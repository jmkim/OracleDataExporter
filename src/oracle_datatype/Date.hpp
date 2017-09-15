//
// Created by jmkim on 9/15/17.
//

#ifndef ORACLEDATAEXPORTER_DATE_HPP
#define ORACLEDATAEXPORTER_DATE_HPP

#include "Datetime.hpp"

namespace oracle_data_exporter::oracle_datatype
{

class Date : public Datetime {
 public:
  explicit Date (const uint8_t column_data[], const size_t &column_data_size);
  explicit Date (const std::vector<uint8_t> &column_data);
  explicit Date (const uint8_t column_data[], const size_t &column_data_size, const std::string &format);
  explicit Date (const std::vector<uint8_t> &column_data, const std::string &format);
  std::string to_string () override;
  size_t write (std::ostream &os) override;
};

}

#endif //ORACLEDATAEXPORTER_DATE_HPP
