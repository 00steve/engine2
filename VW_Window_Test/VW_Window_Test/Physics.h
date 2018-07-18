#pragma once

#include "Node.h"
#include "Physical.h"
#include "Drawable.h"

class Physics : public Drawable{
private:



public:
	virtual Node * AddChild(Node* newNode);

	virtual void Draw();

	Physics();
	~Physics();

	virtual void Update();
};

