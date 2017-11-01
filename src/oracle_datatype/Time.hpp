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
  Time (const uint8_t column_data[], const size_t &column_data_size);
  Time (const uint8_t column_data[], const size_t &column_data_size, const std::string &format);

  explicit Time (const std::vector<uint8_t> &column_data);
  Time (const std::vector<uint8_t> &column_data, const std::string &format);

  Time (const Time &oracle_data);

  Time &operator= (const Time &rhs);

  std::string toString () override;
};

}

#endif //ORACLEDATAEXPORTER_TIME_HPP
