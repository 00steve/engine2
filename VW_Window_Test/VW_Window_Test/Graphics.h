#pragma once
#include "Drawable.h"
#include "Node.h"

class Graphics : public Node{
private:

public:

	Node * AddChild(Node* newNode);

	Graphics();
	~Graphics();
};

