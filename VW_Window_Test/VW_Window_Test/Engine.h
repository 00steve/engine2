#pragma once

#include <iostream>
#include "Window.h"
#include "Physics.h"
#include "View.h"
#include "Graphics.h"

class Engine : public Node {
private:
	UnorderedList<View*> views;
	UnorderedList<Window*> windows;
	Physics *physics;
	Graphics *graphics;

	bool finishedWhenAllWindowsClose = false;


	//context needed before calling InitGLEW
	GLFWwindow * glfwWindow;

public:

	virtual Node* AddChild(Node* newChild);

	Engine();
	~Engine();

	virtual bool Finished();

	virtual Node* RemoveReference(Node* node);


	virtual string Type();

	void Update();
};