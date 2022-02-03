
#include "../headers/Mandelbrot.h"

void Mandelbrot::init() {
	initializeOpenGLFunctions();

	vao = createVAO();
}

void Mandelbrot::draw() {

}

void Mandelbrot::zoom(double delta) {
	scale *= delta;
}

void Mandelbrot::setIterations(int value) {
	iterations = value;
}

GLuint Mandelbrot::createVAO() {
	GLuint vboId;
	glGenBuffers(1, &vboId);
	glBindBuffer(GL_ARRAY_BUFFER, vboId);

	float* vertices = genVertices();
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	GLuint vaoId;
	glGenVertexArrays(1, &vaoId);
	glBindVertexArray(vaoId);
	glBindBuffer(GL_ARRAY_BUFFER, vboId);

	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*) nullptr);
	glEnableVertexAttribArray(0);

	glBindVertexArray(0);

	return vaoId;
}

float* Mandelbrot::genVertices() {
	return new float[8]{
			-1, -1,
			1, -1,
			1, 1,
			-1, 1
	};
}


