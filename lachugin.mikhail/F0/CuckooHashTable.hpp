#ifndef HASHTABLE_HPP
#define HASHTABLE_HPP

#include <cstddef>

namespace lachugin
{
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
    CuckooItem< Key, Value >* table1_;
    CuckooItem< Key, Value >* table2_;
    size_t capacity_;
    size_t size_;

    Hash1 hash1_;
    Hash2 hash2_;
    Equal equal_;
  };



}

#endif
