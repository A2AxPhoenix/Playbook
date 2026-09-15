#ifndef NFLTEAM_H
#define NFLTEAM_H

#include <cstdint>
#include <string>

enum class Conference {
  AFC,
  NFC,
};

enum class Division {
  WEST,
  EAST,
  NORTH,
  SOUTH,
};

struct Location {
  std::string city;
  std::string state;
};

struct Alignment {
  Conference conference;
  Division division;
};

struct TeamRecord {
  uint8_t wins;
  uint8_t losses;
  uint8_t ties;
};

struct TeamStats {
  int32_t pointsFor;
  int32_t pointsAgainst;

  // Offensive stats
  int32_t passingYards;
  int32_t rushingYards;
  uint8_t passingTouchdowns;
  uint8_t rushingTouchdowns;
  uint8_t offensiveFumbles;
  uint8_t offensiveInterceptions;
  uint8_t sacksTaken;
  uint16_t sackYardsLost;

  // Defensive stats
  int32_t passingYardsAllowed;
  int32_t rushingYardsAllowed;
  uint8_t sacks;
  uint8_t interceptions;
  uint8_t fumbles;

  // Special teams stats
  uint8_t fieldGoalsMade;
  uint8_t fieldGoalsAttempted;
  uint8_t extraPointsMade;
  uint8_t extraPointsAttempted;
  uint8_t punts;
  uint8_t fairCatches;
  int32_t puntYards;
  int32_t puntReturnYards;
  uint8_t kickoffs;
  int32_t kickoffYards;
  int32_t kickReturnYards;
  int8_t longestFieldGoal;
  int8_t longestPunt;
  int8_t longestKickoffReturn;
  uint8_t puntReturnTouchdowns;
  uint8_t kickoffReturnTouchdowns;
};

class NFLTeam {
private:
  std::string teamName;
  Location location;
  Alignment alignment;
  std::string stadium;
  std::string headCoach;
  // TODO: vector<Player> roster; Player class will be implemented later
  TeamRecord record;
  TeamStats stats;

public:
  NFLTeam();
  NFLTeam(const std::string &newTeamName, const Location &newLocation,
          const Alignment &newAlignment, const std::string &newStadium,
          const std::string &newHeadCoach);

  // Getters
  std::string getTeamName() const;
  Location getLocation() const;
  Alignment getAlignment() const;
  std::string getStadium() const;
  std::string getHeadCoach() const;
  // TODO: Uncomment this when Player class is implemented
  // std::vector<Player> getRoster() const;
  TeamRecord getRecord() const;
  TeamStats getStats() const;

  // Setters

  // Sort and filter functions
};

#endif
