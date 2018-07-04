#pragma once
#include "Drawable.h"


class Graphics : public Node{
private:

public:

	Node * AddChild(Node* newNode);

	Graphics();
	~Graphics();
};

