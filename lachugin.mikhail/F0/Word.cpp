#include "Word.hpp"

namespace lachugin
{
  Word::Word()
  {}

  Word::Word(const std::string& translation)
  {
    translations_.pushBack(translation);
  }

  void Word::addTranslation(const std::string& translation)
  {
    translations_.pushBack(translation);
  }



}
