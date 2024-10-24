#ifndef STACK_HPP
#define STACK_HPP

#include <stdexcept>
#include <list>

namespace agarkov
{
  template< typename T >
  class Stack
  {
    public:
      Stack() = default;
      ~Stack() = default;
      Stack(const Stack< T >& other);
      Stack< T >& operator=(const Stack< T >& other);
      Stack(Stack< T >&& other) noexcept;
      Stack< T >& operator=(Stack< T >&& other) noexcept;
      void push(const T& value);
      void pop();
      T get() const;
      bool isEmpty() const;
    private:
      std::list<T> data_;
  };

  template< typename T >
  bool Stack< T >::isEmpty() const
  {
    return data_.empty();
  }

  template< typename T >
  void Stack< T >::push(const T& value)
  {
    data_.push_back(value);
  }

  template< typename T >
  T Stack< T >::get() const
  {
    if (isEmpty())
    {
      throw std::logic_error("Empty stack");
    }
    return data_.back();
  }

  template< typename T >
  void Stack< T >::pop()
  {
    if (isEmpty())
    {
      throw std::logic_error("Empty stack");
    }
    data_.pop_back();
  }

  template< typename T >
  Stack< T >::Stack(const Stack< T >& other):
    data_(other.data_)
  {
  }

  template< typename T >
  Stack< T >& Stack< T >::operator=(const Stack< T >& other)
  {
    if (this != std::addressof(other))
    {
      data_ = other.data_;
    }
    return *this;
  }

  template< typename T >
  Stack< T >::Stack(Stack< T >&& other) noexcept:
    data_(std::move(other.data_))
  {
  }

  template< typename T >
  Stack< T >& Stack< T >::operator=(Stack< T >&& other) noexcept
  {
    if (this != std::addressof(other))
    {
      data_ = std::move(other.data_);
    }
  }
}

#endif
