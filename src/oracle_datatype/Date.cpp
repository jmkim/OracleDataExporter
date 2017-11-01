//
// Created by jmkim on 9/15/17.
//

#include "Date.hpp"

oracle_data_exporter::oracle_datatype::Date::Date (const uint8_t column_data[], const size_t &column_data_size)
    : Date (std::vector<uint8_t> (column_data, column_data + column_data_size))
{}

oracle_data_exporter::oracle_datatype::Date::Date (const std::vector<uint8_t> &column_data)
    : Datetime (column_data, "%d-%b-%Y %H:%M:%S")
{}

oracle_data_exporter::oracle_datatype::Date::Date (const uint8_t column_data[], const size_t &column_data_size, const std::string &format)
    : Date (std::vector<uint8_t> (column_data, column_data + column_data_size), format)
{}

oracle_data_exporter::oracle_datatype::Date::Date (const std::vector<uint8_t> &column_data, const std::string &format)
    : Datetime (column_data, format)
{}

oracle_data_exporter::oracle_datatype::Date::Date
    (const Date &oracle_data)
    : Datetime (oracle_data)
{}

oracle_data_exporter::oracle_datatype::Date &
oracle_data_exporter::oracle_datatype::Date::operator=
    (const Date &rhs)
{ static_cast<Datetime &>(*this) = rhs; }

std::string oracle_data_exporter::oracle_datatype::Date::toString ()
{
  if (column_data_.at (0) != 12)
    { throw std::string ("Error: Not a DATE data (type byte mismatch)"); }

  OracleTime time;

  time.setYear (column_data_.at (2), column_data_.at (3));
  time.setMonth (column_data_.at (4));
  time.setDay (column_data_.at (5));
  time.setHours (column_data_.at (6));
  time.setMinutes (column_data_.at (7));
  time.setSeconds (column_data_.at (8));

  time.setFormat (getFormat ());

  return time.toString ();
}
