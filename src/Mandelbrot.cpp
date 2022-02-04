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

void Mandelbrot::zoomRelative(int direction, QVector2D posRelative) {
	float modifier = direction < 0 ? zoomModifier : (1 / zoomModifier);
	QVector2D newSize = size * modifier;
	QVector2D fixPos = origin + posRelative * size;
	QVector2D newOrigin = fixPos - posRelative * newSize;
	size = newSize;
	origin = newOrigin;
}

void Mandelbrot::setIterations(int value) {
	iterations = value;
}

void Mandelbrot::translateRelative(QVector2D relative) {
	QVector2D absolute = relative * size;
	origin -= absolute;
}

void Mandelbrot::resizeRelative(QVector2D relative) {
	size *= relative;
}




