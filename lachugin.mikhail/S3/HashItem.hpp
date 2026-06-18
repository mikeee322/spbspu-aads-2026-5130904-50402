#ifndef HASHTITEM_HPP
#define HASHTITEM_HPP

template < class Key, class Value >
struct HashItem
{
  Key key;
  Value value;
  bool occupied;
};

#endif
