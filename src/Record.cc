#include "Record.h"
#include <climits>
#include <cmath>
#include <cstdint>
#include <stdexcept>

Record::Record(int newWins, int newLosses, int newTies) {
  if (newWins < 0)
    throw std::invalid_argument("Wins cannot be negative. You entered " +
                                std::to_string(newWins) +
                                " as the argument.\n");
  if (newLosses < 0)
    throw std::invalid_argument("Losses cannot be negative. You entered " +
                                std::to_string(newLosses) +
                                " as the argument.\n");
  if (newTies < 0)
    throw std::invalid_argument("Ties cannot be negative. You entered " +
                                std::to_string(newTies) +
                                " as the argument.\n");

  win = newWins;
  loss = newLosses;
  draw = newTies;
}

int Record::wins() const noexcept { return win; }
int Record::losses() const noexcept { return loss; }
int Record::ties() const noexcept { return draw; }
int Record::gamesPlayed() const {
  uint64_t totalGames = static_cast<uint64_t>(win) + loss + draw;
  if (totalGames > INT_MAX) {
    throw std::overflow_error("Total games played exceeds INT_MAX.\n");
  }
  return static_cast<int>(totalGames);
}
double Record::winPercentage() const {
  constexpr double ROUNDING_FACTOR = 1000; // Round to 3 decimal places
  constexpr double TIE_WEIGHT = 0.5; // Ties count as half a win and half a loss
  if (gamesPlayed() == 0)
    return 1.0; // A 0-0-0 record is considered a perfect record, so return 1.0
  else {
    double value = ((wins() + (TIE_WEIGHT * ties())) / gamesPlayed());
    return std::round(value * ROUNDING_FACTOR) /
           ROUNDING_FACTOR; // Return as the sports industry standard of 3
                            // decimal places
  }
}

void Record::addWin() {
  if (win == INT_MAX)
    throw std::overflow_error("Wins cannot exceed INT_MAX.\n");
  win++;
}

void Record::addLoss() {
  if (loss == INT_MAX)
    throw std::overflow_error("Losses cannot exceed INT_MAX.\n");
  loss++;
}

void Record::addTie() {
  if (draw == INT_MAX)
    throw std::overflow_error("Ties cannot exceed INT_MAX.\n");
  draw++;
}

void Record::removeWin() {
  if (win == 0)
    throw std::underflow_error("Wins cannot be less than 0.\n");
  win--;
}

void Record::removeLoss() {
  if (loss == 0)
    throw std::underflow_error("Losses cannot be less than 0.\n");
  loss--;
}

void Record::removeTie() {
  if (draw == 0)
    throw std::underflow_error("Ties cannot be less than 0.\n");
  draw--;
}
