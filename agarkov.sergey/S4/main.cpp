#include <iostream>
#include <fstream>
#include <string>
#include <list.hpp>
#include "avltree.hpp"
#include "commandsdict.hpp"
#include "inputdict.hpp"

int main(int argc, char* argv[])
{
  if (argc != 2)
  {
    std::cout << "Incorrect arg\n";
    return 1;
  }
  std::ifstream input(argv[1]);
  if (!input.is_open())
  {
    std::cout << "Error file\n";
    return 1;
  }

  using dict_t = agarkov::AVLTree< size_t, std::string >;
  agarkov::AVLTree< std::string, dict_t > dict_of_dict;
  agarkov::inputDict(input, dict_of_dict);
  agarkov::Commands dict_wiht_cmd;
  dict_wiht_cmd.runCommand(std::cin, std::cout, dict_of_dict);
}

