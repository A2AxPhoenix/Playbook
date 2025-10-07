#include "Player.h"
using P = Player;

uint64_t P::get_playerID() const { return playerID; }
std::string P::get_playerName() const { return playerName; }
uint8_t P::get_playerJerseyNum() const { return playerJerseyNum; }

bool P::operator==(const Player &p) const noexcept {
  return playerID == p.playerID;
}
