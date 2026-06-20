#include "Wordbook.hpp"

namespace lachugin
{
  Wordbook::Wordbook(const std::string& name):
  name_(name)
  {}

  void Wordbook::addWord(const std::string& eng, const std::string& rus)
  {
    if (words_.has(eng))
    {
      throw std::logic_error("Word already exists");
    }
    words_.add(eng, Word(rus));
  }


}
