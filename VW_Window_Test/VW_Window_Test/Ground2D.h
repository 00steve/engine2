#pragma once
#include "Physical.h"
#include "Drawable.h"
#include "GL\glew.h"

class Ground2D : public Physical, public Drawable {
private:

public:

	virtual void Draw();

	Ground2D();
	~Ground2D();
};

