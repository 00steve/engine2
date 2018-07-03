#pragma once


#include <iostream>
#include "Window.h"

class Engine : public Node {
private:
	Window *window;


	bool destroyOnWindowClose = true;

public:


	Engine();
	~Engine();

	void Update();
};