//
// Created by jmkim on 9/15/17.
//

#include <memory>
#include "ColumnInterpreter.hpp"
#include "../oracle_datatype/OracleDataInterface.hpp"
#include "../oracle_datatype/Date.hpp"
#include "../oracle_datatype/Time.hpp"
#include "../oracle_datatype/TimeWithTimezone.hpp"
#include "../oracle_datatype/Timestamp.hpp"
#include "../oracle_datatype/TimestampWithTimezone.hpp"
#include "../oracle_datatype/Number.hpp"
#include "../oracle_datatype/Char.hpp"

std::string
oracle_data_exporter::util::ColumnInterpreter::Interpret (const uint8_t column_data[], const size_t &column_data_size, const std::string &time_format)
{ return Interpret (std::vector<uint8_t> (column_data, column_data + column_data_size), time_format); }

std::string
oracle_data_exporter::util::ColumnInterpreter::Interpret (const std::vector<uint8_t> &column_data, const std::string &time_format)
{
  std::shared_ptr<oracle_datatype::OracleDataInterface> data;
  switch (column_data.at (0))
    {
      case 1:
      case 96:
        { data = std::make_shared<oracle_datatype::Char> (column_data); }
      break;
      case 2:
        { data = std::make_shared<oracle_datatype::Number> (column_data); }
      break;
      case 12:
        { data = std::make_shared<oracle_datatype::Date> (column_data); }
      break;
      case 178:
        { data = std::make_shared<oracle_datatype::Time> (column_data); }
      break;
      case 179:
        { data = std::make_shared<oracle_datatype::TimeWithTimezone> (column_data); }
      break;
      case 180:
        { data = std::make_shared<oracle_datatype::Timestamp> (column_data); }
      break;
      case 181:
        { data = std::make_shared<oracle_datatype::TimestampWithTimezone> (column_data); }
      break;
      default:
        {
          throw (std::string (
              "Error: Cannot interpret the column data (unknown type byte - "
              + std::to_string (column_data.at (0))
              + ")"));
        }
    }

  return data->to_string ();
}
