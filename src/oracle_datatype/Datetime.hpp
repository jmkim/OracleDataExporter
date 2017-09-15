//
// Created by jmkim on 9/15/17.
//

#ifndef ORACLEDATAEXPORTER_DATETIME_HPP
#define ORACLEDATAEXPORTER_DATETIME_HPP

#include <array>
#include <ctime>
#include "OracleDataInterface.hpp"

namespace oracle_data_exporter::oracle_datatype
{

class Datetime : public OracleDataInterface {
 public:
  explicit Datetime (const uint8_t column_data[], const size_t &column_data_size)
      : Datetime (std::vector<uint8_t> (column_data, column_data + column_data_size))
  {}

  explicit Datetime (const std::vector<uint8_t> &column_data)
      : Datetime (column_data, "")
  {}

  explicit Datetime (const uint8_t column_data[], const size_t &column_data_size, const std::string &format)
      : Datetime (std::vector<uint8_t> (column_data, column_data + column_data_size), format)
  {}

  explicit Datetime (const std::vector<uint8_t> &column_data, const std::string &format)
      : OracleDataInterface (column_data), format_ (format),
        time_ (), tz_hour_ (0), tz_min_ (0), fractions_ (0)
  {}

 protected:
  const std::string format_;
  std::tm time_;
  int8_t tz_hour_;
  uint8_t tz_min_;
  unsigned int fractions_;

  std::string Formatter (const std::string &format, const std::string &format_key, const std::string &value)
  {
    std::string out (format);

    size_t pos;
    while ((pos = out.find (format_key)) != std::string::npos)
      { out.replace (out.find (format_key), format_key.length (), value); }

    return out;
  }

  unsigned int FractionsConverter (const std::array<uint8_t, 4> fraction_of_seconds)
  {
    unsigned int out = fraction_of_seconds.at (0) * 0x1000000u
                       + fraction_of_seconds.at (1) * 0x10000u
                       + fraction_of_seconds.at (2) * 0x100u
                       + fraction_of_seconds.at (3) * 0x1u;

    return out;
  }

  void SetYear (const uint8_t &ora_century, const uint8_t &ora_year)
  { time_.tm_year = ((ora_century - 100) * 100) + (ora_year - 2000); }

  void SetMonth (const uint8_t &ora_mon)
  { time_.tm_mon = ora_mon - 1; }

  void SetDay (const uint8_t &ora_mday)
  { time_.tm_mday = ora_mday; }

  void SetHours (const uint8_t &ora_hour)
  { time_.tm_hour = ora_hour - 1 + tz_hour_; }

  void SetMinutes (const uint8_t &ora_min)
  { time_.tm_min = ora_min - 1 + tz_min_; }

  void SetSeconds (const uint8_t &ora_sec)
  { time_.tm_sec = ora_sec - 1; }

  void SetFractions (const unsigned int &fractions)
  { fractions_ = fractions; }

  void SetTimezone (const uint8_t &ora_tz_hour, const uint8_t &ora_tz_min)
  {
    if (tz_hour_ != 0)
      { time_.tm_hour -= tz_hour_; }

    tz_hour_ = ora_tz_hour - static_cast<int8_t> (20);
    time_.tm_hour += tz_hour_;

    if (tz_min_ != 0)
      { time_.tm_min -= tz_min_; }

    tz_min_ = ora_tz_min - static_cast<int8_t> (60);
    time_.tm_min += tz_min_;
  }
};

}

#endif //ORACLEDATAEXPORTER_DATETIME_HPP
