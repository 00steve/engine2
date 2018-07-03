
#include "stdafx.h"
#include "Engine.h"



Node* Engine::AddChild(Node* newNode) {
	Node::AddChild(newNode);
	physics->AddChild(newNode);

	Window* window = dynamic_cast<Window*>(newNode);
	if (window) windows.Push(window);

	std::cout << "added node to engine." << std::endl;
	return newNode;
}

Engine::Engine() {
	glfwInit();
	physics = new Physics();
	graphics = new SceneGraph();
};

Engine::~Engine() {
	while (windows.Count()) {
		delete windows.Pop();
	}
	glfwTerminate();
	Node::~Node();
}

void Engine::RemoveReference(Node * node) {
	windows.Cut((Window*) node);
	Node::RemoveReference(node);
}

void Engine::Update() {
	int i = windows.Count();
	while (i-- > 0) {
		windows[i]->Update();
	}
	Node::Update();
}