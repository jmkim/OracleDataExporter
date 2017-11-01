//
// Created by jmkim on 9/15/17.
//

#include <iostream>
#include "Number.hpp"

oracle_data_exporter::oracle_datatype::Number::Number (const uint8_t column_data[], const size_t &column_data_size)
    : Number (std::vector<uint8_t> (column_data, column_data + column_data_size))
{}

oracle_data_exporter::oracle_datatype::Number::Number (const std::vector<uint8_t> &column_data)
    : OracleData (column_data)
{}

oracle_data_exporter::oracle_datatype::Number::Number
    (const Number &oracle_data)
    : OracleData (oracle_data)
{}

oracle_data_exporter::oracle_datatype::Number &
oracle_data_exporter::oracle_datatype::Number::operator=
    (const Number &rhs)
{ static_cast<OracleData &>(*this) = rhs; }

std::string oracle_data_exporter::oracle_datatype::Number::toString ()
{
  if (column_data_.at (0) != 2)
    { throw std::string ("Error: Not a NUMBER data (type byte mismatch)"); }

  std::string out;

  uint8_t length = column_data_.at (1);
  uint8_t exponent = column_data_.at (2);
  size_t digits_len = length - 1ul;
  std::vector<uint8_t> digits (column_data_);
  digits.erase (digits.begin (), digits.begin () + 3);

  if (exponent >= 128)
    {
      exponent -= 193;
      for (size_t i = 0; i < digits_len; ++i)
        { --digits.at (i); }
    }
  else
    {
      exponent = static_cast<uint8_t>(62) - exponent;

      for (size_t i = 0; i < digits_len; ++i)
        { digits.at (i) = static_cast<uint8_t>(101) - digits.at (i); }

      if (digits.at (digits_len - 1) != 255)
        { throw std::string ("Error: Corrupt NUMBER data (expected negative suffix not exists)"); }

      --digits_len;
      out += "-";
    }

  if (exponent >= 0)
    {
      size_t i;

      for (i = 0; i <= exponent; ++i)
        { out += std::to_string ((i < digits_len) ? digits.at (i) : 0); }

      if (exponent < digits_len - 1)
        { out += "."; }

      for (; i < digits_len; ++i)
        { out += std::to_string ((i < digits_len) ? digits.at (i) : 0); }
    }
  else
    {
      out += "0.";

      for (ssize_t i = -1; i > exponent; --i)
        { out += "00"; }

      size_t i;
      for (i = 0; i < digits_len - 1; ++i)
        { out += std::to_string (digits.at (i)); }

      out += std::to_string ((digits.at (i) % 10 == 0) ? digits.at (i) / 10 : digits.at (i));
    }

  return out;
}
