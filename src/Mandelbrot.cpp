
#include "../headers/Mandelbrot.h"

void Mandelbrot::init() {
	initializeOpenGLFunctions();
}

void Mandelbrot::draw(GLuint vao, int vertCount, QOpenGLShaderProgram& shader) {
	shader.bind();
	glBindVertexArray(vao);
	glDrawArrays(GL_QUADS, 0, vertCount);
	glBindVertexArray(0);
}

void Mandelbrot::zoom(double delta) {
	scale *= delta;
}

void Mandelbrot::setIterations(int value) {
	iterations = value;
}


