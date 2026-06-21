#ifndef WORDBOOK_HPP
#define WORDBOOK_HPP

#include "Word.hpp"

namespace lachugin
{
  class Wordbook
  {
  public:
    using table_type = CuckooHashTable< std::string, Word, DefaultHash1 <std::string >,
      DefaultHash2< std::string >, std::equal_to< std::string > >;
    Wordbook();
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

    CuckooIter< std::string, Word, DefaultHash1< std::string >, DefaultHash2< std::string >,
      std::equal_to< std::string > > begin();

    CuckooIter< std::string, Word, DefaultHash1< std::string >, DefaultHash2< std::string >,
      std::equal_to< std::string > > end();
  private:
    std::string name_;
    table_type words_;
  };
}


#endif

