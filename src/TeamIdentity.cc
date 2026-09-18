#include "TeamIdentity.h"
#include <stdexcept>

TeamIdentity::TeamIdentity(std::string newMarketName, std::string newNickname) {
  if (newMarketName.empty()) {
    throw std::invalid_argument("Market name cannot be empty.\n");
  }
  if (newNickname.empty()) {
    throw std::invalid_argument("Nickname cannot be empty.\n");
  }
  marketName_ = newMarketName;
  nickname_ = newNickname;
}

const std::string &TeamIdentity::marketName() const noexcept {
  return marketName_;
}
const std::string &TeamIdentity::nickname() const noexcept { return nickname_; }
std::string TeamIdentity::fullTeamName() const {
  return marketName_ + " " + nickname_;
}
