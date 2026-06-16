#ifndef GRAPH_HPP
#define GRAPH_HPP
#include "../common/list.hpp"
#include "HashTable.hpp"

namespace lachugin
{
  class Graph
  {
  public:
    Graph();
    void addVertex(const std::string& name);
    bool hasVertex(const std::string& name) const;

  private:
    List < std::string > vertexes_;

  };


}


#endif
