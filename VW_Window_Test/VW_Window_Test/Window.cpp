#include "stdafx.h"
#include "Window.h"




Node * Window::AddChild(Node * newNode) {
	View* view = dynamic_cast<View*>(newNode);
	if (view) {
		views.Push(view);
		return Node::AddChild(newNode);
	}
	return NULL;
}

bool Window::Finished()
{
	return glfwWindowShouldClose(glfwWindow);
}

void Window::SetGraphicsPool(Graphics * newGraphics) {
	graphics = newGraphics;
	int i = views.Count();
	while (i-- > 0) {
		views[i]->SetGraphics(newGraphics);
	}
}



void Window::Update() {
	Node::Update();
	glfwMakeContextCurrent(glfwWindow);
	glViewport(0, 0, 800, 600); //when using views, we won't need this anymore as the view will specify the pixel area to which to draw

	//glViewport(0, 0, 800, 600);

	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	float vertices[] = {
		-0.5f, -0.5f, 0.0f,
		0.5f, -0.5f, 0.0f,
		0.0f,  0.5f, 0.0f
	};



	//int i = views.Count();
	//while (i-- > 0) {
	//	views[0]->Draw(graphics);
	//}
	glfwSwapBuffers(glfwWindow);
	glfwPollEvents();
}


Window::Window(){
	//setup the GLFW window
	//glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);

	//glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // We don't want the old OpenGL 


	glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);
	glfwWindow = glfwCreateWindow(800, 600, "", nullptr, nullptr);
	if (!glfwWindow) {
		cout << "Failed to create GLFW window!\n";
	}

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

	cout << "GLFW extensions\n----------------\n";
	for (unsigned int i = 0; i < glfwExtensionCount; i++) {
		std::cout << "\t" << glfwExtensions[i] << std::endl;
	}

/*

	unsigned int VBO;
	glGenBuffers(1, &VBO);*/

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
