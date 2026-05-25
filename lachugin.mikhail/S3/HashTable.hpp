#ifndef HASHTABLE_HPP
#define HASHTABLE_HPP
#include "../common/list.hpp"

namespace lachugin
{
  template< class Key, class Value, class Hash, class Equal >
  class HashTable {
  public:
    HashTable(size_t cap);
    ~HashTable();

    void add(const Key& k, const Value& v);
    Value drop(const Key& k);
    bool has(const Key& k) const;

  private:
    List< std::pair< Key, Value > >* buckets_;
    size_t cap_;
    size_t size_;
    Hash hasher_;
    Equal equal_;
  };

  template< class Key, class Value, class Hash, class Equal >
  HashTable<Key, Value, Hash, Equal>::HashTable(size_t cap):
    buckets_(new List< std::pair< Key, Value > >[cap]),
    cap_ (cap),
    size_ (0)
  {}

  template< class Key, class Value, class Hash, class Equal >
  HashTable< Key, Value, Hash, Equal >::~HashTable()
  {
    delete[] buckets_;
  }


}
#endif
