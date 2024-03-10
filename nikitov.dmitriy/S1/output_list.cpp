#include "output_list.hpp"
#include <fstream>
#include <limits>
#include "list_iterator.hpp"
#include "const_list_iterator.hpp"

void nikitov::outputList(List< std::pair< std::string, List< size_t > > >& pairsList, std::ostream& output)
{
  if (pairsList.empty())
  {
    throw std::invalid_argument("Error: Empty list");
  }

  size_t maxSize = 1;
  for (auto pairsIterator = pairsList.cbegin(); pairsIterator != pairsList.cend(); ++pairsIterator)
  {
    maxSize = std::max(maxSize, pairsIterator->second.size());
    if (pairsIterator != pairsList.cbegin())
    {
      output << ' ';
    }
    output << pairsIterator->first;
  }
  output << '\n';

  bool isOverflow = false;
  List< size_t > sumsList;
  for (size_t i = 0; i != maxSize; ++i)
  {
    size_t sum = 0;
    bool isFirst = true;
    for (auto pairsIterator = pairsList.cbegin(); pairsIterator != pairsList.cend(); ++pairsIterator)
    {
      auto numbersIterator = pairsIterator->second.cbegin();
      if (i < pairsIterator->second.size())
      {
        size_t number = *(numbersIterator.advance(i));
        if (isFirst)
        {
          isFirst = false;
        }
        else
        {
          output << ' ';
        }
        output << number;

        size_t maxNum = std::numeric_limits< size_t >::max();
        if (maxNum - number < sum)
        {
          isOverflow = true;
        }
        else
        {
          sum += number;
        }
      }
    }
    if (!isFirst)
    {
      output << '\n';
    }
    sumsList.push_back(sum);
  }

  if (isOverflow)
  {
    throw std::out_of_range("Error: Sum is out of range");
  }

  for (auto sumsIterator = sumsList.cbegin(); sumsIterator != sumsList.cend(); ++sumsIterator)
  {
    if (sumsIterator != sumsList.cbegin())
    {
      output << ' ';
    }
    output << *sumsIterator;
  }
  output << '\n';
}

