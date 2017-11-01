//
// Created by jmkim on 9/15/17.
//

#ifndef ORACLEDATAEXPORTER_TIMESTAMPWITHTIMEZONE_HPP
#define ORACLEDATAEXPORTER_TIMESTAMPWITHTIMEZONE_HPP

#include "Datetime.hpp"

namespace oracle_data_exporter::oracle_datatype
{

class TimestampWithTimezone : public Datetime {
 public:
  TimestampWithTimezone (const uint8_t column_data[], const size_t &column_data_size);
  TimestampWithTimezone (const uint8_t column_data[], const size_t &column_data_size, const std::string &format);

  explicit TimestampWithTimezone (const std::vector<uint8_t> &column_data);
  TimestampWithTimezone (const std::vector<uint8_t> &column_data, const std::string &format);

  TimestampWithTimezone (const TimestampWithTimezone &oracle_data);

  TimestampWithTimezone &operator= (const TimestampWithTimezone &rhs);

  std::string toString () override;
};

}

#endif //ORACLEDATAEXPORTER_TIMESTAMPWITHTIMEZONE_HPP
