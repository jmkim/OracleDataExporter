//
// Created by jmkim on 10/12/17.
//

#include "Datetime.hpp"

oracle_data_exporter::oracle_datatype::Datetime::Datetime
    (const uint8_t column_data[], const size_t &column_data_size)
    : OracleData (std::vector<uint8_t> (column_data, column_data + column_data_size))
{}

oracle_data_exporter::oracle_datatype::Datetime::Datetime
    (const uint8_t column_data[], const size_t &column_data_size, const std::string &format)
    : OracleData (std::vector<uint8_t> (column_data, column_data + column_data_size)),
      format_ (format)
{}

oracle_data_exporter::oracle_datatype::Datetime::Datetime
    (const std::vector<uint8_t> &column_data)
    : OracleData (column_data)
{}

oracle_data_exporter::oracle_datatype::Datetime::Datetime
    (const std::vector<uint8_t> &column_data, const std::string &format)
    : OracleData (column_data),
      format_ (format)
{}

oracle_data_exporter::oracle_datatype::Datetime::Datetime
    (const Datetime &oracle_data)
    : OracleData (oracle_data), format_ (oracle_data.format_)
{}

oracle_data_exporter::oracle_datatype::Datetime &
oracle_data_exporter::oracle_datatype::Datetime::operator=
    (const Datetime &rhs)
{
  static_cast<OracleData &>(*this) = rhs;
  format_ = rhs.format_;
}

void
oracle_data_exporter::oracle_datatype::Datetime::setFormat
    (const std::string &format)
{ format_ = format; }

std::string
oracle_data_exporter::oracle_datatype::Datetime::getFormat
    ()
{ return format_; }

oracle_data_exporter::oracle_datatype::Datetime::OracleTime::OracleTime ()
    : tm_ (), tm_fractions_ (0), tz_hour_ (0), tz_min_ (0)
{}

void
oracle_data_exporter::oracle_datatype::Datetime::OracleTime::setYear
    (const uint8_t &ora_century, const uint8_t &ora_year)
{ tm_.tm_year = ((ora_century - 100) * 100) + (ora_year - 2000); }

void
oracle_data_exporter::oracle_datatype::Datetime::OracleTime::setMonth
    (const uint8_t &ora_mon)
{ tm_.tm_mon = ora_mon - 1; }

void
oracle_data_exporter::oracle_datatype::Datetime::OracleTime::setDay
    (const uint8_t &ora_mday)
{ tm_.tm_mday = ora_mday; }

void
oracle_data_exporter::oracle_datatype::Datetime::OracleTime::setHours
    (const uint8_t &ora_hour)
{ tm_.tm_hour = ora_hour - 1 + tz_hour_; }

void
oracle_data_exporter::oracle_datatype::Datetime::OracleTime::setMinutes
    (const uint8_t &ora_min)
{ tm_.tm_min = ora_min - 1 + tz_min_; }

void
oracle_data_exporter::oracle_datatype::Datetime::OracleTime::setSeconds
    (const uint8_t &ora_sec)
{ tm_.tm_sec = ora_sec - 1; }

void
oracle_data_exporter::oracle_datatype::Datetime::OracleTime::setFractions
    (const std::array<uint8_t, 4> &ora_fractions)
{
  tm_fractions_ =
      ora_fractions.at (0) << 24 + ora_fractions.at (1) << 16 + ora_fractions.at (2) << 8 + ora_fractions.at (3);
}

void
oracle_data_exporter::oracle_datatype::Datetime::OracleTime::setTimezone
    (const uint8_t &ora_tz_hour, const uint8_t &ora_tz_min)
{
  if (tz_hour_ != 0)
    { tm_.tm_hour -= tz_hour_; }

  tz_hour_ = ora_tz_hour - static_cast<int8_t> (20);
  tm_.tm_hour += tz_hour_;

  if (tz_min_ != 0)
    { tm_.tm_min -= tz_min_; }

  tz_min_ = ora_tz_min - static_cast<int8_t> (60);
  tm_.tm_min += tz_min_;
}

void
oracle_data_exporter::oracle_datatype::Datetime::OracleTime::setFormat
    (const std::string &format)
{ format_ = format; }

std::string
oracle_data_exporter::oracle_datatype::Datetime::OracleTime::toString ()
{
  std::string format (format_);
  formatUnofficialDatetimeString (format, "%9N", std::to_string (tm_fractions_));
  formatUnofficialDatetimeString (format, "%zH", std::to_string (tz_hour_));
  formatUnofficialDatetimeString (format, "%zM", std::to_string (tz_min_));

  char out[256]; /*< TODO: 255 characters limited */
  if (!std::strftime (out, sizeof out, format.c_str (), &tm_))
    { throw ("Error: Invalid TIME data (format error)"); }

  return std::string (out);
}

void
oracle_data_exporter::oracle_datatype::Datetime::OracleTime::formatUnofficialDatetimeString
    (std::string &format, const std::string &format_key, const std::string &value)
{
  size_t pos;
  while ((pos = format.find (format_key)) != std::string::npos)
    { format.replace (format.find (format_key), format_key.length (), value); }
}
