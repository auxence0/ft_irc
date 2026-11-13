#include "../include/Utils.hpp"

std::string	ircTolower(std::string const &s) {
	if (s.empty())
		return std::string();
	std::string	res;

	for(size_t i = 0; i < s.length(); i++) {
		if (std::isupper(s[i]))
			res.push_back(std::tolower(s[i]));
		else if (s[i] == '[' || s[i] == ']' || s[i] == '\\' || s[i] == '^')
			res.push_back(s[i] + 32);
		else
			res.push_back(s[i]);
	}
	return res;
}

std::vector<std::string>	split(std::string const &str, char sep) {
	std::vector<std::string>	res;
	size_t						start = 0;
	size_t						end = str.find(sep);

	if (str.empty())
		return res;
	while (end != std::string::npos) {
		res.push_back(str.substr(start, end - start));
		start = end + 1;
		end = str.find(sep, start);
	}
	res.push_back(str.substr(start));
	return res;
}

std::string	trim(std::string const &str) {
	size_t	start = str.find_first_not_of(" \t\r\n");
	if (start == std::string::npos)
		return std::string();
	size_t	end = str.find_last_not_of(" \t\r\n");
	return (str.substr(start, end - start + 1));
}

std::string	toString(int n) {
	std::ostringstream	res;
	res << n;
	return res.str();
}

