//
// Created by jmkim on 9/15/17.
//

#ifndef ORACLEDATAEXPORTER_NUMBER_HPP
#define ORACLEDATAEXPORTER_NUMBER_HPP

#include "OracleDataInterface.hpp"

namespace oracle_data_exporter::oracle_datatype
{

class Number : public OracleDataInterface {
 public:
  explicit Number (const uint8_t column_data[], const size_t &column_data_size);
  explicit Number (const std::vector<uint8_t> &column_data);
  std::string to_string () override;
  size_t write (std::ostream &os) override;

 private:
  std::string number_;
};

}

#endif //ORACLEDATAEXPORTER_NUMBER_HPP
