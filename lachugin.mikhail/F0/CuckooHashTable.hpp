#ifndef HASHTABLE_HPP
#define HASHTABLE_HPP

#include "CuckooItem.hpp"
#include <cstddef>

namespace lachugin
{
  template< class Key >
  struct DefaultHash1
  {
    size_t operator()(const Key& key) const
    {
      return std::hash< Key >{}(key);
    }
  };

  template< class Key >
  struct DefaultHash2
  {
    size_t operator()(const Key& key) const
    {
      size_t h = std::hash< Key >{}(key);
      return h ^ 0x9e3779b97f4a7c15ULL;
    }
  };

  template< class Key, class Value, class Hash1, class Hash2, class Equal >
  class CuckooHashTable
  {
  public:
    using value_type = std::pair< Key, Value >;
    CuckooHashTable(size_t capacity = 17);

    ~CuckooHashTable();
    CuckooHashTable(const CuckooHashTable&);
    CuckooHashTable& operator=(const CuckooHashTable&);
    CuckooHashTable(CuckooHashTable&&) noexcept;
    CuckooHashTable& operator=(CuckooHashTable&&) noexcept;

    void add(const Key&, const Value&);
    Value drop(const Key&);
    bool has(const Key&) const;
    Value& get(const Key&);
    const Value& get(const Key&) const;
    void clear();

    size_t size() const;
    bool empty() const;
    void rehash(size_t);

    Iterator begin();
    Iterator end();
    ConstIterator begin() const;
    ConstIterator end() const;

  private:
    size_t hashPos1(const Key&) const;
    size_t hashPos2(const Key&) const;
    void insertWithoutCheck(const Key&, const Value&);

    CuckooItem< Key, Value >* table1_;
    CuckooItem< Key, Value >* table2_;
    size_t capacity_;
    size_t size_;

    Hash1 hash1_;
    Hash2 hash2_;
    Equal equal_;
  };

  template< class Key, class Value, class Hash1, class Hash2, class Equal >
  CuckooHashTable< Key, Value, Hash1, Hash2, Equal >::CuckooHashTable(size_t capacity):
  table1_(new CuckooItem< Key, Value >[capacity]),
  table2_(new CuckooItem< Key, Value >[capacity]),
  capacity_(capacity),
  size_(0)
  {}



}

#endif
