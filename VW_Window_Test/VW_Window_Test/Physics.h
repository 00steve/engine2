#pragma once

#include "Node.h"
#include "Physical.h"

class Physics : public Physical{
private:



public:
	virtual Node * AddChild(Node* newNode);

	Physics();
	~Physics();

	virtual void Update();
};

