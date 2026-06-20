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

  void Wordbook::removeWord(const std::string& eng)
  {
    if (!words_.has(eng))
    {
      throw std::logic_error("Word does not exist");
    }

    words_.drop(eng);
  }

  void Wordbook::addAnotherTranslation(const std::string& eng, const std::string& rus)
  {
    if (!words_.has(eng))
    {
      throw std::logic_error("Word does not exist");
    }

    words_.get(eng).addTranslation(rus);
  }

  void Wordbook::addInterpretation(const std::string& eng, const std::string& interpretation)
  {
    if (!words_.has(eng))
    {
      throw std::logic_error("Word does not exist");
    }

    words_.get(eng).setInterpretation(interpretation);
  }


}
