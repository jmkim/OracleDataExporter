//
// Created by jmkim on 9/21/17.
//

#include "Char.hpp"

oracle_data_exporter::oracle_datatype::Char::Char (const uint8_t column_data[], const size_t &column_data_size)
    : Char (std::vector<uint8_t> (column_data, column_data + column_data_size))
{}

oracle_data_exporter::oracle_datatype::Char::Char (const std::vector<uint8_t> &column_data)
    : OracleDataInterface (column_data)
{
  if (type != 1 && type != 96)
    { throw std::string ("Error: Not a CHAR (NCHAR, VARCHAR2, NVARCHAR2) data (type byte mismatch)"); }

  for (size_t i = 2; i < length + 2; ++i)
    { characters_.push_back (column_data.at (i)); }
}

std::string oracle_data_exporter::oracle_datatype::Char::to_string ()
{
  return characters_;
}

size_t oracle_data_exporter::oracle_datatype::Char::write (std::ostream &os)
{
  os << characters_;
  return characters_.length ();
}