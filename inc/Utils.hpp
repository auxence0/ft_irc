#pragma once

#include <string>
#include <cctype>
#include <vector>
#include <sstream>

std::string	ircTolower(std::string const &s);
std::vector<std::string>	split(std::string const &str, char sep);
std::string	trim(std::string const &str);
std::string	toString(int n);