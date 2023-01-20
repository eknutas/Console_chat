/* Chat.cpp Console_chat */

#include "Chat.h"

int Chat::chat(const std::string& from)
{
	system("cls");	//clearing the console
	std::cout << "Hello, " << from << "!" << '\n';
	for (int i = 0; i < size(_msg); ++i)
	{
		if (((*_msg[i]).getFrom() == from) || ((*_msg[i]).getTo() == from) || ((*_msg[i]).getTo() == "all")) {

			std::cout << "From: " << (*_msg[i]).getFrom() << "     To: " << (*_msg[i]).getTo() << '\n';
			std::cout << "Message: " << (*_msg[i]).getText() << '\n';
		}
	}
	std::cout << "Enter the recipient (all for everyone): ";
	std::cin >> _to;
	std::cin.seekg(std::cin.eof());	//read the input buffer to the end
	std::cout << "Enter your message: ";
	std::getline(std::cin, _text);	//read a line
	_msg.push_back(std::make_unique<Message>(from, _to, _text));

	return 0;
}

int Chat::logIn()
{
	if (_usr.empty()) {
		throw "No user, registration required!";
	}
	std::cout << "Enter login: ";
	std::cin >> _login;
	std::cout << "Enter password: ";
	std::cin >> _password;
	for (int i = 0; i < size(_usr); ++i)
	{
		if ((*_usr[i]).access(_login, _password)) {	//login and password verification
			chat((*_usr[i]).getName());	//enter the chat
			return 0;
		}
	}
	std::cout << "Invalid user or password!" << '\n';
	return 1;
}

int Chat::checkIn()
{
	std::cout << "Enter a new username: ";
	std::cin >> _name;
	if (_name == "all") {
		throw "This name is busy! Please enter another name.";
	}
	for (int i = 0; i < size(_usr); ++i)
	{
		if (_name == (*_usr[i]).getName()) {
			throw "This name is busy! Please enter another name.";
		}
	}
	std::cout << "Enter new user login: ";
	std::cin >> _login;
	for (int i = 0; i < size(_usr); ++i)
	{
		if (_login == (*_usr[i]).getLogin()) {
			throw "This login is busy! Please enter another login.";
		}
	}
	std::cout << "Enter the new user's password: ";
	std::cin >> _password;
	_usr.push_back(std::make_unique<User>(_name, _login, _password));
	std::cout << "Hello, " << _name << '\n';
	return 0;
}