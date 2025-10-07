#ifndef STATLINE_H
#define STATLINE_H

struct StatLine {
  bool isDST = false;
  // QB Stats:
  int passingYards = 0;   // total passing yards
  int passingTD = 0;      // total passing TDs
  int passingINT = 0;     // total passing interceptions
  int fortyPassingTD = 0; // total forty yard passing TDs
  int fiftyPassingTD = 0; // total fifty yard passing TDs

  // RB/WR Stats:
  int rushingYards = 0;   // total rushing yards
  int rushingTD = 0;      // total rushing TDs
  int receptions = 0;     // total receptions
  int receivingYards = 0; // total receiving yards
  int receivingTD = 0;    // total receiving TDs
  int fortyTD = 0;        // total forty yard rushing/receiving TDs
  int fiftyTD = 0;        // total fifty yard rushing/receiving TDs

  // General Stats:
  int twoPointConv = 0; // total two point conversions scored
  int fumLost = 0;      // total fumbles lost

  // Kicker Stats:
  int totalPATs = 0;       // total extra points kicked
  int fieldGoalTen = 0;    // total 10-19 yard FGs made
  int fieldGoalTwenty = 0; // total 20-29 yard FGs made
  int fieldGoalThirty = 0; // total 30-39 yard FGs made
  int fieldGoalForty = 0;  // total 40-49 yard FGs made
  int fieldGoalFifty = 0;  // total 50+ yard FGs made

  // Defense/ST Stats:
  int sacks = 0;                // total sacks
  int interceptions = 0;        // total interceptions
  int fumbleRecovery = 0;       // total fumbles recovered
  int forcedFumble = 0;         // total forced fumbles
  int safeties = 0;             // total safeties
  int defensiveTD = 0;          // total defensive TDs
  int returnTDs = 0;            // total return TDs (kickoff and punt)
  int totalPointsAllowed = 0;   // total points Allowed in game
  int totalTwoPointReturns = 0; // total two point conversion returns
};

#endif
