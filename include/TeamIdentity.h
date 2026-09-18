#ifndef TEAM_IDENTITY_H
#define TEAM_IDENTITY_H

#include <string>

class TeamIdentity {
private:
  std::string marketName_;
  std::string nickname_;

public:
  TeamIdentity() = delete;
  TeamIdentity(std::string newMarketName, std::string newNickname);

  [[nodiscard]] const std::string &marketName() const noexcept;
  [[nodiscard]] const std::string &nickname() const noexcept;
  [[nodiscard]] std::string fullTeamName() const;
};

#endif
