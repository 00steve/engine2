#pragma once

#define MESSAGE_DEREFERENCE 100
#define MESSAGE_REFERENCE 101

class Message {
public:

	void* Data;
	unsigned int ID;

	Message();
	~Message();
};

