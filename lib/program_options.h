#ifndef GOWNTA_PROGRAM_OPTIONS_H
#define GOWNTA_PROGRAM_OPTIONS_H

#include <boost/program_options.hpp>


boost::program_options::variables_map & cmd_options();
void read_options(int argc, char ** argv);

#endif // GOWNTA_PROGRAM_OPTIONS_H

