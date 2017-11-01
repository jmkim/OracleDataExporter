//
// Created by jmkim on 9/15/17.
//

#ifndef ORACLEDATAEXPORTER_DATETIME_HPP
#define ORACLEDATAEXPORTER_DATETIME_HPP

#include <array>
#include <ctime>
#include "OracleData.hpp"

namespace oracle_data_exporter::oracle_datatype
{

class Datetime : public OracleData {
 public:
  Datetime (const uint8_t column_data[], const size_t &column_data_size);
  Datetime (const uint8_t column_data[], const size_t &column_data_size, const std::string &format);

  explicit Datetime (const std::vector<uint8_t> &column_data);
  Datetime (const std::vector<uint8_t> &column_data, const std::string &format);

  Datetime (const Datetime &oracle_data);

  Datetime &operator= (const Datetime &rhs);

  void setFormat (const std::string &format);
  std::string getFormat ();

 protected:
  class OracleTime : public IStringable {
   public:
    OracleTime();

    void setYear (const uint8_t &ora_century, const uint8_t &ora_year);
    void setMonth (const uint8_t &ora_mon);
    void setDay (const uint8_t &ora_mday);
    void setHours (const uint8_t &ora_hour);
    void setMinutes (const uint8_t &ora_min);
    void setSeconds (const uint8_t &ora_sec);
    void setFractions (const std::array<uint8_t, 4> &ora_fractions);
    void setTimezone (const uint8_t &ora_tz_hour, const uint8_t &ora_tz_min);
    void setFormat (const std::string &format);

    std::string toString () override;

   private:
    std::tm tm_;                /*< Seconds, Minutes, Hours, Day, Month, Year */
    unsigned int tm_fractions_; /*< Fractions */
    int tz_hour_;               /*< Timezone Hour     [-12 - 12] */
    int tz_min_;                /*< Timezone Minutes  [0 - 59] */
    std::string format_;        /*< Time String Format */

    static void
    formatUnofficialDatetimeString (std::string &format, const std::string &format_key, const std::string &value);
  };

 private:
  std::string format_;
};

}

#endif //ORACLEDATAEXPORTER_DATETIME_HPP
