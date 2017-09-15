//
// Created by jmkim on 9/15/17.
//

#ifndef ORACLEDATAEXPORTER_COLUMNINTERPRETER_HPP
#define ORACLEDATAEXPORTER_COLUMNINTERPRETER_HPP

#include <string>
#include <cstdint>
#include <vector>

namespace oracle_data_exporter::util
{

class ColumnInterpreter {
 public:
  std::string
  Interpret (const uint8_t column_data[], const size_t &column_data_size, const std::string &time_format = "");
  std::string Interpret (const std::vector<uint8_t> &column_data, const std::string &time_format = "");
};

}

#endif //ORACLEDATAEXPORTER_COLUMNINTERPRETER_HPP
