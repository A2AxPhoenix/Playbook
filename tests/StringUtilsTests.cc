#include "utils/StringUtils.h"
#include <gtest/gtest.h>

TEST(StringUtilsTests, EmptyStringTest) { // Test 1
  const std::string input = "";
  const std::string expected = "";
  EXPECT_EQ(playbook::utils::trim(input), expected);
}

TEST(StringUtilsTests, SpacesOnlyStringTest) { // Test 2
  const std::string input = "   ";
  const std::string expected = "";
  EXPECT_EQ(playbook::utils::trim(input), expected);
}

TEST(StringUtilsTests, WhiteSpaceOnlyStringTest) { // Test 3
  const std::string input = "\t  \t";
  const std::string input2 = "\n \n";
  const std::string input3 = "\r\n \r\n";
  const std::string input4 = "\r \r";
  const std::string input5 = "\t\n  \t\n";
  const std::string input6 = "\f\n  \t\v";
  const std::string input7 = "\t\r  \v\n";
  const std::string input8 = "\t\f  \t\r";
  const std::string input9 = "\n\f  \r\t";
  const std::string expected = "";
  EXPECT_EQ(playbook::utils::trim(input), expected);
  EXPECT_EQ(playbook::utils::trim(input2), expected);
  EXPECT_EQ(playbook::utils::trim(input3), expected);
  EXPECT_EQ(playbook::utils::trim(input4), expected);
  EXPECT_EQ(playbook::utils::trim(input5), expected);
  EXPECT_EQ(playbook::utils::trim(input6), expected);
  EXPECT_EQ(playbook::utils::trim(input7), expected);
  EXPECT_EQ(playbook::utils::trim(input8), expected);
  EXPECT_EQ(playbook::utils::trim(input9), expected);
}

TEST(StringUtilsTests, LeadingAndTrailingSpacesTest) { // Test 4
  const std::string input = "   Hello, World!   ";
  const std::string expected = "Hello, World!";
  EXPECT_EQ(playbook::utils::trim(input), expected);
}

TEST(StringUtilsTests, LeadingAndTrailingTabsTest) { // Test 5
  const std::string input = "\t\tHello, World!\t\t";
  const std::string expected = "Hello, World!";
  EXPECT_EQ(playbook::utils::trim(input), expected);
}

TEST(StringUtilsTests, LeadingAndTrailingNewLinesTest) { // Test 6
  const std::string input = "\n\nHello, World!\n\n";
  const std::string expected = "Hello, World!";
  EXPECT_EQ(playbook::utils::trim(input), expected);
}

TEST(StringUtilsTests, LeadingAndTrailingMixedWhitespaceTest) { // Test 7
  const std::string input = " \t\nHello, World!\n\t ";
  const std::string expected = "Hello, World!";
  EXPECT_EQ(playbook::utils::trim(input), expected);
}

TEST(StringUtilsTests, NoLeadingOrTrailingWhitespaceTest) { // Test 8
  const std::string input = "Hello, World!";
  const std::string expected = "Hello, World!";
  EXPECT_EQ(playbook::utils::trim(input), expected);
}

TEST(StringUtilsTests, OnlyLeadingWhitespaceTest) { // Test 9
  const std::string input = "   Hello, World!";
  const std::string expected = "Hello, World!";
  EXPECT_EQ(playbook::utils::trim(input), expected);
}

TEST(StringUtilsTests, OnlyTrailingWhitespaceTest) { // Test 10
  const std::string input = "Hello, World!   ";
  const std::string expected = "Hello, World!";
  EXPECT_EQ(playbook::utils::trim(input), expected);
}

TEST(StringUtilsTests,
     LeadingAndTrailingWhitespaceWithSpecialCharactersTest) { // Test 11
  const std::string input =
      " \t\nHello, World!@#$%^&*()_+-=[]{}|;':\",./<>?\n\t ";
  const std::string expected = "Hello, World!@#$%^&*()_+-=[]{}|;':\",./<>?";
  EXPECT_EQ(playbook::utils::trim(input), expected);
}

TEST(StringUtilsTests,
     LeadingAndTrailingWhitespaceWithUnicodeCharactersTest) { // Test 12
  const std::string input = " \t\nHello, 世界! こんにちは！\n\t ";
  const std::string expected = "Hello, 世界! こんにちは！";
  EXPECT_EQ(playbook::utils::trim(input), expected);
}

TEST(StringUtilsTests, LeadingAndTrailingWhitespaceWithEmojiTest) { // Test 13
  const std::string input = " \t\nHello, World! 😀😃😄😁\n\t ";
  const std::string expected = "Hello, World! 😀😃😄😁";
  EXPECT_EQ(playbook::utils::trim(input), expected);
}

TEST(StringUtilsTests,
     LeadingAndTrailingWhitespaceWithMixedCharactersTest) { // Test 14
  const std::string input =
      " \t\nHello, 世界! 😀😃😄😁@#$%^&*()_+-=[]{}|;':\",./<>?\n\t ";
  const std::string expected =
      "Hello, 世界! 😀😃😄😁@#$%^&*()_+-=[]{}|;':\",./<>?";
  EXPECT_EQ(playbook::utils::trim(input), expected);
}

TEST(StringUtilsTests, PreservingInternalWhitespaceTest) { // Test 15
  const std::string input = "   Hello,   World!   ";
  const std::string input2 = "\t   Hello,\tWorld!   \t";
  const std::string input3 = "\n   Hello,\nWorld!   \n";
  const std::string input4 = "\t\n\f\v\r   Hello,\t\nWorld!   \t\n\f\v\r";
  const std::string expected = "Hello,   World!";
  const std::string expected2 = "Hello,\tWorld!";
  const std::string expected3 = "Hello,\nWorld!";
  const std::string expected4 = "Hello,\t\nWorld!";
  EXPECT_EQ(playbook::utils::trim(input), expected);
  EXPECT_EQ(playbook::utils::trim(input2), expected2);
  EXPECT_EQ(playbook::utils::trim(input3), expected3);
  EXPECT_EQ(playbook::utils::trim(input4), expected4);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
