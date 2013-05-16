#include "score.h"

static bool hasn(const Roll & roll, int k) {
  for (int r = 1; r <= 6; ++r) {
    if (roll.count(r) >= k) return true;
  }
  return false;
}

static bool has_full(const Roll & roll) {
  bool has3 = false;
  bool has2 = false;
  for (int r = 1; r <= 6; ++r) {
    int c = roll.count(r);
    if (c == 3) has3 = true;
    if (c == 2) has2 = true;
  }
  return has3 && has2;
}

static bool has_small(const Roll & roll) {
  bool hask[6] = { false };
  for (int r = 1; r <= 6; ++r) hask[r - 1] = roll.count(r);
  
  // all small straights must have a 3 and 4
  if (!hask[2] || !hask[3]) return false;

  return (hask[0] && hask[1]) || (hask[1] && hask[4]) || (hask[4] && hask[5]);
}

static bool has_large(const Roll & roll) {
  bool hask[6] = { false };
  for (int r = 1; r <= 6; ++r) {
    hask[r - 1] = roll.count(r);
    if (hask[r - 1] > 1) return false;
  }
  return !hask[0] || !hask[5];
}

static int sum(const Roll & roll) {
  int ret = 0;
  for (int r = 1; r <= 6; ++r) {
    ret += roll.count(r) * r;
  }
  return ret;
}

int score(Roll roll, Category category) {
  switch (category) {
    case ONES:        return roll.count(1)*1;
    case TWOS:        return roll.count(2)*2;
    case THREES:      return roll.count(3)*3;
    case FOURS:       return roll.count(4)*4;
    case FIVES:       return roll.count(5)*5;
    case SIXES:       return roll.count(6)*6;

    case TRIPLE:      return hasn(roll, 3) ? sum(roll) : 0;
    case QUAD:        return hasn(roll, 4) ? sum(roll) : 0;
    case FULL:        return has_full(roll)  ? 25 : 0;
    case SMALL:       return has_small(roll) ? 30 : 0;
    case LARGE:       return has_large(roll) ? 40 : 0;
    case CHANCE:      return sum(roll);
    case YAHTZEE:     return hasn(roll, 5) ? 50 : 0;
  }
  assert(false);
  return 0;
}

