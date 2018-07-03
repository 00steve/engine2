#pragma once


#include <iostream>
#include "Window.h"
#include "Physics.h"
#include "SceneGraph.h"

class Engine : public Node {
private:
	Graphics * graphics;
	UnorderedList<Window*> windows;
	Physics *physics;

	bool destroyOnWindowClose = true;

public:

	virtual Node* AddChild(Node* newChild);

	Engine();
	~Engine();

	virtual void RemoveReference(Node* node);

	void Update();
};