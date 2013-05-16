#include <iostream>
#include "program_options.h"
#include <cstdlib>

using namespace std;

int main(int argc, char** argv) {
  srand(time(NULL));

  read_options(argc, argv);

  // Help
  if (cmd_options().count("help")) {
    cout << "\n     ===== Yahtzee =====\n\n"
              "     Nicholas Ormrod (Gownta)\n"
            "\n     ===================\n\n";
    cout << "Usage: yahtzee [options] [what]\n\n";
    print_options();
    return 1;
  }

  cout << (8 << 1) << ", " << (8 >> 1) << endl;

  return 0;
}

