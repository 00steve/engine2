#pragma once
#include<iostream>
#include "UnorderedList.h"

class Node {
private:
	bool canDestroy;
	UnorderedList<Node*> children;

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

public:
	Node* AddChild(Node* newNode);
	Node* AddReference(Node* newNode);
	virtual bool CanDestroy();


	virtual bool MakeDestroyable();

	Node();
	~Node();


	Node* RemoveReference(Node* oldNode);
	Node* SetParent(Node* newNode);

	virtual void Update();
};

