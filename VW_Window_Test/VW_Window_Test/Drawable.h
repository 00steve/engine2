#pragma once
#include "Node.h"
class Drawable : public Node {
private:
	bool visable;

public:

	void Draw();

	Drawable();
	~Drawable();

	virtual void Update();
};

