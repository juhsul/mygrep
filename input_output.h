#pragma once

#ifdef _WIN32
#include <boost/nowide/iostream.hpp>
#include <boost/nowide/fstream.hpp>
#include <boost/nowide/args.hpp>
namespace io = boost::nowide;
#else
#include <iostream>
#include <fstream>
namespace io = std;
#endif