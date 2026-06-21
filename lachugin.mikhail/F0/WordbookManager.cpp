#include "WordbookManager.hpp"

namespace lachugin
{

  void WordbookManager::createWordbook(const std::string& name)
  {
    if (wordbooks_.has(name))
    {
      throw std::logic_error("Wordbook already exists");
    }
    wordbooks_.add(name, Wordbook(name));
  }

  void WordbookManager::deleteWordbook(const std::string& name)
  {
    if (!wordbooks_.has(name))
    {
      throw std::logic_error("Wordbook does not exist");
    }
    wordbooks_.drop(name);
  }

  bool WordbookManager::hasWordbook(const std::string& name) const
  {
    return wordbooks_.has(name);
  }

  Wordbook& WordbookManager::getWordbook(const std::string& name)
  {
    if (!wordbooks_.has(name))
    {
      throw std::logic_error("Wordbook does not exist");
    }
    return wordbooks_.get(name);
  }

  const Wordbook& WordbookManager::getWordbook(const std::string& name) const
  {
    if (!wordbooks_.has(name))
    {
      throw std::logic_error("Wordbook does not exist");
    }
    return wordbooks_.get(name);
  }



}

