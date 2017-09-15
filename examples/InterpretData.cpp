#include <iostream>
#include <vector>
#include "../src/util/ColumnInterpreter.hpp"

int main ()
{
  std::vector<uint8_t> column_data;

  int buff;

  std::cin >> buff;
  column_data.push_back (static_cast<uint8_t>(buff)); /* type byte */

  std::cin >> buff;
  column_data.push_back (static_cast<uint8_t>(buff)); /* length byte */

  for (int i = 0; i < column_data.at (1); ++i)
    {
      std::cin >> buff;
      column_data.push_back (static_cast<uint8_t>(buff)); /* column data */
    }

  try
    {
      oracle_data_exporter::util::ColumnInterpreter interpreter;
      std::cout << interpreter.Interpret (column_data) << "\n";
    }
  catch (std::string &e)
    { std::cout << e << "\n"; }

  return 0;
}