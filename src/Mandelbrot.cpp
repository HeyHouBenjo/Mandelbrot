#include <QImage>
#include <iostream>
#include <QOpenGLWidget>
#include "../headers/Mandelbrot.h"

void Mandelbrot::init(GLuint vaoId) {
	initializeOpenGLFunctions();
	vao = vaoId;
}

void Mandelbrot::draw() {
	glClear(GL_COLOR_BUFFER_BIT);
	shader.bind();
	setShaderValues();
	glBindVertexArray(vao);
	glDrawArrays(GL_TRIANGLES, 0, 6);
	glBindVertexArray(0);
}

void Mandelbrot::updateAnimation() {
	if (!animating)
		return;
	hueAdd += 1;
	hueAdd -= hueAdd >= 360 ? 360 : 0;
}

void Mandelbrot::toggleAnimation() {
	animating = !animating;
}

bool Mandelbrot::initShader() {
	if (!shader.addShaderFromSourceFile(QOpenGLShader::Vertex, "Vertex.glsl")) return false;
	if (!shader.addShaderFromSourceFile(QOpenGLShader::Fragment, "Fragment.glsl")) return false;
	if (!shader.link()) return false;
	if (!shader.bind()) return false;
	return true;
}

void Mandelbrot::setShaderValues() {
	shader.setUniformValue("origin", origin);
	shader.setUniformValue("size", size);
	shader.setUniformValue("maxIterationsCount", maxIterations);
	shader.setUniformValue("hueAdd", hueAdd);
	shader.setUniformValue("normalize", normalize);
}

void Mandelbrot::zoomRelative(int direction, QVector2D posRelative) {
	float modifier = direction < 0 ? zoomModifier : (1 / zoomModifier);
	QVector2D newSize = size * modifier;
	QVector2D fixPos = origin + posRelative * size;
	QVector2D newOrigin = fixPos - posRelative * newSize;
	size = newSize;
	origin = newOrigin;
}

void Mandelbrot::setMaxIterations(int value) {
	maxIterations = value;
}

void Mandelbrot::translateRelative(QVector2D relative) {
	QVector2D absolute = relative * size;
	origin -= absolute;
}

void Mandelbrot::resizeRelative(QVector2D relative) {
	size *= relative;
}

void Mandelbrot::toggleNormalize() {
	normalize = !normalize;
}

void Mandelbrot::initView(QSize startSize) {
	int viewW = startSize.width();
	int viewH = startSize.height();
	float ratio = float(viewW) / float(viewH);

	if (ratio > 1){
		size = {startMaxSize, startMaxSize / ratio};
	} else {
		size = {startMaxSize * ratio, startMaxSize};
	}
	origin = startCenter - size / 2;
}




