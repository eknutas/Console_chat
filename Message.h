/* Message.h Console_chat */

#pragma once
#include <iostream>

class Message
{
private:
	const std::string _from;
	const std::string _to;
	const std::string _text;
public:
	Message() = default;

	Message(const std::string& from, const std::string& to, const std::string& text);

	~Message() = default;

	const std::string getFrom() const;

	const std::string getTo() const;

	const std::string getText() const;
};