#pragma once



//#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include "Node.h"
#include "Graphics.h"
#include "View.h"

class Window : public Node {
private:

	/*a lot of this bullshit could probably be moved down
	into the constructor function, but I want to leave it 
	here in case I need it later for some stupid reason.*/
	uint32_t glfwExtensionCount = 0;
	const char** glfwExtensions;
	GLFWwindow * glfwWindow;

	//VkApplicationInfo appInfo = {};
	//VkInstanceCreateInfo createInfo = {};
	//VkResult result;
	//VkInstance vulkanInstance;


	Graphics* graphics;

	UnorderedList<View*> views;

public:

	Node * AddNode(Node* newNode);

	virtual bool Finished();

	void SetGraphicsPool(Graphics* newGraphics);

	void Update();

	Window();

	~Window();



};

