//
// Created by jmkim on 9/15/17.
//

#ifndef ORACLEDATAEXPORTER_ORACLELOBDATAINTERFACE_HPP
#define ORACLEDATAEXPORTER_ORACLELOBDATAINTERFACE_HPP

#include "OracleDataInterface.hpp"

namespace oracle_data_exporter::oracle_datatype
{

struct OracleLOBDataInterface : public OracleDataInterface {
  explicit OracleLOBDataInterface (const uint8_t column_data[], const size_t &column_data_size)
      : OracleDataInterface (column_data, column_data_size)
  {}
  explicit OracleLOBDataInterface (const std::vector<uint8_t> &column_data)
      : OracleDataInterface (column_data)
  {}
};

}

#endif //ORACLEDATAEXPORTER_ORACLELOBDATAINTERFACE_HPP
