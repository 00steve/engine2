#pragma once



#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include "Node.h"


class Window : public Node {
private:
	GLFWwindow * glfwWindow;
	VkInstance vulkanInstance;
	VkApplicationInfo appInfo = {};
	VkInstanceCreateInfo createInfo = {}; 
	VkResult result;

	uint32_t glfwExtensionCount = 0;
	const char** glfwExtensions;





public:

	Node * AddNode(Node* newNode);

	bool ShouldClose();

	void Update();

	Window();

	~Window();



};

