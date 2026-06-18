#ifndef EDGE_HPP
#define EDGE_HPP
#include <cstddef>
#include <string>
namespace lachugin
{
  struct Edge
  {
    std::string from;
    std::string to;
  };

  struct EdgeEqual
  {
    bool operator()(const Edge& lhs, const Edge& rhs) const;
  };

  struct EdgeHash
  {
    size_t operator()(const Edge& e) const;
  };
}
#endif

