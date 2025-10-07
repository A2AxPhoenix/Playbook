#ifndef PLAYER_H
#define PLAYER_H

#include "StatLine.h"
#include <functional>
#include <string>

class Player {
  uint64_t playerID;
  std::string playerName;
  uint8_t playerJerseyNum;
  StatLine fantasyStats;

public:
  uint64_t get_playerID() const;
  std::string get_playerName() const;
  uint8_t get_playerJerseyNum() const;

  bool operator==(const Player &p) const noexcept;
};

namespace std {
template <> struct hash<Player> {
  size_t operator()(const Player &p) const noexcept {
    return std::hash<uint64_t>{}(p.get_playerID());
  }
};
} // namespace std
#endif
