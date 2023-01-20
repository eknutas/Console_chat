/* Chat.h Console_chat */

#pragma once
#include <string>
#include <vector>
#include "Message.h"
#include "User.h"

class Chat
{
private:
	std::string _name;
	std::string _login;
	std::string _password;
	std::string _from;
	std::string _to;
	std::string _text;
	std::vector<std::unique_ptr<Message>> _msg;	//vector for messages
	std::vector<std::unique_ptr<User>> _usr;	//vector for users
public:
	Chat() = default;

	~Chat() = default;

	int chat(const std::string& from);

	int logIn();

	int checkIn();
};