#ifndef RECORD_H
#define RECORD_H

class Record {
private:
  int win{0};
  int loss{0};
  int draw{0}; // Intentionally named draw to avoid issues with std::tie

public:
  Record() = default;
  Record(int newWins, int newLosses, int newTies);

  // Observers
  [[nodiscard]] int wins() const noexcept;
  [[nodiscard]] int losses() const noexcept;
  [[nodiscard]] int ties() const noexcept;
  [[nodiscard]] int gamesPlayed() const;
  [[nodiscard]] double winPercentage() const;

  // Modifiers
  void addWin();
  void addLoss();
  void addTie();
  void removeWin();
  void removeLoss();
  void removeTie();
};

#endif
