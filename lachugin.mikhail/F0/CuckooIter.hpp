#ifndef ITERATOR_HPP
#define ITERATOR_HPP
#include <algorithm>
#include "CuckooHashTable.hpp"

namespace lachugin
{
  template< class Key, class Value, class Hash1, class Hash2, class Equal >
  class CuckooIter
  {
  public:
    friend class CuckooHashTable<Key, Value, Hash1, Hash2, Equal>;
    std::pair< Key, Value >& operator*() const;
    std::pair< Key, Value> * operator->() const;
    CuckooIter& operator++();
    bool operator==(const CuckooIter&) const;
    bool operator!=(const CuckooIter&) const;

  private:
    CuckooIter(CuckooHashTable< Key, Value, Hash1, Hash2, Equal >* table, bool secondTable, size_t pos);
    void skipEmpty();
    CuckooHashTable< Key, Value, Hash1, Hash2, Equal >* table_;
    bool secondTable_;
    size_t pos_;
  };

}
#endif
