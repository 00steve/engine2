#pragma once
#include<iostream>
#include <string>

#include "UnorderedList.h"
#include "Message.h"

using namespace std;

class Node {
private:
	bool canDestroy;
	UnorderedList<Node*> children;


	UnorderedList<Message*> messages;

	string name;

	/*
	The node that contains this node.
	*/
	Node* parent;

	/*
	Store a list of the nodes that reference this node. It doesn't matter
	how or why, all that matters is any node in this list should have a 
	pointer to this node, which will cause an error if this node was deleted.
	*/
	UnorderedList<Node*> references;

protected:

	UnorderedList<Node*> Children();

	virtual bool ProcessMessage(Message* message);
	bool ProcessMessages();

public:
	Node* AddChild(Node* newNode);
	Node* AddReference(Node* newNode);
	virtual bool CanDestroy();



	virtual bool MakeDestroyable();

	Node();
	~Node();


	void ReceiveMessage(Message* newMessage);
	Node* RemoveChild(Node* oldNode);
	Node* RemoveReference(Node* oldNode);
	
	bool SendMessage(Node* receiver, unsigned int id, void* data);
	
	Node* SetParent(Node* newNode);

	virtual void Update();
};

