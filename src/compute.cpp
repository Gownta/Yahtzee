#include "compute.h"
#include "state.h"
#include "roll.h"
#include <map>

#include <iostream>

using namespace std;
/*
static map<pair<State, Roll>, double> table;

double compute(const State & state, const Roll & roll, int num_rolls) {
  if (state.all_used()) return 0;
  if (auto it = table.find(make_pair(state, roll))) return it->second;

  double best = 0;

  if (num_rolls == 3) {
    // no rerolling available
  }

  return 0;
}
*/
