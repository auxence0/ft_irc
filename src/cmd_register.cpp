#include "Command.hpp"

void	cmd_pass(server &serv, Client &client, Message const &msg);
void	cmd_nick(server &serv, Client &client, Message const &msg);
void	cmd_user(server &serv, Client &client, Message const &msg);
void	cmd_cap(server &serv, Client &client, Message const &msg);
void	cmd_quit(server &serv, Client &client, Message const &msg);