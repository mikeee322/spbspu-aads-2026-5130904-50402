#ifndef COMMANDS_HPP
#define COMMANDS_HPP

#include "WordbookManager.hpp"
#include <iostream>

namespace lachugin
{
  void cmdMake(std::istream&, std::ostream&, WordbookManager&);
  void cmdDelete(std::istream&, std::ostream&, WordbookManager&);
  void cmdAddWord(std::istream&, std::ostream&, WordbookManager&);
  void cmdRemove(std::istream&, std::ostream&, WordbookManager&);
  void cmdAddAnother(std::istream&, std::ostream&, WordbookManager&);
  void cmdAddInterpretation(std::istream&, std::ostream&, WordbookManager&);
  void cmdRemoveInterpretation(std::istream&, std::ostream&, WordbookManager&);
  void cmdDivWord(std::istream&, std::ostream&, WordbookManager&);
}

#endif