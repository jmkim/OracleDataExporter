//
// Created by jmkim on 9/15/17.
//

#include "TimestampWithTimezone.hpp"

oracle_data_exporter::oracle_datatype::TimestampWithTimezone::TimestampWithTimezone (const uint8_t column_data[], const size_t &column_data_size)
    : TimestampWithTimezone (std::vector<uint8_t> (column_data, column_data + column_data_size))
{}

oracle_data_exporter::oracle_datatype::TimestampWithTimezone::TimestampWithTimezone (const std::vector<uint8_t> &column_data)
    : TimestampWithTimezone (column_data, "%d-%b-%Y %I.%M.%S.%9N %p %zH:%zM")
{}

oracle_data_exporter::oracle_datatype::TimestampWithTimezone::TimestampWithTimezone (const uint8_t column_data[], const size_t &column_data_size, const std::string &format)
    : TimestampWithTimezone (std::vector<uint8_t> (column_data, column_data + column_data_size), format)
{}

oracle_data_exporter::oracle_datatype::TimestampWithTimezone::TimestampWithTimezone (const std::vector<uint8_t> &column_data, const std::string &format)
    : Datetime (column_data, format)
{
  if (type != 181)
    { throw std::string ("Error: Not a TIMESTAMP WITH TIME ZONE data (type byte mismatch)"); }

  SetYear (column_data.at (2), column_data.at (3));
  SetMonth (column_data.at (4));
  SetDay (column_data.at (5));
  SetHours (column_data.at (6));
  SetMinutes (column_data.at (7));
  SetSeconds (column_data.at (8));
  SetFractions (
      FractionsConverter ({column_data.at (9), column_data.at (10), column_data.at (11), column_data.at (12)}));
  SetTimezone (column_data.at (13), column_data.at (14));
}

std::string oracle_data_exporter::oracle_datatype::TimestampWithTimezone::to_string ()
{
  std::string format (format_);
  format = Formatter (format, "%9N", std::to_string (fractions_));
  format = Formatter (format, "%zH", std::to_string (tz_hour_));
  format = Formatter (format, "%zM", std::to_string (tz_min_));

  char out[70];
  if (!std::strftime (out, sizeof out, format.c_str (), &time_))
    { throw ("Error: Invalid TIMESTAMP WITH TIME ZONE data (format error)"); }

  return std::string (out);
}

size_t oracle_data_exporter::oracle_datatype::TimestampWithTimezone::write (std::ostream &os)
{
  std::string out (to_string ());
  os << out;
  return out.length ();
}
