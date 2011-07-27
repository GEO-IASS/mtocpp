#include "mfilescanner.h"

#include <cassert>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <iterator>
extern "C" {
#include <unistd.h>
}

using std::cerr;
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::list;
using std::copy;
using std::map;
using std::set;
using std::istream;
using std::ifstream;
using std::ostream;
using std::ostream_iterator;
using std::ostringstream;

void usage()
{
  cout
    << "This is mtoc++ Version " << MTOCPP_VERSION_MAJOR << "." << MTOCPP_VERSION_MINOR << "\n"
    << "\n"
    << "mtoc++ parses the Matlab m-file <mfile> and produces c++-compliant output that can be processed by doxygen.\n"
    << "\n"
    << "Usage: mtocpp <mfile> [<configuration-file>]\n"
    << "       mtocpp --help\n"
    << "\n"
    << "If no explicit configuration file is given, mtoc++ also looks for './mtoc++.conf' by default." << endl;
}

// main routine
int main(int argc, char ** argv)
{
  istream * fcin;
  std::ifstream fin;
  string filename;
  if(argc >= 2)
  {
    if (string(argv[1]) == string("--help"))
    {
      usage();
      exit(0);
    }
    std::ios_base::iostate oldstate = fin.exceptions();
    fin.exceptions ( ifstream::failbit );
    try
    {
      fin.open(argv[1]);
      fcin = &fin;
      filename = argv[1];
    }
    catch (std::ifstream::failure e)
    {
      cout << "Exception opening/reading file: " << argv[1] << "\n";
      usage();
      exit(-1);
    }
    fin.exceptions(oldstate);
  }
  else
  {
    fcin = &cin;
    filename = "stdin";
  }

  std::string conffilename;
  if(argc == 3)
  {
    conffilename = std::string(argv[2]);
  }
  
  char buf[1000];
  char * dummy = getcwd(buf, 1000);
  dummy = 0;

  string::size_type found = 0;
  string cwd(buf);
  found = filename.find(cwd);
  if(found!=string::npos)
  {
    filename = filename.substr(cwd.size()+1);
  }
  RunMode runMode;
  MFileScanner scanner(*fcin, cout, filename, conffilename, runMode);
  scanner.execute();
  return 0;
}

/* vim: set et sw=2 ft=ragel foldmethod=marker: */

