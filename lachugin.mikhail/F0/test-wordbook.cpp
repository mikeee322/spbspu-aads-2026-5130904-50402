#include <boost/test/unit_test.hpp>
#include "Wordbook.hpp"
using namespace lachugin;

BOOST_AUTO_TEST_CASE(wordbook_constructor_test)
{
  Wordbook wb("dictionary");
  BOOST_TEST(wb.getName() == "dictionary");
}

BOOST_AUTO_TEST_CASE(wordbook_add_word_test)
{
  Wordbook wb("dictionary");
  wb.addWord("watermelon", "арбуз");
  BOOST_TEST(wb.hasWord("watermelon"));
}

BOOST_AUTO_TEST_CASE(duplicate_word_test)
{
  Wordbook wb("dictionary");
  wb.addWord("watermelon", "арбуз");
  BOOST_CHECK_THROW(wb.addWord("watermelon", "арбузик"), std::logic_error);
}

BOOST_AUTO_TEST_CASE(wordbook_remove_word_test)
{
  Wordbook wb("dictionary");
  wb.addWord("watermelon", "арбуз");
  wb.removeWord("watermelon");
  BOOST_TEST(!wb.hasWord("watermelon"));
}

BOOST_AUTO_TEST_CASE(remove_missing_word_test)
{
  Wordbook wb("dictionary");
  BOOST_CHECK_THROW(wb.removeWord("watermelon"), std::logic_error);
}

BOOST_AUTO_TEST_CASE(wordbook_add_translation_test)
{
  Wordbook wb("dictionary");
  wb.addWord("watermelon", "арбуз");
  wb.addAnotherTranslation("watermelon", "арбузик");
  BOOST_TEST(wb.getWord("watermelon").getTranslations().size() == 2);
}

BOOST_AUTO_TEST_CASE(wordbook_add_translation_missing_word_test)
{
  Wordbook wb("dictionary");
  BOOST_CHECK_THROW(wb.addAnotherTranslation("watermelon", "арбузик"), std::logic_error);
}

BOOST_AUTO_TEST_CASE(wordbook_add_interpretation_test)
{
  Wordbook wb("dictionary");
  wb.addWord("watermelon", "арбуз");
  wb.addInterpretation("watermelon", "большая зелёная ягода");
  BOOST_TEST(wb.getWord("watermelon").hasInterpretation());
}

BOOST_AUTO_TEST_CASE(wordbook_remove_interpretation_test)
{
  Wordbook wb("dictionary");
  wb.addWord("watermelon", "арбуз");
  wb.addInterpretation("watermelon", "ягода");
  wb.removeInterpretation("watermelon");
  BOOST_TEST(!wb.getWord("watermelon").hasInterpretation());
}

BOOST_AUTO_TEST_CASE(wordbook_assign_part_of_speech_test)
{
  Wordbook wb("dictionary");
  wb.addWord("watermelon", "арбуз");
  wb.assignPartOfSpeech("watermelon", "noun");
  BOOST_TEST(wb.getWord("watermelon").getPartOfSpeech() == "noun");
}

BOOST_AUTO_TEST_CASE(wordbook_get_word_test)
{
  Wordbook wb("dictionary");
  wb.addWord("apple", "яблоко");

  BOOST_TEST(wb.getWord("apple").hasTranslation("яблоко"));
}

BOOST_AUTO_TEST_CASE(wordbook_has_word_test)
{
  Wordbook wb("dictionary");
  BOOST_TEST(!wb.hasWord("apple"));
  wb.addWord("apple", "яблоко");
  BOOST_TEST(wb.hasWord("apple"));
}


