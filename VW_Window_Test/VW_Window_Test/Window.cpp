#include "stdafx.h"
#include "Window.h"




Node * Window::AddNode(Node * newNode) {
	View* view = dynamic_cast<View*>(newNode);
	if (view) {
		views.Push(view);
		Node::AddChild(newNode);
	}
	return newNode;
}

bool Window::Finished()
{
	return glfwWindowShouldClose(glfwWindow);
}

void Window::SetGraphicsPool(Graphics * newGraphics) {
	graphics = newGraphics;
}



void Window::Update() {
	glfwPollEvents();
	Node::Update();
	//if (glfwWindowShouldClose(glfwWindow)) this->~Window();
}


Window::Window(){
	//setup the GLFW window
	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
	glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);
	glfwWindow = glfwCreateWindow(800, 600, "", nullptr, nullptr);

	/*
	//setup vulkan information
	appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
	appInfo.pApplicationName = "Hello Triangle";
	appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
	appInfo.pEngineName = "No Engine";
	appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
	appInfo.apiVersion = VK_API_VERSION_1_0;

	createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
	createInfo.pApplicationInfo = &appInfo;
	createInfo.enabledExtensionCount = glfwExtensionCount;
	createInfo.ppEnabledExtensionNames = glfwExtensions;
	createInfo.enabledLayerCount = 0;
	*/
	//if (vkCreateInstance(&createInfo, nullptr, &vulkanInstance) != VK_SUCCESS) {
	//	//throw std::runtime_error("failed to create instance!");
	//	std::cout << "couldn't create vulkan instance, for some dumb reason!" << std::endl;
	//}
	cout << "->Window\n";


	for (int i = 0; i < glfwExtensionCount; i++) {
		std::cout << "\t" << glfwExtensions[i] << std::endl;
	}
};


Window::~Window(){
	int i = views.Count();
	while (i-- > 0) {
		views[i]->RemoveReference(this);
	}

	//vkDestroyInstance(vulkanInstance, nullptr);
	glfwDestroyWindow(glfwWindow);
	cout << " - GLFW destroy window!\n";
};
