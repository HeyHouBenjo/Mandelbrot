
#include <iostream>
#include "../headers/OutputWidget.h"

void OutputWidget::initializeGL() {
	initializeOpenGLFunctions();
	std::cout << "Initialize GL" << std::endl;
	auto format = this->format();
	std::cout << "OpenGL version: " <<
		format.majorVersion() << "." << format.minorVersion()
	<< std::endl;

	::glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
}

void OutputWidget::paintGL() {

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
