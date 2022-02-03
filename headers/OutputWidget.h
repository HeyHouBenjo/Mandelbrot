
#pragma once


#include <QWidget>
#include <QOpenGLFunctions>
#include <QOpenGLWidget>
#include "Mandelbrot.h"

class OutputWidget : public QOpenGLWidget, protected QOpenGLFunctions {
	Q_OBJECT
public:
	explicit OutputWidget(QWidget* parent): QOpenGLWidget(parent) {}
	Mandelbrot* getMandelbrot() {return &mandelbrot;}
private:
	void initializeGL() override;
	void paintGL() override;
	void resizeGL(int, int) override;

	void wheelEvent(QWheelEvent*) override;
	void mouseMoveEvent(QMouseEvent*) override;
	void mousePressEvent(QMouseEvent*) override;
	void mouseReleaseEvent(QMouseEvent*) override;
	void keyPressEvent(QKeyEvent*) override;

	Mandelbrot mandelbrot;
};


