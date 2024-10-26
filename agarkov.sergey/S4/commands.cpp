#include "commands.hpp"
#include <string>
#include <ostream>
#include <utility>
#include "avltree.hpp"

namespace
{
  using dict_t = agarkov::AVLTree< size_t, std::string >;
  using main_dict = agarkov::AVLTree< std::string, dict_t >;
}

void agarkov::printDict(std::string name, main_dict& dict_of_dict, std::ostream& out)
{
  try
  {
    dict_t dict = dict_of_dict.at(name);
    if (dict.empty())
    {
      out << "<EMPTY>";
      return;
    }
    out << name;
    for (auto i = dict.begin(); i != dict.end(); i++)
    {
      out << " " << i->first << " " << i->second;
    }
  }
  catch (...)
  {
    throw;
  }
}
 
