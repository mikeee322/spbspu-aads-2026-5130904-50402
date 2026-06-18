#include "commands.hpp"
#include "Graph.hpp"
#include "sorts.hpp"

namespace lachugin
{
  void cmdGraphs(std::istream&, std::ostream& out, GraphStorage& storage)
  {
    List< std::string > names;
    const auto& graphs = storage.getGraphs();
    for (auto it = graphs.begin(); it != graphs.end(); ++it)
    {
      names.pushBack(it->key);
    }
    sortList(names);
    for (auto it = names.begin(); it != names.end(); ++it)
    {
      out << *it << '\n';
    }
  }

  void cmdVertexes(std::istream& in, std::ostream& out, GraphStorage& storage)
  {
    std::string graphName;
    in >> graphName;
    const Graph& graph = storage.getGraph(graphName);
    List< std::string > verts = graph.getVertexes();
    sortList(verts);

    for (auto it = verts.begin(); it != verts.end(); ++it)
    {
      out << *it << '\n';
    }
  }

  void cmdOutbound(std::istream& in, std::ostream& out, GraphStorage& storage)
  {
    std::string name;
    std::string vertex;
    in >> name >> vertex;
    const Graph& graph = storage.getGraph(name);

    if (!graph.hasVertex(vertex))
    {
      throw std::logic_error("no vertex");
    }

    List< Edge > edges = graph.outbound(vertex);
    sortEdgesByTo(edges);
    for (auto it = edges.begin(); it != edges.end(); ++it)
    {
      out << (*it).to;
      List< size_t > weights = graph.getEdges().get(*it);
      sortList(weights);

      for (auto w = weights.begin(); w != weights.end(); ++w)
      {
        out << ' ' << *w;
      }
      out << '\n';
    }
  }

  void cmdInbound(std::istream& in, std::ostream& out, GraphStorage& storage)
  {
    std::string name;
    std::string vertex;
    in >> name >> vertex;
    const Graph& graph = storage.getGraph(name);
    if (!graph.hasVertex(vertex))
    {
      throw std::logic_error("no vertex");
    }

    List< Edge > edges = graph.inbound(vertex);
    sortEdgesByFrom(edges);
    for (auto it = edges.begin(); it != edges.end(); ++it)
    {
      out << (*it).from;
      List< size_t > weights = graph.getEdges().get(*it);
      sortList(weights);

      for (auto w = weights.begin(); w != weights.end(); ++w)
      {
        out << ' ' << *w;
      }
      out << '\n';
    }
  }

  void cmdCreate(std::istream& in, std::ostream&, GraphStorage& storage)
  {
    std::string name;
    in >> name;
    if (storage.hasGraph(name))
    {
      throw std::logic_error("Graph exists");
    }
    Graph graph;
    storage.addGraph(name, graph);
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
