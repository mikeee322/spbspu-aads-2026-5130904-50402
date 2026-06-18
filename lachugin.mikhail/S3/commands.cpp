#include "commands.hpp"

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


}
