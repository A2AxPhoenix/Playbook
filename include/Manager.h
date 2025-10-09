#ifndef MANAGER_H
#define MANAGER_H

#include "Player.h"
#include <cstdint>
#include <string>
#include <unordered_set>

class Manager {
private:
  uint64_t id;
  static uint64_t nextID;
  std::string name;
  uint8_t placement;
  uint8_t wins;
  uint8_t ties;
  uint8_t losses;
  uint16_t pointsFor;
  uint16_t pointsAgainst;
  int16_t differential;
  bool isCommissioner;
  std::unordered_set<Player> roster;

public:
  Manager();
  Manager(std::string newName);
  Manager(std::string newName, uint8_t newPlacement, uint8_t newWins,
          uint8_t newTies, uint8_t newLosses);

  uint64_t get_manager_id() const;
  std::string get_name() const;
  uint8_t get_placement() const;
  uint8_t get_wins() const;
  uint8_t get_ties() const;
  uint8_t get_losses() const;
  uint16_t get_pointsFor() const;
  uint16_t get_pointsAgainst() const;
  int16_t get_differential() const;
  bool has_commissioner() const;

  void set_manager_id(uint64_t newManID);
  void set_name(std::string newName);
  void set_placement(uint8_t newWins);
  void set_wins(uint8_t newWins);
  void set_ties(uint8_t newTies);
  void set_losses(uint8_t newLosses);
  void set_pointsFor(uint16_t newPointsFor);
  void set_pointsAgainst(uint16_t newPointsAgainst);
  void set_differential(int16_t newDifferential);
  void remove_player(const Player &id);
  void add_player(const Player &id);
  void set_commissioner(bool isCommissioner);

  bool operator<(const Manager &m) const;
  bool operator==(const Manager &m) const;
  Manager &operator[](Manager &m);
};

#endif
