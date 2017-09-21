//
// Created by jmkim on 9/21/17.
//

#ifndef ORACLEDATAEXPORTER_CHAR_HPP
#define ORACLEDATAEXPORTER_CHAR_HPP

#include "OracleDataInterface.hpp"

namespace oracle_data_exporter::oracle_datatype
{

class Char : public OracleDataInterface {
 public:
  explicit Char (const uint8_t column_data[], const size_t &column_data_size);
  explicit Char (const std::vector<uint8_t> &column_data);
  std::string to_string () override;
  size_t write (std::ostream &os) override;

 private:
  std::string characters_;
};

}

#endif //ORACLEDATAEXPORTER_CHAR_HPP
