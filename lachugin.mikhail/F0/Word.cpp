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

  bool Word::hasTranslation(const std::string& translation) const
  {
    for (auto it = translations_.begin(); it != translations_.end(); ++it)
    {
      if (*it == translation)
      {
        return true;
      }
    }
    return false;
  }

  List< std::string> & Word::getTranslations()
  {
    return translations_;
  }



}
