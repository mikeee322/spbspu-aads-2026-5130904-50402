#ifndef HASHTABLE_HPP
#define HASHTABLE_HPP
#include "../common/list.hpp"
#include "../common/itters.hpp"
#include "../common/node.hpp"
namespace lachugin
{
  template< class Key, class Value, class Hash, class Equal >
  class HashTable {
    using value_type = std::pair< Key, Value >;
  public:
    HashTable(size_t cap);
    ~HashTable();

    void add(const Key& k, const Value& v);
    Value drop(const Key& k);
    bool has(const Key& k) const;
    Value& get(const Key& k);
    const Value& get(const Key& k) const;

    size_t size() const noexcept;
    bool empty() const noexcept;

    void clear();
  private:
    List< std::pair< Key, Value > >* buckets_;
    size_t cap_;
    size_t size_;
    Hash hasher_;
    Equal equal_;
  };

  template< class Key, class Value, class Hash, class Equal >
  HashTable< Key, Value, Hash, Equal >::HashTable(size_t cap):
    buckets_(new List< std::pair< Key, Value > >[cap]),
    cap_ (cap),
    size_ (0)
  {}

  template< class Key, class Value, class Hash, class Equal >
  HashTable< Key, Value, Hash, Equal >::~HashTable()
  {
    delete[] buckets_;
  }

  template< class Key, class Value, class Hash, class Equal >
  void HashTable< Key, Value, Hash, Equal >::add(const Key &k, const Value &v)
  {
    size_t index = hasher_(k);
    List< value_type >&buck = buckets_[index];
    LIter< value_type > it = buck.begin();
    for (; it != buck.end(); ++it)
    {
      if (equal_((*it).first, k))
      {
        throw std::logic_error("err: key already exist");
      }
    }
    buck.pushBack({k, v});
    size_++;
  }

  template< class Key, class Value, class Hash, class Equal >
  bool HashTable< Key, Value, Hash, Equal >::has(const Key &k) const
  {
    size_t index = hasher_(k);
    const List< value_type >&buck = buckets_[index];
    LCIter< value_type > it = buck.begin();
    for (; it != buck.end(); ++it) {
      if (equal_((*it).first, k)) {
        return true;
      }
    }
    return false;
  }

  template< class Key, class Value, class Hash, class Equal >
  Value HashTable< Key, Value, Hash, Equal >::drop(const Key &k) {
    size_t index = hasher_(k);
    List< value_type >&buck = buckets_[index];
    LIter< value_type > it = buck.begin();
    for (; it != buck.end(); ++it) {
      if (equal_((*it).first, k)) {
        Value result = (*it).second;

        buck.erase(it);

        --size_;
        return result;
      }
    }
    throw std::out_of_range ("err: out of range");
  }


  template< class Key, class Value, class Hash, class Equal >
  size_t HashTable< Key, Value, Hash, Equal >::size() const noexcept {
    return size_;
  }

  template< class Key, class Value, class Hash, class Equal >
  bool HashTable< Key, Value, Hash, Equal >::empty() const noexcept {
    return size_ == 0;
  }

  template < class Key, class Value, class Hash, class Equal >
  Value &HashTable< Key, Value, Hash, Equal >::get(const Key &k) {
    size_t index = hasher_(k);
    List< value_type >&buck = buckets_[index];
    LIter< value_type > it = buck.begin();

    for (; it != buck.end(); ++it) {
      if (equal_((*it).first, k)) {
        return (*it).second;
      }
    }
    throw std::out_of_range ("err: out of range");
  }

  template < class Key, class Value, class Hash, class Equal >
  const Value &HashTable< Key, Value, Hash, Equal >::get(const Key &k) const {
    size_t index = hasher_(k);
    const List< value_type >&buck = buckets_[index];
    LCIter< value_type > it = buck.begin();
    for (; it != buck.end(); ++it) {
      if (equal_((*it).first, k)) {
        return (*it).second;
      }
    }
    throw std::out_of_range ("err: out of range");
  }

  template < class Key, class Value, class Hash, class Equal >
  void HashTable< Key, Value, Hash, Equal >::clear() {
    for (size_t i = 0; i < cap_; ++i) {
      buckets_[i].clear();
    }
    size_ = 0;
  }




}
#endif
