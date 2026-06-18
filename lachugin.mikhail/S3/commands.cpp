#include "commands.hpp"
#include "Graph.hpp"

namespace lachugin
{
  template< class T >
  void sortList(List< T >& list)
  {
    if (list.size() < 2)
    {
      return;
    }
    for (auto it1 = list.begin(); it1 != list.end(); ++it1)
    {
      auto minIt = it1;
      for (auto it2 = it1; it2 != list.end(); ++it2)
      {
        if (*it2 < *minIt)
        {
          minIt = it2;
        }
      }
      if (minIt != it1)
      {
        T tmp = *it1;
        *it1 = *minIt;
        *minIt = tmp;
      }
    }
  }

  void cmdGraphs(std::istream&, std::ostream& out, GraphStorage& storage)
  {
    auto& graphs = storage.getGraphs();
    for (auto it = graphs.begin(); it != graphs.end(); ++it)
    {
      out << it->key << '\n';
    }
  }

  void cmdVertexes(std::istream& in, std::ostream& out, GraphStorage& storage)
  {
    std::string graphName;
    in >> graphName;
    Graph& graph = storage.getGraph(graphName);
    const List< std::string >& verts = graph.getVertexes();

    for (auto it = verts.begin(); it != verts.end(); ++it)
    {
      out << *it << '\n';
    }
  }

  void cmdOutbound(std::istream& in, std::ostream& out, GraphStorage& storage)
  {
    std::string graphName;
    std::string vertex;
    in >> graphName >> vertex;

    const Graph& graph = storage.getGraph(graphName);
    const auto& edges = graph.getEdges();
    for (auto it = edges.begin(); it != edges.end(); ++it)
    {
      if (it->key.from == vertex)
      {
        out << it->key.to;
        for (auto w = it->value.begin(); w != it->value.end(); ++w)
        {
          out << ' ' << *w;
        }
        out << '\n';
      }
    }
  }

  void cmdInbound(std::istream& in, std::ostream& out, GraphStorage& storage)
  {
    std::string graphName;
    std::string vertex;
    in >> graphName >> vertex;

    const Graph& graph = storage.getGraph(graphName);
    const auto& edges = graph.getEdges();
    for (auto it = edges.begin(); it != edges.end(); ++it)
    {
      if (it->key.to == vertex)
      {
        out << it->key.from;
        for (auto w = it->value.begin(); w != it->value.end(); ++w)
        {
          out << ' ' << *w;
        }
        out << '\n';
      }
    }
  }

  void cmdCreate(std::istream& in, std::ostream&, GraphStorage& storage)
  {
    std::string name;
    in >> name;
    Graph gr;
    storage.addGraph(name, gr);
  }

  void cmdBind(std::istream& in, std::ostream&, GraphStorage& storage)
  {
    std::string name;
    std::string from;
    std::string to;
    size_t weight = 0;
    in >> name >> from >> to >> weight;

    storage.getGraph(name).bind(from, to, weight);
  }

  void cmdCut(std::istream& in, std::ostream&, GraphStorage& storage)
  {
    std::string name;
    std::string from;
    std::string to;
    size_t weight = 0;
    in >> name >> from >> to >> weight;

    storage.getGraph(name).cut(from, to, weight);
  }



}
