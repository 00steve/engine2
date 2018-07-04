#pragma once
#include "View.h"
#include "Window.h"

class SceneGraph2D : public View {
private:

public:

	void Draw();

	SceneGraph2D();
	~SceneGraph2D();

	virtual void Update();

};

