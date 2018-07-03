// VW_Window_Test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>

#include <iostream>
#include "Engine.h"


int main()
{


	Engine *e = new Engine();

	//Physical *p = new Physical();
	//e->AddChild(p);

	Window *w = new Window();
	e->AddChild(w);
	e->AddChild(new Window());
	while (!e->CanDestroy()) {
		e->Update();
	}
	delete e;
	
	return 0;
}

