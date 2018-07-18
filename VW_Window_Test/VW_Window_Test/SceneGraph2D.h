#pragma once
#include "View.h"
#include "Window.h"

class SceneGraph2D : public View {
private:

public:

	virtual void Draw(Graphics *graphics);

	SceneGraph2D();
	~SceneGraph2D();

	virtual void Update();

};

