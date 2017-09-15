//
// Created by jmkim on 9/15/17.
//

#include "TimeWithTimezone.hpp"

oracle_data_exporter::oracle_datatype::TimeWithTimezone::TimeWithTimezone (const uint8_t column_data[], const size_t &column_data_size)
    : TimeWithTimezone (std::vector<uint8_t> (column_data, column_data + column_data_size))
{}

oracle_data_exporter::oracle_datatype::TimeWithTimezone::TimeWithTimezone (const std::vector<uint8_t> &column_data)
    : TimeWithTimezone (column_data, "%I.%M.%S %p %zH:%zM")
{}

oracle_data_exporter::oracle_datatype::TimeWithTimezone::TimeWithTimezone (const uint8_t column_data[], const size_t &column_data_size, const std::string &format)
    : TimeWithTimezone (std::vector<uint8_t> (column_data, column_data + column_data_size), format)
{}

oracle_data_exporter::oracle_datatype::TimeWithTimezone::TimeWithTimezone (const std::vector<uint8_t> &column_data, const std::string &format)
    : Datetime (column_data, format)
{
  if (type != 179)
    { throw std::string ("Error: Not a TIME WITH TIME ZONE data (type byte mismatch)"); }

  SetHours (column_data.at (2));
  SetMinutes (column_data.at (3));
  SetSeconds (column_data.at (4));
  SetFractions (
      FractionsConverter ({column_data.at (5), column_data.at (6), column_data.at (7), column_data.at (8)}));
  SetTimezone (column_data.at (9), column_data.at (10));
}

std::string oracle_data_exporter::oracle_datatype::TimeWithTimezone::to_string ()
{
  std::string format (format_);
  format = Formatter (format, "%9N", std::to_string (fractions_));
  format = Formatter (format, "%zH", std::to_string (tz_hour_));
  format = Formatter (format, "%zM", std::to_string (tz_min_));

  char out[70];
  if (!std::strftime (out, sizeof out, format.c_str (), &time_))
    { throw ("Error: Invalid TIME WITH TIME ZONE data (format error)"); }

  return std::string (out);
}

size_t oracle_data_exporter::oracle_datatype::TimeWithTimezone::write (std::ostream &os)
{
  std::string out (to_string ());
  os << out;
  return out.length ();
}