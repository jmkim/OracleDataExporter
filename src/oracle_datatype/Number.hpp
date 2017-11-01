//
// Created by jmkim on 9/15/17.
//

#ifndef ORACLEDATAEXPORTER_NUMBER_HPP
#define ORACLEDATAEXPORTER_NUMBER_HPP

#include "OracleData.hpp"

namespace oracle_data_exporter::oracle_datatype
{

class Number : public OracleData {
 public:
  Number (const uint8_t column_data[], const size_t &column_data_size);
  explicit Number (const std::vector<uint8_t> &column_data);
  Number (const Number &oracle_data);

  Number &operator= (const Number &rhs);

  std::string toString () override;
};

}

#endif //ORACLEDATAEXPORTER_NUMBER_HPP
