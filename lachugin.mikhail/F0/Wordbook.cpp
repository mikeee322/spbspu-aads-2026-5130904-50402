#include "Wordbook.hpp"

namespace lachugin
{

  Wordbook::Wordbook():
  name_("")
  {}

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

  CuckooIter< std::string, Word, DefaultHash1< std::string >, DefaultHash2< std::string >,
    std::equal_to< std::string > > Wordbook::begin()
  {
    return words_.begin();
  }

  CuckooIter< std::string, Word, DefaultHash1< std::string >, DefaultHash2< std::string >,
    std::equal_to< std::string > > Wordbook::end()
  {
    return words_.end();
  }

  void Wordbook::addWordObject(const std::string& eng, const Word& word)
  {
    if (words_.has(eng))
    {
      throw std::logic_error("Word already exists");
    }
    words_.add(eng, word);
  }

  void Wordbook::showStartsWith(std::ostream& out, char letter) const
  {
    for (auto it = words_.begin();it != words_.end();++it)
    {
      if (!it->first.empty() && it->first[0] == letter)
      {
        out << it->first << " - ";
        const List< std::string >& trs = it->second.getTranslations();
        bool firstTranslation = true;
        for (auto tr = trs.begin(); tr != trs.end(); ++tr)
        {
          if (!firstTranslation)
          {
            out << ", ";
          }
          out << *tr;
          firstTranslation = false;
        }
        out << "\n";
      }
    }
  }

  void Wordbook::showPartsOfSpeech(std::ostream& out, const std::string& pos) const
  {
    for (auto it = words_.begin(); it != words_.end(); ++it)
    {
      if (it->second.getPartOfSpeech() == pos)
      {
        out << it->first << " - ";
        const List< std::string >& trs = it->second.getTranslations();
        bool firstTranslation = true;
        for (auto tr = trs.begin(); tr != trs.end(); ++tr)
        {
          if (!firstTranslation)
          {
            out << ", ";
          }
          out << *tr;
          firstTranslation = false;
        }
        out << "\n";
      }
    }
  }




}
