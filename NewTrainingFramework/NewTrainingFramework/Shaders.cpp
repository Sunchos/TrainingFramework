#include "stdafx.h"
#include "../Utilities/utilities.h" 
#include "Shaders.h"
#include <iostream>

int Shaders::Init(char * fileVertexShader, char * fileFragmentShader)
{
	vertexShader = esLoadShader(GL_VERTEX_SHADER, fileVertexShader);

	if ( vertexShader == 0 )
		return -1;

	fragmentShader = esLoadShader(GL_FRAGMENT_SHADER, fileFragmentShader);

	if ( fragmentShader == 0 )
	{
		glDeleteShader( vertexShader );
		return -2;
	}

	program = esLoadProgram(vertexShader, fragmentShader);

	//finding location of uniforms / attributes
	positionAttribute = glGetAttribLocation(program, "a_posL");
	colorAttribute_ = glGetAttribLocation(program, "a_color");
	matrixTransform_ = glGetUniformLocation(program, "u_matT");
	
	if (matrixTransform_ == GL_INVALID_OPERATION)
		std::cout << "error invalid operator" << "\n";
	if (matrixTransform_ == GL_INVALID_OPERATION)
		std::cout << "error INVALID_OPERATION" << "\n";

	return 0;
}

Shaders::~Shaders()
{
	glDeleteProgram(program);
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}