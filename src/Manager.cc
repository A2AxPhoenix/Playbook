#include "Manager.h"
#include <cstdint>
#include <stdexcept>
#include <string>
using M = Manager;

M::Manager() {
  name = "DEFAULT";
  placement = 1;
  wins = 1;
  ties = 1;
  losses = 1;
  pointsFor = 1;
  pointsAgainst = 1;
  differential = 1;
}
M::Manager(std::string newName) {
  name = newName;
  placement = 1;
  wins = 1;
  ties = 1;
  losses = 1;
  pointsFor = 1;
  pointsAgainst = 1;
  differential = 1;
}
M::Manager(std::string newName, uint8_t newPlacement, uint8_t newWins,
           uint8_t newTies, uint8_t newLosses) {
  name = newName;
  placement = newPlacement;
  wins = newWins;
  ties = newTies;
  losses = newLosses;
  pointsFor = 1;
  pointsAgainst = 1;
  differential = 1;
}

// Returns the current name of the manager in the League
// Returned as a std::string
// Example:
//     Manager m;
//     std::string manName = m.get_name();
//     std::cout << "Manager name is " << manName << ".\n";
std::string M::get_name() const { return name; }
// Returns the current place of the manager in the League
// Returned as a uint8_t
// Example:
//     Manager m;
//     uint8_t placer = m.get_placement();
//     std::cout << "Manager is placed " << placer << "\n";
uint8_t M::get_placement() const { return placement; }
// Returns the current wins of the manager
// Returned as a uint8_t
// Example:
//     Manager m;
//     uint8_t curWins = m.get_wins();
//     std::cout << "Wins: " << curWins << "\n";
uint8_t M::get_wins() const { return wins; }
// Returns the current ties of the manager
// Returned as a uint8_t
// Example:
//     Manager m;
//     uint8_t curTies = m.get_ties();
//     std::cout << "Ties: " << curTies << "\n";
uint8_t M::get_ties() const { return ties; }
// Returns the current losses of the manager
// Returned as a uint8_t
// Example:
//     Manager m;
//     uint8_t curLosses = m.get_losses();
//     std::cout << "Losses: " << curLosses << "\n";
uint8_t M::get_losses() const { return losses; }
// Returns the current points the manager's team scored in the league
// Returned as a uint16_t
// Example:
//     Manager m;
//     uint16_t curPointsFor = m.get_pointsFor();
//     std::cout << "Points for: " << curPointsFor << "\n";
uint16_t M::get_pointsFor() const { return pointsFor; }
// Returns the current points the manager's team has been scored
// against in the league
// Returned as a uint16_t
// Example:
//     Manager m;
//     uint16_t curPointsAgainst = m.get_pointsAgainst();
//     std::cout << "Points Against: " << curPointsAgainst << "\n";
uint16_t M::get_pointsAgainst() const { return pointsAgainst; }
// Returns the current point differntial of the manager
// Point differential formula: pointsFor - pointsAgainst
// Returned as an int16_t
// Example:
//     Manager m;
//     uint16_t curDiff = m.get_differential();
//     std::cout << "Differential: " << curDiff << "\n";
int16_t M::get_differential() const { return differential; }

bool M::has_commissioner() const { return isCommissioner; }

// Sets the name to a valid STL sring
// Strings can legitimately be anything for the manager's name
// Example:
//     std::string newManagerName = "Pete Carroll";
//     Manager m;
//     m.set_name(newManagerName); // Manager's name is now "Pete Carroll"
//     std::cout << "Manager Name: " << m.get
void M::set_name(std::string newName) { name = newName; }
// Sets the placement to a value between 1 - (UINT8_MAX - 1)
// Values set to 0 or UINT8_MAX throw errors to stop overflow
// and underflow errors.
// Example:
//     Manager m;
//     m.set_placement(10); // GOOD
//     m.set_placement(0); // BAD; cannot be placed 0
//     m.set_placement(255); // BAD; cannot be placed 255
//     m.set_placement(-1); // BAD; underflow error
//     m.set_placement(1'000); // BAD; overflow error
void M::set_placement(uint8_t newPlacement) {
  if (newPlacement >= UINT8_MAX) {
    throw std::runtime_error(
        "Invalid value for placement. Potential overflow error.\nPassed in " +
        std::to_string(newPlacement) + ".\nMaximum uint8_t size is " +
        std::to_string(UINT8_MAX) + ".\n");
  }
  if (newPlacement == 0) {
    throw std::runtime_error(
        "Invalid value for placement. Potential underflow error.\nPassed in " +
        std::to_string(newPlacement) + ".\nRange of uint8_t is 0 - " +
        std::to_string(UINT8_MAX) + ".\n");
  }
  placement = newPlacement;
}
// Sets the wins to a value between 0 - (UINT8_MAX - 1)
// Values set to UINT8_MAX throw errors to stop overflow
// and underflow errors.
// Example:
//     Manager m;
//     m.set_wins(8); // GOOD
//     m.set_wins(0); // GOOD
//     m.set_wins(255); // BAD; Potential overflow error
//     m.set_wins(-10); // BAD; underflow error
//     m.set_wins(1'000'000); // BAD; overflow error
void M::set_wins(uint8_t newWins) {
  if (newWins >= UINT8_MAX) {
    throw std::runtime_error(
        "Invalid value for wins. Potential overflow error.\nPassed in " +
        std::to_string(newWins) + ".\nMaximum uint8_t size is " +
        std::to_string(UINT8_MAX) + ".\n");
  }
  wins = newWins;
}
// Sets the ties to a value between 0 - (UINT8_MAX - 1)
// Values set to UINT8_MAX throw errors to stop overflow
// and underflow errors.
// Example:
//     Manager m;
//     m.set_ties(3); // GOOD
//     m.set_ties(0); // GOOD
//     m.set_ties(255); // BAD; Potential overflow error
//     m.set_ties(-99); // BAD; underflow error
//     m.set_ties(69420); // BAD; overflow error
void M::set_ties(uint8_t newTies) {
  if (newTies >= UINT8_MAX) {
    throw std::runtime_error(
        "Invalid value for ties. Potential overflow error.\nPassed in " +
        std::to_string(newTies) + ".\nMaximum uint8_t size is " +
        std::to_string(UINT8_MAX) + ".\n");
  }
  ties = newTies;
}
void M::set_losses(uint8_t newLosses) { losses = newLosses; }
void M::set_pointsFor(uint16_t newPointsFor) { pointsFor = newPointsFor; }
void M::set_pointsAgainst(uint16_t newPointsAgainst) {
  pointsAgainst = newPointsAgainst;
}
void M::set_differential(int16_t newDifferential) {
  differential = newDifferential;
}
void M::remove_player(const Player &id) { roster.erase(id); }
void M::add_player(const Player &id) { roster.insert(id); }

void M::set_commissioner(bool isCommissioner) {
  this->isCommissioner = isCommissioner;
}

bool M::operator<(const Manager &m) const { return m.wins < wins; }
bool M::operator==(const Manager &m) const { return m.wins == wins; }
Manager &M::operator[](Manager &m) { return m; }
