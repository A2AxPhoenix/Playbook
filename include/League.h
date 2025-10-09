#ifndef LEAGUE_H
#define LEAGUE_H

#include "Manager.h"
#include "ScoringRules.h"
#include <cstdint>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class League {
private:
  static constexpr uint8_t WEEKS_IN_SEASON = 18;
  struct Matchup {
    uint64_t id = 0;
    Manager *teamA = nullptr;
    Manager *teamB = nullptr;
    bool isConcluded = false;
    double teamAPts = 0.;
    double teamBPts = 0.;
  };
  std::string leagueName;
  Manager *commissioner;
  uint8_t currentWeek;
  Scoring_Rules ruleset;
  std::unordered_map<uint64_t, Manager *> managers;
  std::unordered_map<uint64_t, Matchup> managerSchedule;
  std::vector<std::vector<Matchup>> schedule{WEEKS_IN_SEASON + 1};

public:
  League() = delete;
  League(std::string newLeagueName, Manager *newCommissioner,
         uint8_t startingWeek);
  std::string get_leagueName() const;
  Manager *get_commissioner() const;
  uint8_t get_currentWeek() const;
  const std::unordered_map<uint64_t, Manager *> &get_managers() const;
  const std::vector<std::vector<Matchup>> &
  get_schedule(uint64_t managerID) const;
  std::unordered_set<Player> get_manager_roster(uint64_t managerID) const;
  std::unordered_map<uint64_t, Matchup> get_managers_schedule() const;
  // TODO: Give permissions for the Commissioner to modify more of the League
};
#endif
