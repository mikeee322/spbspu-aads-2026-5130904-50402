#ifndef WORD_HPP
#define WORD_HPP
#include "CuckooHashTable.hpp"
#include <stdexcept>
#include "../common/list.hpp"
#include <string>

namespace lachugin
{
  class Word
  {
    List <std::string > translations_;
    std::string interpretation_;
    std::string partOfSpeech_;
  };

}

#endif

