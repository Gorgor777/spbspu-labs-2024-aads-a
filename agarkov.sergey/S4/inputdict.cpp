#include "inputdict.hpp"
#include <iostream>
#include <string>
#include "avltree.hpp"

namespace
{
  using dict_t = agarkov::AVLTree< size_t, std::string >;
}

void agarkov::inputDict(std::istream& input, AVLTree< std::string, dict_t >& dict_of_dict)
{
  while (input)
  {
    std::string name = "";
    while (input >> name)
    {
      size_t key;
      std::string value;
      dict_t dict;
      while (input >> key >> value)
      {
        dict.insert(key, value);
      }
      dict_of_dict.insert(name, dict);
      input.clear();
    }
  }
}
