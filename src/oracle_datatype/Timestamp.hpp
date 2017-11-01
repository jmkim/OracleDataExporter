//
// Created by jmkim on 9/15/17.
//

#ifndef ORACLEDATAEXPORTER_TIMESTAMP_HPP
#define ORACLEDATAEXPORTER_TIMESTAMP_HPP

#include "Datetime.hpp"

namespace oracle_data_exporter::oracle_datatype
{

class Timestamp : public Datetime {
 public:
  Timestamp (const uint8_t column_data[], const size_t &column_data_size);
  Timestamp (const uint8_t column_data[], const size_t &column_data_size, const std::string &format);

  explicit Timestamp (const std::vector<uint8_t> &column_data);
  Timestamp (const std::vector<uint8_t> &column_data, const std::string &format);

  Timestamp (const Timestamp &oracle_data);

  Timestamp &operator= (const Timestamp &rhs);

  std::string toString () override;
};

}

#endif //ORACLEDATAEXPORTER_TIMESTAMP_HPP
