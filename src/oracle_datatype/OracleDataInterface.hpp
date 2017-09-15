//
// Created by jmkim on 9/15/17.
//

#ifndef ORACLEDATAEXPORTER_ORACLEDATAINTERFACE_HPP
#define ORACLEDATAEXPORTER_ORACLEDATAINTERFACE_HPP

#include <cstdint>
#include <string>
#include <vector>
#include <istream>

namespace oracle_data_exporter::oracle_datatype
{

struct OracleDataInterface {
  explicit OracleDataInterface (const uint8_t column_data[], const size_t &column_data_size)
      : OracleDataInterface (std::vector<uint8_t> (column_data, column_data + column_data_size))
  {}

  explicit OracleDataInterface (const std::vector<uint8_t> &column_data)
      : type (column_data.at (0)), length (column_data.at (1))
  {}

  virtual std::string to_string () = 0;
  virtual size_t write (std::ostream &) = 0;

 protected:
  const uint8_t type;
  const uint8_t length;
};

}

#endif //ORACLEDATAEXPORTER_ORACLEDATAINTERFACE_HPP
