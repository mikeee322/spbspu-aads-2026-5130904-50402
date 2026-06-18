#include "Edge.hpp"
#include <string>
namespace lachugin
{
  bool EdgeEqual::operator()(const Edge &lhs, const Edge &rhs) const
  {
    return lhs.from == rhs.from && lhs.to == rhs.to;
  }

  size_t EdgeHash::operator()(const Edge &e) const
  {
    return std::hash<std::string>{}(e.from) ^ std::hash<std::string>{}(e.to);
  }

}
