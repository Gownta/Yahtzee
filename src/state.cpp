#include "state.h"
#include <iostream>

static int C(int n, int k) {
  if (n < k) return 0;
  if (2*k > n) k = n - k;
  int c = 1;
  for (int i = 0; i < k; ++i) c = c * (n-i) / (i+1);
  return c;
}

static int encode(int n, int k, const int * data) {
  int e = 0;
  for (int i = 0; i < k; ++i) e += C(n-data[i], k-i);
  return e;
}

static void decode(int n, int k, int e, int * data) {
  // bottom-up search
  // INVARIANT: the next element in the sequence is at least equal to j
  // INVARIANT: c = C(n-j,k-i)

  int j = 1;
  int c = C(n-j,k);

  for (int i = 0; i < k-1; ++i) {
    // increment j while it is not the i'th element
    while (c > e) {
      c = c * (n-j-k+i) / (n-j);
      j++;
    }

    // the i'th element is j
    data[i] = j;

    // adjust variables for next loop
    e -= c;
    c  = c * (k-i) / (n-j);
    j += 1;
  }

  // final element optimization
  data[k-1] = n - e;
}

Roll::Roll(int e) {
  int data[7];
  decode(10,5,e,data+1);
  data[0] = 0;
  data[6] = 11;
  for (int i = 0; i < 6; ++i) data[i] = data[i+1] - data[i] - 1;
  n_1 = data[0];
  n_2 = data[1];
  n_3 = data[2];
  n_4 = data[3];
  n_5 = data[4];
  n_6 = data[5];
  assert(n_1 + n_2 + n_3 + n_4 + n_5 + n_6 == 5);
}

int Roll::to_int() const {
  int data[7] = { 0, n_1, n_2, n_3, n_4, n_5, n_6 };
  for (int i = 1; i < 7; ++i) data[i] = data[i-1] + data[i] + 1;
  return encode(10,5,data+1);
}

std::ostream & operator<<(std::ostream & os, const Category category) {
  switch (category) {
    case ONES:        os << "1s"; break;
    case TWOS:        os << "2s"; break;
    case THREES:      os << "3s"; break;
    case FOURS:       os << "4s"; break;
    case FIVES:       os << "5s"; break;
    case SIXES:       os << "6s"; break;

    case TRIPLE:      os << "triple"; break;
    case QUAD:        os << "quad"; break;
    case FULL:        os << "full"; break;
    case SMALL:       os << "small"; break;
    case LARGE:       os << "large"; break;
    case CHANCE:      os << "chance"; break;
    case YAHTZEE:     os << "yahtzee"; break;
  }
  return os;
}

std::ostream & operator<<(std::ostream & os, const Roll roll) {
  for (int r = 1; r <= 6; ++r) for (int i = 0; i < roll.count(r); ++i) os << r << " ";
  return os;
}

std::ostream & operator<<(std::ostream & os, const State state) {
  os << "=== Yahtzee State ===\n"
     << "1s      = " << (state.can_use(ONES)    ? " " : "-") << "\n"
     << "2s      = " << (state.can_use(TWOS)    ? " " : "-") << "\n"
     << "3s      = " << (state.can_use(THREES)  ? " " : "-") << "\n"
     << "4s      = " << (state.can_use(FOURS)   ? " " : "-") << "\n"
     << "5s      = " << (state.can_use(FIVES)   ? " " : "-") << "\n"
     << "6s      = " << (state.can_use(SIXES)   ? " " : "-") << "\n"
     << "(total  = " << state.get_topscore() << ")\n\n"
     << "triple  = " << (state.can_use(TRIPLE)  ? " " : "-") << "\n"
     << "quad    = " << (state.can_use(QUAD)    ? " " : "-") << "\n"
     << "full    = " << (state.can_use(FULL)    ? " " : "-") << "\n"
     << "small   = " << (state.can_use(SMALL)   ? " " : "-") << "\n"
     << "large   = " << (state.can_use(LARGE)   ? " " : "-") << "\n"
     << "chance  = " << (state.can_use(CHANCE)  ? " " : "-") << "\n"
     << "yahtzee = " << (state.can_bonus() ? "*" : state.can_use(YAHTZEE) ? " " : "-") << "\n"
  ;
  return os;
}

