#include "../headers/Mandelbrot.h"

void Mandelbrot::init() {
	initializeOpenGLFunctions();
}

void Mandelbrot::draw(GLuint vao, QOpenGLShaderProgram& shader) {
	glClear(GL_COLOR_BUFFER_BIT);
	shader.bind();
	setShaderValues(shader);
	glBindVertexArray(vao);
	glDrawArrays(GL_QUADS, 0, 4);
	glBindVertexArray(0);
}

void Mandelbrot::setShaderValues(QOpenGLShaderProgram &shader) const {
	shader.setUniformValue("origin", QVector2D(-2, 1));
	shader.setUniformValue("size", QVector2D(2, 2));
	shader.setUniformValue("iterationCount", iterations);
}

void Mandelbrot::zoom(double delta) {
	scale *= delta;
}

void Mandelbrot::setIterations(int value) {
	iterations = value;
}




