#include "stdafx.h"
#include "Ground2D.h"


void Ground2D::Draw() {

	//glUseProgram(shaderProgram);
	//glBindVertexArray(VAO);
	//glDrawArrays(GL_TRIANGLES, 0, 3);


	glUseProgram(shaderProgram);
	//glBindVertexArray(VAO);
	//glBindBuffer(GL_ARRAY_BUFFER, VBO);
	//glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	//glBindVertexArray(0);
	//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	//glDrawElements(GL_TRIANGLES, 9, GL_UNSIGNED_INT, 0);
	groundMesh.Draw();
}

Ground2D::Ground2D() {
	cout << "->Ground2D";
	SetupMesh();

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



	////build an element buffer object
	//float vertices[] = {
	//	0.5f,  0.5f, 0.0f,  // top right
	//	0.5f, -0.5f, 0.0f,  // bottom right
	//	-0.5f, -0.5f, 0.0f,  // bottom left
	//	-0.5f,  0.5f, 0.0f,   // top left 
	//	1.0f,.5f,.0f
	//};
	//unsigned int indices[] = {  // note that we start from 0!
	//	0, 1, 3,   // first triangle
	//	1, 2, 3,    // second triangle
	//	0, 4, 1
	//};

	////generate these shits in whatever order you want, they don't depend on each other yet.
	//glGenBuffers(1, &VBO);
	//glGenVertexArrays(1, &VAO);
	//glGenBuffers(1, &EBO);

	//glBindVertexArray(VAO);
	//glBindBuffer(GL_ARRAY_BUFFER, VBO);
	//glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);


	////bind the ebo buffer so that the indecies data can be set, and other properties set 
	////up like the glVertexAttribPointer. 
	//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);



	////set the indicies that are used
	//glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	////call this before binding a different element array buffer, to set the settings
	//glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	//glEnableVertexAttribArray(0);


}


Ground2D::~Ground2D() {
	cout << "->Ground2D";
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}


void Ground2D::SetupMesh() {
	groundMesh.GenerateGrid(Double2(1, 1), Int2(0, 0));
	groundMesh.BindToGraphics();
}