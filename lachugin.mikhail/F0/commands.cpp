#include "commands.hpp"


namespace lachugin
{
  void cmdMake(std::istream& in, std::ostream& out, WordbookManager& manager)
  {
    std::string name;
    in >> name;
    manager.createWordbook(name);
    out << "Wordbook \"" << name << "\" was created\n";
  }

  void cmdDelete(std::istream& in, std::ostream& out, WordbookManager& manager)
  {
    std::string name;
    in >> name;
    manager.deleteWordbook(name);
    out << "Wordbook \"" << name << "\" was deleted\n";
  }

  void cmdAddWord(std::istream& in, std::ostream& out, WordbookManager& manager)
  {
    std::string wordbook;
    std::string eng;
    std::string rus;
    in >> wordbook >> eng >> rus;
    manager.getWordbook(wordbook).addWord(eng, rus);
    out << "Word " << eng << " was added in " << wordbook << "\n";
  }

  void cmdRemove( std::istream& in, std::ostream& out, WordbookManager& manager)
  {
    std::string wordbook;
    std::string word;
    in >> wordbook >> word;
    manager.getWordbook(wordbook).removeWord(word);
    out << "Word " << word << " was removed from " << wordbook << ".\n";
  }


}
