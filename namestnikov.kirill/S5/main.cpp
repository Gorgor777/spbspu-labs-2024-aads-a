#include <iostream>
#include <string>
#include <functional>
#include <utility>
#include <map>
#include "tree.hpp"

namespace namestnikov
{
  class SumFunc
  {
  public:
    SumFunc();
    void operator()(const std::pair< const int, std::string > & data);
    int getResult() const;
    std::string getLine() const;
  private:
    int result_;
    std::string line_;
  };
}

namestnikov::SumFunc::SumFunc():
  result_(0),
  line_("")
{}

int namestnikov::SumFunc::getResult() const
{
  return result_;
}

std::string namestnikov::SumFunc::getLine() const
{
  return line_;
}

void namestnikov::SumFunc::operator()(const std::pair< const int, std::string > & data)
{
  result_ += data.first;
  line_ = line_ + data.second + " ";
}

void ascending(int & result, std::string & line, const Tree< int, std::string > & map)
{
  namestnikov::SumFunc sumAmount;
  sumAmount = map.traverse_lnr(sumAmount);
  result = sumAmount.getResult();
  line = sumAmount.getLine();
}

int main()
{
  std::map< int, std::string > myMap;
  while (!std::cin.eof())
  {
    std::cin.clear();
    int keyNumber = 0;
    std::string value = "";
    while (std::cin >> keyNumber >> value)
    {
      myMap.insert(std::make_pair(keyNumber, value));
    }
  }
  std::cout << "|||" << myMap[10];
}
