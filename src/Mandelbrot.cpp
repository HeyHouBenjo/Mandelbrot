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
	shader.setUniformValue("origin", origin);
	shader.setUniformValue("size", size);
	shader.setUniformValue("iterationCount", iterations);
}

void Mandelbrot::zoomRelative(double delta, QVector2D posRelative) {

}

void Mandelbrot::setIterations(int value) {
	iterations = value;
}

void Mandelbrot::translateRelative(QVector2D relative) {
	QVector2D absolute = relative * size;
	origin -= absolute;
}




