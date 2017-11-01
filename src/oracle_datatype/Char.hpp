//
// Created by jmkim on 9/21/17.
//

#ifndef ORACLEDATAEXPORTER_CHAR_HPP
#define ORACLEDATAEXPORTER_CHAR_HPP

#include "OracleData.hpp"

namespace oracle_data_exporter::oracle_datatype
{

class Char : public OracleData {
 public:
  Char (const uint8_t column_data[], const size_t &column_data_size);
  explicit Char (const std::vector<uint8_t> &column_data);
  Char (const Char &oracle_data);

  Char &operator= (const Char &rhs);

  std::string toString () override;
};

}

#endif //ORACLEDATAEXPORTER_CHAR_HPP
