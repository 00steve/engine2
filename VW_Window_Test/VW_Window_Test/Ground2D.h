#pragma once
#include "Physical.h"
#include "Drawable.h"

#include <GL/glew.h>

class Ground2D : public Physical, public Drawable {
private:

	//shit for testing OPENGL
	unsigned int VBO;
	unsigned int VAO;
	const char *vShader = "#version 330 core \n\
		layout(location = 0) in vec3 aPos;\n\
		void main()\n\
		{\n\
			gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n\
		}\n";
	unsigned int vertexShader;
	const char *fShader = "#version 330 core\n\
		out vec4 FragColor;\n\
		\n\
		void main()\n\
		{\n\
			FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n\
		}\n";
	unsigned int fragmentShader;
	unsigned int shaderProgram;
public:

	virtual void Draw();

	Ground2D();
	~Ground2D();
};

