#include "Manager.h" // IWYU pragma: keep
#include "Player.h"  // IWYU pragma: keep
#include "ScoringRules.h"
#include "StatLine.h"
#include <algorithm> // IWYU pragma: keep
#include <cassert>
#include <cmath> // IWYU pragma: keep
#include <cstdlib>
#include <fstream>  // IWYU pragma: keep
#include <iostream> // IWYU pragma: keep
#include <vector>   // IWYU pragma: keep
using namespace std;

int main() {
  Scoring_Rules rules;
  StatLine dst{};
  dst.isDST = true;
  dst.totalPointsAllowed = 0;
  dst.sacks = 3;
  assert(rules.compute(dst) == 13 && "DST points does not equal expected\n");
  cout << "DST pts: " << rules.compute(dst) << endl;
}
