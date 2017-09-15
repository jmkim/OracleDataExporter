//
// Created by jmkim on 9/15/17.
//

#ifndef ORACLEDATAEXPORTER_TIME_HPP
#define ORACLEDATAEXPORTER_TIME_HPP

#include "Datetime.hpp"

namespace oracle_data_exporter::oracle_datatype
{

class Time : public Datetime {
 public:
  explicit Time (const uint8_t column_data[], const size_t &column_data_size);
  explicit Time (const std::vector<uint8_t> &column_data);
  explicit Time (const uint8_t column_data[], const size_t &column_data_size, const std::string &format);
  explicit Time (const std::vector<uint8_t> &column_data, const std::string &format);
  std::string to_string () override;
  size_t write (std::ostream &os) override;
};

}

#endif //ORACLEDATAEXPORTER_TIME_HPP
