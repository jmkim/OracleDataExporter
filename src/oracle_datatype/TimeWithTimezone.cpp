//
// Created by jmkim on 9/15/17.
//

#include "TimeWithTimezone.hpp"

oracle_data_exporter::oracle_datatype::TimeWithTimezone::TimeWithTimezone (const uint8_t column_data[], const size_t &column_data_size)
    : TimeWithTimezone (std::vector<uint8_t> (column_data, column_data + column_data_size))
{}

oracle_data_exporter::oracle_datatype::TimeWithTimezone::TimeWithTimezone (const std::vector<uint8_t> &column_data)
    : Datetime (column_data, "%I.%M.%S %p %zH:%zM")
{}

oracle_data_exporter::oracle_datatype::TimeWithTimezone::TimeWithTimezone (const uint8_t column_data[], const size_t &column_data_size, const std::string &format)
    : TimeWithTimezone (std::vector<uint8_t> (column_data, column_data + column_data_size), format)
{}

oracle_data_exporter::oracle_datatype::TimeWithTimezone::TimeWithTimezone (const std::vector<uint8_t> &column_data, const std::string &format)
    : Datetime (column_data, format)
{}

oracle_data_exporter::oracle_datatype::TimeWithTimezone::TimeWithTimezone
    (const TimeWithTimezone &oracle_data)
    : Datetime (oracle_data)
{}

oracle_data_exporter::oracle_datatype::TimeWithTimezone &
oracle_data_exporter::oracle_datatype::TimeWithTimezone::operator=
    (const TimeWithTimezone &rhs)
{ static_cast<Datetime &>(*this) = rhs; }

std::string oracle_data_exporter::oracle_datatype::TimeWithTimezone::toString ()
{
  if (column_data_.at (0) != 179)
    { throw std::string ("Error: Not a TIME WITH TIME ZONE data (type byte mismatch)"); }

  OracleTime time;

  time.setHours (column_data_.at (2));
  time.setMinutes (column_data_.at (3));
  time.setSeconds (column_data_.at (4));
  time.setFractions ({column_data_.at (5), column_data_.at (6), column_data_.at (7), column_data_.at (8)});
  time.setTimezone (column_data_.at (9), column_data_.at (10));

  time.setFormat (getFormat ());

  return time.toString ();
}
