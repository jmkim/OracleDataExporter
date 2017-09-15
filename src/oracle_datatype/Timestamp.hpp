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
  explicit Timestamp (const uint8_t column_data[], const size_t &column_data_size);
  explicit Timestamp (const std::vector<uint8_t> &column_data);
  explicit Timestamp (const uint8_t column_data[], const size_t &column_data_size, const std::string &format);
  explicit Timestamp (const std::vector<uint8_t> &column_data, const std::string &format);
  std::string to_string () override;
  size_t write (std::ostream &os) override;
};

}

#endif //ORACLEDATAEXPORTER_TIMESTAMP_HPP
