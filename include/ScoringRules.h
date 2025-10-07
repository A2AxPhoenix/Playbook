#ifndef SCORING_RULES_H
#define SCORING_RULES_H

#include "StatLine.h"

struct Scoring_Rules {
  // OFFENSE:
  // QB RULES
  static constexpr double PASSING_YD = 0.04; // 1 point per 25 yards
  static constexpr double PASSING_TD = 6;    // 6 Points per Passing TD
  static constexpr double PASSING_INT = -2;  // -2 for each interception thrown
  static constexpr double THREE_HUNDRED_BONUS = 1; // +1 if thrown 300-399 yards
  static constexpr double FOUR_HUNDRED_BONUS = 1;  // +1 if thrown 400+ yards
  static constexpr double FORTY_YD_PASSING_TD_BONUS =
      1; // +1 if thrown 40+ yard TD
  static constexpr double FIFTY_YD_PASSING_TD_BONUS =
      1; // +1 if thrown 50+ yard TD

  // RB RULES
  static constexpr double RUSHING_YD = 0.1; // 1 point per 10 yards
  static constexpr double RUSHING_TD = 6;   // 6 points per Rushing TD
  static constexpr double FORTY_YD_RUSHING_TD_BONUS =
      1; // 1 point if rushing 40+ yard TD
  static constexpr double FIFTY_YD_RUSHING_TD_BONUS =
      1; // 1 point if rushing 50+ yard TD

  // WR RULES
  static constexpr double RECEPTION = 1;      // Caught a pass? +1 point
  static constexpr double RECEIVING_YD = 0.1; // 1 point per 10 yards
  static constexpr double RECEIVING_TD = 6;   // 6 Points per Receiving TD
  static constexpr double FORTY_YD_RECEIVING_TD_BONUS =
      1; // 1 point if caught 40+ yard TD
  static constexpr double FIFTY_YD_RECEIVING_TD_BONUS =
      1; // 1 point if caught 50+ yard TD

  // General Rules on Offense
  static constexpr double ONE_HUNDRED_BONUS =
      1; // +1 if 100-199 total rushing/receiving yards
  static constexpr double TWO_HUNDRED_BONUS =
      2; // +2 if 200+ total yards for WR/RB
  static constexpr double KO_PUNT_RETURN_TD =
      6;                                 // 6 points for Kickoff/Punt return TD
  static constexpr double FUMBLE_TD = 6; // 6 points for Fumble return TD
  static constexpr double FUMBLE = -2;   // Fumbled? -2 Points
  static constexpr double TWO_PT_CONVERSION = 2; // Two point conversion

  // KICKING

  static constexpr double PAT = 1;   // Point After Touchdown (extra point)
  static constexpr double FG_10 = 3; // +3 FG 10-19
  static constexpr double FG_20 = 3; // +3 FG 20-29
  static constexpr double FG_30 = 3; // +3 FG 30-39
  static constexpr double FG_40 = 3; // +3 FG 40-49
  static constexpr double FG_50 = 5; // +5 FG 50+

  // DEFENSE RULES
  static constexpr double SACK = 1;            // Sack = 1 point
  static constexpr double INT_RECOVERY = 2;    // INT = 2 points
  static constexpr double FUMBLE_RECOVERY = 2; // Fumble Recovery = 2 points
  static constexpr double FUMBLE_FORCED = 1;   // Fumble forced = 1 point
  static constexpr double SAFETY = 2;          // Safety = 2 points
  static constexpr double DEFENSE_TD = 6;      // Defensive TD = 6 points
  static constexpr double DEFENSE_KICK_RETURN_TD =
      6;                                     // Defensive Kick Return (Punt/KO)
  static constexpr double PA_ZERO = 10;      // 0 points allowed = 10 points
  static constexpr double PA_ONE_TO_SIX = 7; // 1-6 PA = 7 points
  static constexpr double PA_SEVEN_TO_THIRTEEN = 4;  // 7-13 PA = 4 points
  static constexpr double PA_FOURTEEN_TO_TWENTY = 1; // 14-20 PA = 1 point
  static constexpr double PA_TWENTYONE_TO_TWENTYSEVEN =
      0; // 21-27 PA = 0 points
  static constexpr double PA_TWENTYEIGHT_TO_THIRTYFIVE =
      -1; // 28-35 PA = -1 point
  static constexpr double PA_THIRTYFIVE_PLUS =
      -4; // 35+ Points Allowed = -4 points
  static constexpr double DEFENSE_TWO_POINT_RETURN =
      2; // Defensive Two Point = 2 points

  bool allowsFractional =
      true; // Allow fraction points (Ex. 2.24 points over 2 points)
  bool allowsNegative = true; // Allow negative points (0 is minimum if false)

  // Compute fantasty points
  double compute(const StatLine &s) const;
};

#endif
