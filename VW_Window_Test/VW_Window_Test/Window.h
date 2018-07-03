#pragma once



#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include "Node.h"


class Window : public Node {
private:
	GLFWwindow * glfwWindow;

public:
	bool Init();

	bool ShouldClose();

	void Update();

	Window();

	~Window();



};

