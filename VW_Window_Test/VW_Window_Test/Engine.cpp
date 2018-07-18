
#include "stdafx.h"
#include "Engine.h"


Node* Engine::AddChild(Node* newNode) {
	//add it as a child node no matter hahwat, it is 
	//a special boy, and it deserves a chance to grow
	//up awkwardly like the rest of us
	Node::AddChild(newNode);
	//let the physics engine try to add the node
	physics->AddChild(newNode);
	//let the graphics pool try to add the node
	graphics->AddChild(newNode);
	/*if it's a window, add it to the window list and 
	also push it to the node list of children so it does
	all of the node stuff with references*/
	Window* window = dynamic_cast<Window*>(newNode);
	if (window) {
		window->SetGraphicsPool(graphics);
		windows.Push(window);
	}
	return newNode;
}

Engine::Engine() {
	cout << "->Engine";

	//initialize openGL
	if (!glfwInit()) {
		cout << "Failed to initialize GLFW, abandoning engine initialization.\n";
		return;
	}

	glfwWindowHint(GLFW_SAMPLES, 4); // 4x antialiasing
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_ALWAYS);
	glLineWidth(2.0f);
	glEnable(GL_ALPHA);
	glClearColor(1, 0, 0, 1);


	physics = new Physics();
	graphics = new Graphics();



};

Engine::~Engine() {
	while (windows.Count()) {
		delete windows.Pop();
	}
	delete physics;
	glfwTerminate();
	Node::~Node();
}

bool Engine::Finished() {
	return (finishedWhenAllWindowsClose && !windows.Count());
}

Node* Engine::RemoveReference(Node * node) {
	Node::RemoveReference(node);
	Window* w = windows.Cut((Window*) node);
	if(w) cout << "cut the reference\n";
	return node;
}

string Engine::Type()
{
	return "Engine";
}

void Engine::Update() {
	physics->Update();
	int i = windows.Count();
	while (i-- > 0) {
		windows[i]->Update();
		if (windows[i]->Finished()) {
			delete windows.Cut(windows[i]);
		}
	}
}