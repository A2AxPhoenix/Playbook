#include "TeamIdentity.h"
#include "utils/StringUtils.h" // IWYU pragma: keep - Quick fix for missing include
#include <gtest/gtest.h>
#include <stdexcept>

TEST(TeamIdentityCreation, NormalCreation) { // Test 1
  TeamIdentity team("Seattle", "Seahawks");
  EXPECT_EQ("Seattle", team.marketName());
  EXPECT_EQ("Seahawks", team.nickname());
}

TEST(TeamIdentityCreation, WhitespaceTrimming) { // Test 2
  TeamIdentity team("  Seattle  ", "  Seahawks  ");
  TeamIdentity team2("New England       ", "Patriots      ");
  TeamIdentity team3("     Los Angeles", "     Chargers");
  TeamIdentity team4("Cincinatti     ", "     Bengals");
  TeamIdentity team5("     Baltimore", "Ravens     ");
  TeamIdentity team6("\tMiami\n", "\tDolphins\n");
  EXPECT_EQ("Seattle", team.marketName());
  EXPECT_EQ("Seahawks", team.nickname());
  EXPECT_EQ("New England", team2.marketName());
  EXPECT_EQ("Patriots", team2.nickname());
  EXPECT_EQ("Los Angeles", team3.marketName());
  EXPECT_EQ("Chargers", team3.nickname());
  EXPECT_EQ("Cincinatti", team4.marketName());
  EXPECT_EQ("Bengals", team4.nickname());
  EXPECT_EQ("Baltimore", team5.marketName());
  EXPECT_EQ("Ravens", team5.nickname());
  EXPECT_EQ("Miami", team6.marketName());
  EXPECT_EQ("Dolphins", team6.nickname());
}

TEST(TeamIdentityCreation, ThrowOnPartialCreation) { // Test 3
  EXPECT_THROW(TeamIdentity team("Seattle", ""), std::invalid_argument);
  EXPECT_THROW(TeamIdentity team("", "Seahawks"), std::invalid_argument);
}

TEST(TeamIdentityCreation, ThrowOnEmptyCreation) { // Test 4
  EXPECT_THROW(TeamIdentity team("", ""), std::invalid_argument);
  EXPECT_THROW(TeamIdentity team2("\t", "\n"), std::invalid_argument);
  EXPECT_THROW(TeamIdentity team3("\t", "\n\n"), std::invalid_argument);
}

TEST(TeamIdentityCreation, ThrowOnWhitespaceOnlyCreation) { // Test 5
  EXPECT_THROW(TeamIdentity team("   ", "Seahawks"), std::invalid_argument);
  EXPECT_THROW(TeamIdentity team("Seattle", "   "), std::invalid_argument);
  EXPECT_THROW(TeamIdentity team("   ", "   "), std::invalid_argument);
}

TEST(TeamIdentityCreation, ThrowOnInvalidInternalWhitespaceCreation) { // Test 6
  EXPECT_THROW(TeamIdentity team("New\tEngland", "Patriots"),
               std::invalid_argument);
  EXPECT_THROW(TeamIdentity team("Kansas\nCity", "Chiefs"),
               std::invalid_argument);
}

TEST(TeamIdentityObserver, returnMarketName) { // Test 7
  TeamIdentity team("Arizona", "Cardinals");
  TeamIdentity team2("Indianapolis", "Colts");
  TeamIdentity team3("New York", "Giants");
  TeamIdentity team4("\t\tKansas City\n\n", "\t\tChiefs\n\n");
  EXPECT_EQ("Arizona", team.marketName());
  EXPECT_EQ("Indianapolis", team2.marketName());
  EXPECT_EQ("New York", team3.marketName());
  EXPECT_EQ("Kansas City", team4.marketName());
}

TEST(TeamIdentityObserver, returnNickname) { // Test 8
  TeamIdentity team("Arizona", "Cardinals");
  TeamIdentity team2("Indianapolis", "Colts");
  TeamIdentity team3("New York", "Giants");
  TeamIdentity team4("\t\tLas Vegas\n\n", "\t\tRaiders\n\n");
  EXPECT_EQ("Cardinals", team.nickname());
  EXPECT_EQ("Colts", team2.nickname());
  EXPECT_EQ("Giants", team3.nickname());
  EXPECT_EQ("Raiders", team4.nickname());
}

TEST(TeamIdentityObserver, returnTeamName) { // Test 9
  TeamIdentity team("Pittsburgh", "Steelers");
  TeamIdentity team2("Green Bay", "Packers");
  TeamIdentity team3("Dallas", "Cowboys");
  TeamIdentity team4("\t\tNew Orleans\n\n", "\t\tSaints\n\n");
  EXPECT_EQ("Pittsburgh Steelers", team.fullTeamName());
  EXPECT_EQ("Green Bay Packers", team2.fullTeamName());
  EXPECT_EQ("Dallas Cowboys", team3.fullTeamName());
  EXPECT_EQ("New Orleans Saints", team4.fullTeamName());
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
