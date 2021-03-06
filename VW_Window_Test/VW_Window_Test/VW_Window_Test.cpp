// VW_Window_Test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>

#include <iostream>
#include "Engine.h"
#include "SceneGraph2D.h"
#include "Ground2D.h"

int main()
{


	Engine* e = new Engine();



	View* v = new SceneGraph2D();
	Window* w = new Window(); 
	w->AddChild(v);
	e->AddChild(w);


	Physical *ground = new Ground2D();
	e->AddChild(ground);



	while (!e->Finished()) {
		e->Update();
	}
	delete e;
	
	return 0;
}

