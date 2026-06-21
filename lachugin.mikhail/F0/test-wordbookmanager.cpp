#include <boost/test/unit_test.hpp>
#include "WordbookManager.hpp"
using namespace lachugin;

BOOST_AUTO_TEST_CASE(wordbookmanager_create_test)
{
  WordbookManager manager;
  manager.createWordbook("dict");
  BOOST_TEST(manager.hasWordbook("dict"));
}

BOOST_AUTO_TEST_CASE(wordbookmanager_duplicate_create_test)
{
  WordbookManager manager;
  manager.createWordbook("dict");
  BOOST_CHECK_THROW(manager.createWordbook("dict"), std::logic_error);
}

BOOST_AUTO_TEST_CASE(wordbookmanager_delete_test)
{
  WordbookManager manager;
  manager.createWordbook("dict");
  manager.deleteWordbook("dict");
  BOOST_TEST(!manager.hasWordbook("dict"));
}

BOOST_AUTO_TEST_CASE(wordbookmanager_delete_missing_test)
{
  WordbookManager manager;
  BOOST_CHECK_THROW(manager.deleteWordbook("dict"),std::logic_error);
}

BOOST_AUTO_TEST_CASE(wordbookmanager_get_wordbook_test)
{
  WordbookManager manager;
  manager.createWordbook("dict");
  BOOST_TEST(manager.getWordbook("dict").getName() == "dict");
}

