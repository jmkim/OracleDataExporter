//
// Created by jmkim on 10/12/17.
//

#ifndef ORACLEDATAEXPORTER_ORACLEDATA_HPP
#define ORACLEDATAEXPORTER_ORACLEDATA_HPP

#include <vector>
#include "../IStringable.hpp"

namespace oracle_data_exporter::oracle_datatype
{

/**
 * An abstract class for Oracle Built-in Data Types (NUMBER, DATE, TIME, ...).
 */
class OracleData : public IStringable {
 public:
  OracleData () = default;
  OracleData (const uint8_t column_data[], const size_t &column_data_size);
  explicit OracleData (const std::vector<uint8_t> &column_data);
  /**
   * Copy constructor
   */
  OracleData (const OracleData &oracle_data);

  OracleData &operator= (const OracleData &rhs);
  OracleData &operator= (const std::vector<uint8_t> &rhs);

 protected:
  std::vector<uint8_t> column_data_;
};

}

#endif //ORACLEDATAEXPORTER_ORACLEDATA_HPP
