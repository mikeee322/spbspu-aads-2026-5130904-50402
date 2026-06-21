#include "commands.hpp"


namespace lachugin
{
  void lachugin::cmdMake(std::istream& in, std::ostream& out, WordbookManager& manager)
  {
    std::string name;
    in >> name;
    manager.createWordbook(name);
    out << "Wordbook \"" << name << "\" was created\n";
  }

  void lachugin::cmdDelete(std::istream& in, std::ostream& out, WordbookManager& manager)
  {
    std::string name;
    in >> name;
    manager.deleteWordbook(name);
    out << "Wordbook \"" << name << "\" was deleted\n";
  }
}
