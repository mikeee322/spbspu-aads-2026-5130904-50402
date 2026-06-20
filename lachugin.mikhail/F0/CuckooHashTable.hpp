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
    void swap(CuckooHashTable& other);

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

  template< class Key, class Value, class Hash1, class Hash2, class Equal >
  CuckooHashTable< Key, Value, Hash1, Hash2, Equal >::~CuckooHashTable()
  {
    delete[] table1_;
    delete[] table2_;
  }

  template< class Key, class Value, class Hash1, class Hash2, class Equal >
  size_t CuckooHashTable<Key, Value, Hash1, Hash2, Equal>::size() const
  {
    return size_;
  }

  template< class Key, class Value, class Hash1, class Hash2, class Equal >
  bool CuckooHashTable< Key, Value, Hash1, Hash2, Equal >::empty() const
  {
    return size_ == 0;
  }

  template< class Key, class Value, class Hash1, class Hash2, class Equal >
  size_t CuckooHashTable< Key, Value, Hash1, Hash2, Equal >::hashPos1(const Key& key) const
  {
    return hash1_(key) % capacity_;
  }

  template< class Key, class Value, class Hash1, class Hash2, class Equal >
  size_t CuckooHashTable< Key, Value, Hash1, Hash2, Equal >::hashPos2(const Key& key) const
  {
    return hash2_(key) % capacity_;
  }

  template< class Key, class Value, class Hash1, class Hash2, class Equal >
  bool CuckooHashTable< Key, Value, Hash1, Hash2, Equal >::has(const Key& key) const
  {
    size_t pos1 = hashPos1(key);
    if (table1_[pos1].occupied && equal_(table1_[pos1].data.first, key))
    {
      return true;
    }
    size_t pos2 = hashPos2(key);
    if (table2_[pos2].occupied && equal_(table2_[pos2].data.first, key))
    {
      return true;
    }
    return false;
  }

  template< class Key, class Value, class Hash1, class Hash2, class Equal >
  Value& CuckooHashTable< Key, Value, Hash1, Hash2, Equal >::get(const Key& key)
  {
    size_t pos1 = hashPos1(key);
    if (table1_[pos1].occupied && equal_(table1_[pos1].data.first, key))
    {
      return table1_[pos1].data.second;
    }
    size_t pos2 = hashPos2(key);
    if (table2_[pos2].occupied && equal_(table2_[pos2].data.first, key))
    {
      return table2_[pos2].data.second;
    }
    throw std::out_of_range("Key does not exist");
  }

  template< class Key, class Value, class Hash1, class Hash2, class Equal >
  const Value& CuckooHashTable< Key, Value, Hash1, Hash2, Equal >::get(const Key& key) const
  {
    size_t pos1 = hashPos1(key);
    if (table1_[pos1].occupied && equal_(table1_[pos1].data.first, key))
    {
      return table1_[pos1].data.second;
    }
    size_t pos2 = hashPos2(key);
    if (table2_[pos2].occupied && equal_(table2_[pos2].data.first, key))
    {
      return table2_[pos2].data.second;
    }
    throw std::out_of_range("Key does not exist");
  }

  template< class Key, class Value, class Hash1, class Hash2, class Equal >
  void CuckooHashTable< Key, Value, Hash1, Hash2, Equal >::clear()
  {
    delete[] table1_;
    delete[] table2_;
    table1_ = new CuckooItem< Key, Value >[capacity_];
    table2_ = new CuckooItem< Key, Value >[capacity_];
    size_ = 0;
  }

  template< class Key, class Value, class Hash1, class Hash2, class Equal >
  CuckooHashTable< Key, Value, Hash1, Hash2, Equal >::CuckooHashTable(const CuckooHashTable& other):
  table1_(new CuckooItem<Key, Value>[other.capacity_]),
  table2_(new CuckooItem<Key, Value>[other.capacity_]),
  capacity_(other.capacity_),
  size_(other.size_),
  hash1_(other.hash1_),
  hash2_(other.hash2_),
  equal_(other.equal_)
  {
    for (size_t i = 0; i < capacity_; ++i)
    {
      table1_[i] = other.table1_[i];
      table2_[i] = other.table2_[i];
    }
  }

  template< class Key, class Value, class Hash1, class Hash2, class Equal >
  void CuckooHashTable< Key, Value, Hash1, Hash2, Equal >::swap(CuckooHashTable& other)
  {
    std::swap(table1_, other.table1_);
    std::swap(table2_, other.table2_);
    std::swap(capacity_, other.capacity_);
    std::swap(size_, other.size_);
    std::swap(hash1_, other.hash1_);
    std::swap(hash2_, other.hash2_);
    std::swap(equal_, other.equal_);
  }

  template< class Key, class Value, class Hash1, class Hash2, class Equal >
  CuckooHashTable< Key, Value, Hash1, Hash2, Equal >&
  CuckooHashTable< Key, Value, Hash1, Hash2, Equal >::operator=(const CuckooHashTable& other)
  {
    if (this != &other)
    {
      CuckooHashTable temp(other);
      swap(temp);
    }
    return *this;
  }





}

#endif
