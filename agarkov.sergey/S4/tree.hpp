#ifndef TREE_HPP
#define TREE_HPP

#include <cstddef>

namespace agarkov
{
  template< typename T >
  struct Tree
  {
    T data_;
    Tree< T >* left_ = nullptr;
    Tree< T >* head_ = nullptr;
    Tree< T >* right_ = nullptr;
    size_t height_ = 0;
  };

  template< typename T >
  size_t getHeight(const Tree< T >* tree)
  {
    if (tree)
    {
      return tree->height_;
    }
    return 0ull;
  }
}

#endif