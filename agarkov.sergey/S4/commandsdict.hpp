#ifndef COMMANDSDICT_HPP
#define COMMANDSDICT_HPP

#include <iostream>
#include "avltree.hpp"
#include "commands.hpp"

namespace agarkov
{
  class Commands
  {
  public:
    using dict_t = agarkov::AVLTree< size_t, std::string >;
    using main_dict = agarkov::AVLTree< std::string, dict_t >;
    Commands();
    void runCommand(std::istream& in, std::ostream& out, main_dict&);
  private:
    using com1 = void(*)(std::string, main_dict&, std::ostream&);
    using com2 = void(*)(std::string, std::string, std::string, main_dict&);

    AVLTree< std::string, com1 > dict1_;
    AVLTree< std::string, com2 > dict2_;
  };
}

#endif
