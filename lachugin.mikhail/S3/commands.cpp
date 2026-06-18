#include "commands.hpp"
#include "Graph.hpp"

namespace lachugin
{
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



}
