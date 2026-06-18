#ifndef COMMANDS_HPP
#define COMMANDS_HPP
#include <ostream>
#include <fstream>
#include "GraphStorage.hpp"

namespace lachugin
{
  using Command = void (*)(std::istream&, std::ostream&, GraphStorage&);
  void cmdGraphs(std::istream&, std::ostream&, GraphStorage&);
}

#endif
