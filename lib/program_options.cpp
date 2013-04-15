#include "program_options.h"
#include <iostream>

using namespace std;

static po::options_description desc("Yahtzee Options");
static po::variables_map vm;

po::variables_map & cmd_options() {
  return vm;
}

void print_options() {
  cout << desc << endl;
}

void read_options(int argc, char ** argv) {
  // The options
  desc.add_options()
      // main
      ("help,h", "Display help message.")
  ;

  // positional options
  po::positional_options_description pos;
  pos.add("switch", 1);

  po::options_description dpos("Positionals");
  dpos.add_options()
      ("switch", po::value<string>()->default_value("all"), "What to do when the program executes.")
  ;

  // parse the command line
  po::options_description all;
  all.add(desc).add(dpos);

  po::store(po::command_line_parser(argc, argv).options(all).positional(pos).run(), vm);
  po::notify(vm);
}

