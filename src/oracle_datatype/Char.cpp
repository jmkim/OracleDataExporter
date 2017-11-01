//
// Created by jmkim on 9/21/17.
//

#include "Char.hpp"

oracle_data_exporter::oracle_datatype::Char::Char (const uint8_t column_data[], const size_t &column_data_size)
    : Char (std::vector<uint8_t> (column_data, column_data + column_data_size))
{}

oracle_data_exporter::oracle_datatype::Char::Char (const std::vector<uint8_t> &column_data)
    : OracleData (column_data)
{}

oracle_data_exporter::oracle_datatype::Char::Char
    (const Char &oracle_data)
    : OracleData (oracle_data)
{}

oracle_data_exporter::oracle_datatype::Char &
oracle_data_exporter::oracle_datatype::Char::operator=
    (const Char &rhs)
{ static_cast<OracleData &>(*this) = rhs; }

std::string oracle_data_exporter::oracle_datatype::Char::toString ()
{
  if (column_data_.at (0) != 1 && column_data_.at (0) != 96)
    { throw std::string ("Error: Not a CHAR (NCHAR, VARCHAR2, NVARCHAR2) data (type byte mismatch)"); }

  std::string out;

  for (size_t i = 2; i < column_data_.at (1) + 2; ++i)
    { out.push_back (column_data_.at (i)); }

  return out;
}
