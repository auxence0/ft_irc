
# include <iostream>
# include <limits>

bool	verif_port(char	*port) {
	bool	has_int(false);
	size_t	i(0);

	while (isspace(port[i]))
		i++;
	if (port[i] == '+' || port[i] == '-')
		i++;
	while (isdigit(port[i])) {
		has_int = true;
		i++;
	}
	while (isspace(port[i]))
		i++;
	if (port[i] != '\0' || has_int == false)
		return false;
	errno = 0;
	long	num = strtol(port, NULL, 10);
	if (errno == ERANGE || num < 1024 || num > 65535)
		return false;
	return true;
}

int	main(int ac, char **av) {
	if (ac != 3) {
		std::cerr << "Bad usage: ./ircserv <port> <password>\n";
		return 1;
	}
	if (verif_port(av[1]) == false) {
		std::cerr << "Bad usage port: [1024, 65535]\n";
		return 1;
	}
	std::string	str(av[2]);
	if (str.empty()) {
		std::cerr << "Password is empty\n";
		return 1;
	}

	return 0;
}