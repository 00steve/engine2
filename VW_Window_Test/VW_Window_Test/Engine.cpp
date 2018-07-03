
#include "stdafx.h"
#include "Engine.h"




Engine::Engine() {
	glfwInit();
	window = new Window();
};

Engine::~Engine() {
	if (window) delete window;
	glfwTerminate();
	Node::~Node();
}

void Engine::Update() {
	window->Update();


	if (window->ShouldClose()) {
		
		if (destroyOnWindowClose) MakeDestroyable();
	}

	Node::Update();
}