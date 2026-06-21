#ifndef COMMANDS_HPP
#define COMMANDS_HPP

#include "WordbookManager.hpp"
#include <iostream>

namespace lachugin
{
  void cmdMake(std::istream&, std::ostream&, WordbookManager&);
  void cmdDelete(std::istream&, std::ostream&, WordbookManager&);

}

#endif