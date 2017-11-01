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
  Date (const uint8_t column_data[], const size_t &column_data_size);
  Date (const uint8_t column_data[], const size_t &column_data_size, const std::string &format);

  explicit Date (const std::vector<uint8_t> &column_data);
  Date (const std::vector<uint8_t> &column_data, const std::string &format);

  Date (const Date &oracle_data);

  Date &operator= (const Date &rhs);

  std::string toString () override;
};

}

#endif //ORACLEDATAEXPORTER_DATE_HPP
