//
// Created by jmkim on 9/15/17.
//

#include "Date.hpp"

oracle_data_exporter::oracle_datatype::Date::Date (const uint8_t column_data[], const size_t &column_data_size)
    : Date (std::vector<uint8_t> (column_data, column_data + column_data_size))
{}

oracle_data_exporter::oracle_datatype::Date::Date (const std::vector<uint8_t> &column_data)
    : Date (column_data, "%d-%b-%Y %H:%M:%S")
{}

oracle_data_exporter::oracle_datatype::Date::Date (const uint8_t column_data[], const size_t &column_data_size, const std::string &format)
    : Date (std::vector<uint8_t> (column_data, column_data + column_data_size), format)
{}

oracle_data_exporter::oracle_datatype::Date::Date (const std::vector<uint8_t> &column_data, const std::string &format)
    : Datetime (column_data, format)
{
  if (type != 12)
    { throw std::string ("Error: Not a DATE data (type byte mismatch)"); }

  SetYear (column_data.at (2), column_data.at (3));
  SetMonth (column_data.at (4));
  SetDay (column_data.at (5));
  SetHours (column_data.at (6));
  SetMinutes (column_data.at (7));
  SetSeconds (column_data.at (8));
}

std::string oracle_data_exporter::oracle_datatype::Date::to_string ()
{
  char out[70];
  if (!std::strftime (out, sizeof out, format_.c_str (), &time_))
    { throw ("Error: Invalid DATE data (format error)"); }

  return std::string (out);
}

size_t oracle_data_exporter::oracle_datatype::Date::write (std::ostream &os)
{
  std::string out (to_string ());
  os << out;
  return out.length ();
}