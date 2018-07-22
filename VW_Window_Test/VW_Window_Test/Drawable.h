#pragma once

#include "Node.h"
#include <GL/glew.h>

class Drawable : public Node {
private:
	bool visable;

	static GLenum drawMode;

public:

	virtual void Draw();

	Drawable();
	~Drawable();

	virtual GLenum DrawMode();

	virtual void Update();
};

