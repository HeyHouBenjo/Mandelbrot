
#include <iostream>
#include "../headers/OutputWidget.h"

using std::cout, std::endl;

void OutputWidget::initializeGL() {
	cout << "Initialize OpenGL" << endl;
	initializeOpenGLFunctions();

	auto format = this->format();
	cout << "OpenGL version: " <<
		format.majorVersion() << "." << format.minorVersion()
	<< endl;

	glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
}

void OutputWidget::paintGL() {
	glClear(GL_COLOR_BUFFER_BIT);
	mandelbrot.draw();
}

void OutputWidget::resizeGL(int w, int h) {

}

void OutputWidget::wheelEvent(QWheelEvent *e) {

}

void OutputWidget::mouseMoveEvent(QMouseEvent *e) {

}

void OutputWidget::mousePressEvent(QMouseEvent *e) {

}

void OutputWidget::mouseReleaseEvent(QMouseEvent *e) {

}

void OutputWidget::keyPressEvent(QKeyEvent *e) {

}
