#include "stdafx.h"
#include "Window.h"

bool Window::glewIsSetup = false;


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

bool Window::GLEWIsSetup() {
	return glewIsSetup;
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

	glUseProgram(shaderProgram);
	glBindVertexArray(VAO);
	glDrawArrays(GL_TRIANGLES, 0, 3);

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
		return;
	}

	glfwMakeContextCurrent(glfwWindow); //must be called before glew init

	cout << "->Window\n";

	cout << "GLFW extensions\n----------------\n";
	for (unsigned int i = 0; i < glfwExtensionCount; i++) {
		std::cout << "\t" << glfwExtensions[i] << std::endl;
	}



	if (!GLEWIsSetup()) {
		//glewExperimental = GL_TRUE;
		GLenum ret = glewInit();
		if (GLEW_OK == ret) {
			cout << "Initialized GLEW!\n";
			if (GLEW_VERSION_1_3)
			{
				cout << " - v1.3 supported\n";
			}
			glewIsSetup = true;
		} else {
			/* Problem: glewInit failed, something is seriously wrong. */
			fprintf(stderr, "GLFW Init Error: %s\n", glewGetErrorString(ret));
			return;
		}
	}





	//test building some shit out

	//create the vertex buffer
	float vertices[] = {
		-0.5f, -0.5f, 0.0f,
		0.5f, -0.5f, 0.0f,
		0.0f,  0.5f, 0.0f
	};
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);


	//create and compile the vertex shader
	vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vShader, NULL);
	glCompileShader(vertexShader);

	int  success;
	char infoLog[512];
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
	}


	//create and compile fragment shader
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fShader, NULL);
	glCompileShader(fragmentShader);
	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
	}


	//create shader program
	shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);

	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
	if (!success) {
		glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
	}

	glUseProgram(shaderProgram);//not sure I need this one



	//https://learnopengl.com/Getting-started/Hello-Triangle

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);


	// 2. use our shader program when we want to render an object
	glUseProgram(shaderProgram);
	// 3. now draw the object 
	//someOpenGLFunctionThatDrawsOurTriangle();

	
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);
	// 2. copy our vertices array in a buffer for OpenGL to use
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	// 3. then set our vertex attributes pointers
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
};


Window::~Window(){
	int i = views.Count();
	while (i-- > 0) {
		views[i]->RemoveReference(this);
	}

	//vkDestroyInstance(vulkanInstance, nullptr);
	glfwDestroyWindow(glfwWindow);
	cout << " - GLFW destroy window!\n";


	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
};
