#pragma once
#include "Physical.h"
#include "Drawable.h"

class Ground2D : public Physical, public Drawable {
private:

public:

	virtual void Draw();

	Ground2D();
	~Ground2D();
};

