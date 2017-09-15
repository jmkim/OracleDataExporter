//
// Created by jmkim on 9/15/17.
//

#ifndef ORACLEDATAEXPORTER_TIMEWITHTIMEZONE_HPP
#define ORACLEDATAEXPORTER_TIMEWITHTIMEZONE_HPP

#include "Datetime.hpp"

namespace oracle_data_exporter::oracle_datatype
{

class TimeWithTimezone : public Datetime {
 public:
  explicit TimeWithTimezone (const uint8_t column_data[], const size_t &column_data_size);
  explicit TimeWithTimezone (const std::vector<uint8_t> &column_data);
  explicit TimeWithTimezone (const uint8_t column_data[], const size_t &column_data_size, const std::string &format);
  explicit TimeWithTimezone (const std::vector<uint8_t> &column_data, const std::string &format);
  std::string to_string () override;
  size_t write (std::ostream &os) override;
};

}

#endif //ORACLEDATAEXPORTER_TIMEWITHTIMEZONE_HPP
