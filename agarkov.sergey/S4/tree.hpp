#ifndef TREE_HPP
#define TREE_HPP

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
}

#endif