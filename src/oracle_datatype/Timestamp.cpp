//
// Created by jmkim on 9/15/17.
//

#include "Timestamp.hpp"

oracle_data_exporter::oracle_datatype::Timestamp::Timestamp (const uint8_t column_data[], const size_t &column_data_size)
    : Timestamp (std::vector<uint8_t> (column_data, column_data + column_data_size))
{}

oracle_data_exporter::oracle_datatype::Timestamp::Timestamp (const std::vector<uint8_t> &column_data)
    : Datetime (column_data, "%d-%b-%Y %I.%M.%S.%9N %p")
{}

oracle_data_exporter::oracle_datatype::Timestamp::Timestamp (const uint8_t column_data[], const size_t &column_data_size, const std::string &format)
    : Timestamp (std::vector<uint8_t> (column_data, column_data + column_data_size), format)
{}

oracle_data_exporter::oracle_datatype::Timestamp::Timestamp (const std::vector<uint8_t> &column_data, const std::string &format)
    : Datetime (column_data, format)
{}

oracle_data_exporter::oracle_datatype::Timestamp::Timestamp
    (const Timestamp &oracle_data)
    : Datetime (oracle_data)
{}

oracle_data_exporter::oracle_datatype::Timestamp &
oracle_data_exporter::oracle_datatype::Timestamp::operator=
    (const Timestamp &rhs)
{ static_cast<Datetime &>(*this) = rhs; }

std::string oracle_data_exporter::oracle_datatype::Timestamp::toString ()
{
  if (column_data_.at (0) != 180)
    { throw std::string ("Error: Not a TIMESTAMP data (type byte mismatch)"); }

  OracleTime time;

  time.setYear (column_data_.at (2), column_data_.at (3));
  time.setMonth (column_data_.at (4));
  time.setDay (column_data_.at (5));
  time.setHours (column_data_.at (6));
  time.setMinutes (column_data_.at (7));
  time.setSeconds (column_data_.at (8));
  time.setFractions ({column_data_.at (9), column_data_.at (10), column_data_.at (11), column_data_.at (12)});

  time.setFormat (getFormat ());

  return time.toString ();
}
