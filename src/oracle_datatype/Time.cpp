//
// Created by jmkim on 9/15/17.
//

#include "Time.hpp"

oracle_data_exporter::oracle_datatype::Time::Time (const uint8_t column_data[], const size_t &column_data_size)
    : Time (std::vector<uint8_t> (column_data, column_data + column_data_size))
{}

oracle_data_exporter::oracle_datatype::Time::Time (const std::vector<uint8_t> &column_data)
    : Datetime (column_data, "%I:%M:%S.%9N %p")
{}

oracle_data_exporter::oracle_datatype::Time::Time (const uint8_t column_data[], const size_t &column_data_size, const std::string &format)
    : Time (std::vector<uint8_t> (column_data, column_data + column_data_size), format)
{}

oracle_data_exporter::oracle_datatype::Time::Time (const std::vector<uint8_t> &column_data, const std::string &format)
    : Datetime (column_data, format)
{}

oracle_data_exporter::oracle_datatype::Time::Time
    (const Time &oracle_data)
    : Datetime (oracle_data)
{}

oracle_data_exporter::oracle_datatype::Time &
oracle_data_exporter::oracle_datatype::Time::operator=
    (const Time &rhs)
{ static_cast<Datetime &>(*this) = rhs; }

std::string oracle_data_exporter::oracle_datatype::Time::toString ()
{
  if (column_data_.at (0) != 178)
    { throw std::string ("Error: Not a TIME data (type byte mismatch)"); }

  OracleTime time;

  time.setHours (column_data_.at (2));
  time.setMinutes (column_data_.at (3));
  time.setSeconds (column_data_.at (4));
  time.setFractions ({column_data_.at (5), column_data_.at (6), column_data_.at (7), column_data_.at (8)});

  time.setFormat (getFormat ());

  return time.toString ();
}
