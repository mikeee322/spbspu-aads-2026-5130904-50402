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

  void Wordbook::assignPartOfSpeech(const std::string& eng, const std::string& pos)
  {
    if (!words_.has(eng))
    {
      throw std::logic_error("Word does not exist");
    }
    words_.get(eng).setPartOfSpeech(pos);
  }

  const std::string& Wordbook::getName() const
  {
    return name_;
  }

  bool Wordbook::hasWord(const std::string& eng) const
  {
    return words_.has(eng);
  }

  Word& Wordbook::getWord(const std::string& eng)
  {
    if (!words_.has(eng))
    {
      throw std::logic_error("Word does not exist");
    }
    return words_.get(eng);
  }

  const Word& Wordbook::getWord(const std::string& eng) const
  {
    if (!words_.has(eng))
    {
      throw std::logic_error("Word does not exist");
    }
    return words_.get(eng);
  }

  void Wordbook::removeInterpretation(const std::string& eng)
  {
    if (!words_.has(eng))
    {
      throw std::logic_error("Word does not exist");
    }
    words_.get(eng).removeInterpretation();
  }


}
