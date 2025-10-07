#include "ScoringRules.h"
#include <algorithm>

// Defensive Score constants
const int TIER_ZERO = 0;
const int TIER_ONE = 6;
const int TIER_TWO = 13;
const int TIER_THREE = 20;
const int TIER_FOUR = 27;
const int TIER_FIVE = 35;
const int ONE_HUNDRED_YD = 100;
const int TWO_HUNDRED_YD = 200;
const int THREE_HUNDRED_YD = 300;
const int FOUR_HUNDRED_YD = 400;

static inline double points_allowed_compute(int pointsAllowed) {
  if (pointsAllowed == TIER_ZERO)
    return Scoring_Rules::PA_ZERO;
  else if (pointsAllowed > TIER_ZERO and pointsAllowed < TIER_ONE)
    return Scoring_Rules::PA_ONE_TO_SIX;
  else if (pointsAllowed > TIER_ONE and pointsAllowed < TIER_TWO)
    return Scoring_Rules::PA_SEVEN_TO_THIRTEEN;
  else if (pointsAllowed > TIER_TWO and pointsAllowed < TIER_THREE)
    return Scoring_Rules::PA_FOURTEEN_TO_TWENTY;
  else if (pointsAllowed > TIER_THREE and pointsAllowed < TIER_FOUR)
    return Scoring_Rules::PA_TWENTYONE_TO_TWENTYSEVEN;
  else if (pointsAllowed > TIER_FOUR and pointsAllowed < TIER_FIVE)
    return Scoring_Rules::PA_TWENTYEIGHT_TO_THIRTYFIVE;
  else
    return Scoring_Rules::PA_THIRTYFIVE_PLUS;
}

double Scoring_Rules::compute(const StatLine &s) const {
  double fantasyPts = 0.;
  if (s.isDST) {
    fantasyPts = points_allowed_compute(s.totalPointsAllowed);
    fantasyPts += s.sacks * SACK;
    fantasyPts += s.interceptions * INT_RECOVERY;
    fantasyPts += s.fumbleRecovery * FUMBLE_RECOVERY;
    fantasyPts += s.forcedFumble * FUMBLE_FORCED;
    fantasyPts += s.safeties * SAFETY;
    fantasyPts += s.defensiveTD * DEFENSE_TD;
    fantasyPts += s.returnTDs * DEFENSE_KICK_RETURN_TD;
    fantasyPts += s.totalTwoPointReturns * DEFENSE_TWO_POINT_RETURN;
  }
  // ================ QB Centered Stats ======================
  fantasyPts += s.passingYards * PASSING_YD;
  fantasyPts += s.passingTD * PASSING_TD;
  fantasyPts += s.passingINT * PASSING_INT;

  // ================ RB/WR Centered Stats ======================

  fantasyPts += s.rushingYards * RUSHING_YD;
  fantasyPts += s.rushingTD * RUSHING_TD;
  fantasyPts += s.receptions * RECEPTION;
  fantasyPts += s.receivingYards * RECEIVING_YD;
  fantasyPts += s.receivingTD * RECEIVING_TD;

  // ================ General Stats ======================

  fantasyPts += s.twoPointConv * TWO_PT_CONVERSION;
  fantasyPts += s.fumLost * FUMBLE;

  // ================ Bonus Stats ======================

  fantasyPts += s.fortyPassingTD * FORTY_YD_PASSING_TD_BONUS;
  fantasyPts += s.fiftyPassingTD * FIFTY_YD_PASSING_TD_BONUS;
  if (s.passingYards >= THREE_HUNDRED_YD and s.passingYards < FOUR_HUNDRED_YD)
    fantasyPts += THREE_HUNDRED_BONUS;
  if (s.passingYards >= FOUR_HUNDRED_YD)
    fantasyPts += FOUR_HUNDRED_BONUS;
  fantasyPts += s.fortyTD * FORTY_YD_RUSHING_TD_BONUS;
  fantasyPts += s.fortyTD * FORTY_YD_RECEIVING_TD_BONUS;
  if (s.rushingYards > ONE_HUNDRED_YD and s.rushingYards < TWO_HUNDRED_YD)
    fantasyPts += ONE_HUNDRED_BONUS;
  if (s.rushingYards >= TWO_HUNDRED_YD)
    fantasyPts += TWO_HUNDRED_BONUS;
  if (s.receivingYards > ONE_HUNDRED_YD and s.receivingYards < TWO_HUNDRED_YD)
    fantasyPts += ONE_HUNDRED_BONUS;
  if (s.receivingYards >= TWO_HUNDRED_YD)
    fantasyPts += TWO_HUNDRED_BONUS;

  fantasyPts += s.totalPATs * PAT;
  fantasyPts += s.fieldGoalTen * FG_10;
  fantasyPts += s.fieldGoalTwenty * FG_20;
  fantasyPts += s.fieldGoalThirty * FG_30;
  fantasyPts += s.fieldGoalForty * FG_40;
  fantasyPts += s.fieldGoalFifty * FG_50;

  if (!allowsNegative)
    fantasyPts = std::clamp(fantasyPts, 0.0, fantasyPts);
  if (!allowsFractional)
    return int(fantasyPts);
  return fantasyPts;
}
