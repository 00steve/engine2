#pragma once

#include "Node.h"
class Drawable : public Node {
private:
	bool visable;

public:

	virtual void Draw();

	Drawable();
	~Drawable();

	virtual void Update();
};

