#include "Record.h"
#include <gtest/gtest.h>
#include <stdexcept>

TEST(RecordCreation, DefaultConstructor) { // Test 1
  Record record;
  EXPECT_EQ(0, record.wins());
  EXPECT_EQ(0, record.losses());
  EXPECT_EQ(0, record.ties());
}
TEST(RecordCreation, ParameterizedConstructor) { // Test 2
  Record record(5, 2, 1);
  EXPECT_EQ(5, record.wins());
  EXPECT_EQ(2, record.losses());
  EXPECT_EQ(1, record.ties());
}

TEST(RecordCreation, RejectsNegWinsCSTOR) { // Test 3
  EXPECT_THROW((Record{-1, 0, 0}), std::invalid_argument);
}
TEST(RecordCreation, RejectsNegLossesCSTOR) { // Test 4
  EXPECT_THROW((Record{0, -1, 0}), std::invalid_argument);
}
TEST(RecordCreation, RejectsNegTiesCSTOR) { // Test 5
  EXPECT_THROW((Record{0, 0, -1}), std::invalid_argument);
}

TEST(RecordMutation, AddWinToRecord) { // Test 6
  Record record;
  Record record2(INT_MAX - 1, 0, 0);
  EXPECT_EQ(0, record.wins());
  record.addWin();
  EXPECT_EQ(1, record.wins());
  record2.addWin();
  EXPECT_EQ(INT_MAX, record2.wins());
}
TEST(RecordMutation, AddLossToRecord) { // Test 7
  Record record;
  Record record2(0, INT_MAX - 1, 0);
  EXPECT_EQ(0, record.losses());
  record.addLoss();
  EXPECT_EQ(1, record.losses());
  record2.addLoss();
  EXPECT_EQ(INT_MAX, record2.losses());
}
TEST(RecordMutation, AddTieToRecord) { // Test 8
  Record record;
  Record record2(0, 0, INT_MAX - 1);
  EXPECT_EQ(0, record.ties());
  record.addTie();
  EXPECT_EQ(1, record.ties());
  record2.addTie();
  EXPECT_EQ(INT_MAX, record2.ties());
}
TEST(RecordMutation, RemoveWinFromRecord) { // Test 9
  Record record(1, 0, 0);
  EXPECT_EQ(1, record.wins());
  record.removeWin();
  EXPECT_EQ(0, record.wins());
}
TEST(RecordMutation, RemoveLossFromRecord) { // Test 10
  Record record(0, 1, 0);
  EXPECT_EQ(1, record.losses());
  record.removeLoss();
  EXPECT_EQ(0, record.losses());
}
TEST(RecordMutation, RemoveTieFromRecord) { // Test 11
  Record record(0, 0, 1);
  EXPECT_EQ(1, record.ties());
  record.removeTie();
  EXPECT_EQ(0, record.ties());
}

TEST(RecordMutation, ThrowOnOverflowWins) { // Test 12
  Record record(INT_MAX, 0, 0);
  EXPECT_THROW(record.addWin(), std::overflow_error);
}
TEST(RecordMutation, ThrowOnOverflowLosses) { // Test 13
  Record record(0, INT_MAX, 0);
  EXPECT_THROW(record.addLoss(), std::overflow_error);
}
TEST(RecordMutation, ThrowOnOverflowTies) { // Test 14
  Record record(0, 0, INT_MAX);
  EXPECT_THROW(record.addTie(), std::overflow_error);
}
TEST(RecordMutation, ThrowOnUnderflowWins) { // Test 15
  Record record(0, 0, 0);
  EXPECT_THROW(record.removeWin(), std::underflow_error);
}
TEST(RecordMutation, ThrowOnUnderflowLosses) { // Test 16
  Record record(0, 0, 0);
  EXPECT_THROW(record.removeLoss(), std::underflow_error);
}
TEST(RecordMutation, ThrowOnUnderflowTies) { // Test 17
  Record record(0, 0, 0);
  EXPECT_THROW(record.removeTie(), std::underflow_error);
}

TEST(RecordObserver, CheckGamesPlayedNormal) { // Test 18
  Record record;
  Record record2(3, 2, 1);
  Record record3(10, 10, 0);
  Record record4(1, 2, 3);
  Record record5(8, 9, 0);
  EXPECT_EQ(0, record.gamesPlayed());
  EXPECT_EQ(6, record2.gamesPlayed());
  EXPECT_EQ(20, record3.gamesPlayed());
  EXPECT_EQ(6, record4.gamesPlayed());
  EXPECT_EQ(17, record5.gamesPlayed());
}
TEST(RecordObserver, CheckGamesPlayedAtIntMax) { // Test 19
  Record record(INT_MAX, 0, 0);
  Record record2(0, INT_MAX, 0);
  Record record3(0, 0, INT_MAX);
  Record record4(INT_MAX - 2, 1, 1);
  Record record5(1, INT_MAX - 2, 1);
  Record record6(1, 1, INT_MAX - 2);
  EXPECT_EQ(INT_MAX, record.gamesPlayed());
  EXPECT_EQ(INT_MAX, record2.gamesPlayed());
  EXPECT_EQ(INT_MAX, record3.gamesPlayed());
  EXPECT_EQ(INT_MAX, record4.gamesPlayed());
  EXPECT_EQ(INT_MAX, record5.gamesPlayed());
  EXPECT_EQ(INT_MAX, record6.gamesPlayed());
}

TEST(RecordObserver, CheckGamesPlayedThrows) { // Test 20
  Record record(INT_MAX, 1, 0);
  Record record2(1, INT_MAX, 0);
  Record record3(0, 1, INT_MAX);
  EXPECT_THROW(int r = record.gamesPlayed(), std::overflow_error);
  EXPECT_THROW(int r = record2.gamesPlayed(), std::overflow_error);
  EXPECT_THROW(int r = record3.gamesPlayed(), std::overflow_error);
}

TEST(RecordObserver, CalculateWinPercentage) { // Test 21
  Record record;
  Record record2(3, 2, 1);
  Record record3(10, 10, 0);
  Record record4(1, 2, 3);
  Record record5(8, 9, 0);
  Record record6(0, 0, 1);
  EXPECT_DOUBLE_EQ(1.000, record.winPercentage());
  EXPECT_DOUBLE_EQ(0.583, record2.winPercentage());
  EXPECT_DOUBLE_EQ(0.500, record3.winPercentage());
  EXPECT_DOUBLE_EQ(0.417, record4.winPercentage());
  EXPECT_DOUBLE_EQ(0.471, record5.winPercentage());
  EXPECT_DOUBLE_EQ(0.500, record6.winPercentage());
}
TEST(RecordObserver, CalculateWinPercentageThrows) { // Test 22
  Record record(INT_MAX, 1, 0);
  Record record2(1, INT_MAX, 0);
  Record record3(0, 1, INT_MAX);
  EXPECT_THROW(double r = record.winPercentage(), std::overflow_error);
  EXPECT_THROW(double r = record2.winPercentage(), std::overflow_error);
  EXPECT_THROW(double r = record3.winPercentage(), std::overflow_error);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
