#pragma once


#include <GL/glew.h>
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

	static bool glewIsSetup;




	////shit for testing OPENGL
	//unsigned int VBO; 
	//unsigned int VAO;
	//const char *vShader = "#version 330 core \n\
	//	layout(location = 0) in vec3 aPos;\n\
	//	void main()\n\
	//	{\n\
	//		gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n\
	//	}\n";
	//unsigned int vertexShader;
	//const char *fShader = "#version 330 core\n\
	//	out vec4 FragColor;\n\
	//	\n\
	//	void main()\n\
	//	{\n\
	//		FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n\
	//	}\n";
	//unsigned int fragmentShader;
	//unsigned int shaderProgram;


protected:

	static bool GLEWIsSetup();


public:

	virtual Node* AddChild(Node* newNode);

	virtual bool Finished();

	void SetGraphicsPool(Graphics* newGraphics);

	void Update();

	Window();

	~Window();



};

