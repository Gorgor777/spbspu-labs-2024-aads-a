#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <stdexcept>
#include <list>

namespace agarkov
{
  template< typename T >
  class Queue
  {
    public:
      Queue() = default;
      ~Queue() = default;
      Queue(const Queue< T >& other);
      Queue< T >& operator=(const Queue< T >& other);
      Queue(Queue< T >&& other) noexcept;
      Queue< T >& operator=(Queue < T >&& other) noexcept;
      bool isEmpty() const;
      void pop();
      void clear();
      void push(const T& value);
      T get() const;
    private:
      std::list<T> data_;
  };

  template< typename T >
  Queue< T >::Queue(const Queue< T >& other):
    data_(other.data_)
  {
  }

  template< typename T >
  Queue< T >& Queue< T >::operator=(const Queue< T >& other)
  {
    if (this != std::addressof(other))
    {
      data_ = other.data_;
    }
    return *this;
  }

  template < typename T >
  Queue< T >::Queue(Queue< T >&& other) noexcept:
    data_(std::move(other.data_))
  {
  }

  template < typename T >
  Queue< T >& Queue< T >::operator=(Queue< T >&& other) noexcept
  {
    if (this != std::addressof(other))
    {
      data_ = std::move(other.data_);
    }
    return *this;
  }

  template< typename T >
  bool Queue< T >::isEmpty() const
  {
    return data_.empty();
  }

  template< typename T >
  void Queue< T >::pop()
  {
    if (isEmpty())
    {
      throw std::logic_error("Empty queue");
    }
    data_.pop_front();
  }

  template< typename T >
  void Queue< T >::push(const T& value)
  {
    data_.push_back(value);
  }

  template< typename T >
  T Queue< T >::get() const
  {
    if (isEmpty())
    {
      throw std::logic_error("Empty queue");
    }
    return data_.front();
  }

}

#endif
