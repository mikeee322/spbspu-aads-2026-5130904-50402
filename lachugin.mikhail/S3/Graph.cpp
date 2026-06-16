#include "Graph.hpp"
#include "HashTable.hpp"

namespace lachugin {

  Graph::Graph()
  {}

  bool Graph::hasVertex(const std::string &name) const
  {
    for (auto it = vertexes_.begin(); it != vertexes_.end(); ++it)
    {
    if (*it == name)
      {
      return true;
      }
    }
    return false;
  }

  void Graph::addVertex(const std::string& name)
  {
    if (!hasVertex(name))
    {
      vertexes_.pushBack(name);
    }
  }


}