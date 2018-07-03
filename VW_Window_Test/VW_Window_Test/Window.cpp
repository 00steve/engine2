#include "stdafx.h"
#include "Window.h"



bool Window::Init() {


	return true;
};


bool Window::ShouldClose() {

	return glfwWindowShouldClose(glfwWindow);
}


void Window::Update() {
	glfwPollEvents();
	Node::Update();
}


Window::Window(){


	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
	glfwWindow = glfwCreateWindow(800, 600, "", nullptr, nullptr);

};


Window::~Window(){
	glfwDestroyWindow(glfwWindow);
	Node::~Node();
};
