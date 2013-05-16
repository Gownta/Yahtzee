#include "program_options.h"
#include <iostream>
#include <cstdlib>

using namespace std;
namespace po = boost::program_options;
static const string TITLE = "***TITLE***";

static po::options_description desc(TITLE + " Options");
static po::variables_map vm;

po::variables_map & cmd_options() {
  return vm;
}

void read_options(int argc, char ** argv) {
  /////////////////////////////////////

  // Argument options
  desc.add_options()
      // main
      ("help,h", "Display help message.")
  ;

  // positional options
  po::positional_options_description pos;
    //pos.add("switch", 1);

  po::options_description dpos("Positionals");
  dpos.add_options()
      //("switch", po::value<string>()->default_value("all"), "What to do when the program executes.")
  ;

  /////////////////////////////////////
  // parse the command line

  po::options_description all;
  all.add(desc).add(dpos);

  po::store(po::command_line_parser(argc, argv).options(all).positional(pos).run(), vm);
  po::notify(vm);

  // if the help option was selected, print a help message
  if (cmd_options().count("help")) {
    cout << "\n    ===== " << TITLE << " =====\n"
         <<   "    Nicholas Ormrod (Gownta)\n\n";
    cout << "Usage: " << TITLE << " [args]\n\n";
    cout << desc << endl;
    exit(1);
  }
}

