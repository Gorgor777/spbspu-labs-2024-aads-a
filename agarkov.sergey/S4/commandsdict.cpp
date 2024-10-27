#include "commandsdict.hpp"
#include "commands.hpp"

agarkov::Commands::Commands()
{
  dict1_.insert("print", printDict);
  dict2_.insert("complement", complementDict);
  dict2_.insert("intersect", intersectDict);
  dict2_.insert("union", unionDict);
}
