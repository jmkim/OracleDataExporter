//
// Created by jmkim on 10/12/17.
//

#ifndef ORACLEDATAEXPORTER_ISTRINGABLE_HPP
#define ORACLEDATAEXPORTER_ISTRINGABLE_HPP

#include <string>

namespace oracle_data_exporter
{

class IStringable {
 public:
  virtual std::string toString() = 0;
};

}

#endif //ORACLEDATAEXPORTER_ISTRINGABLE_HPP
