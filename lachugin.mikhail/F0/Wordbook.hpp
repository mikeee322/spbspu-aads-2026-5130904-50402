#ifndef WORDBOOK_HPP
#define WORDBOOK_HPP

#include "Word.hpp"

namespace lachugin
{
  class Wordbook
  {
  public:
    Wordbook(const std::string& name);
    const std::string& getName() const;

    void addWord(const std::string& eng, const std::string& rus);
    void removeWord(const std::string& eng);
    void addAnotherTranslation(const std::string& eng, const std::string& rus);
    void addInterpretation(const std::string& eng, const std::string& interpretation);
    void removeInterpretation(const std::string& eng);
    void assignPartOfSpeech(const std::string& eng, const std::string& pos);
    bool hasWord(const std::string& eng) const;
    Word& getWord(const std::string& eng);
    const Word& getWord(const std::string& eng) const;
  private:
    std::string name_;

    CuckooHashTable< std::string, Word, DefaultHash1< std::string >, DefaultHash2< std::string >,
      std::equal_to< std::string > > words_;
  };
}


#endif

