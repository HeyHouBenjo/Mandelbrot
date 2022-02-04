#pragma once


#include <QWidget>
#include <QOpenGLWidget>
#include <QMouseEvent>
#include <QWheelEvent>
#include <QKeyEvent>
#include "Mandelbrot.h"

class OutputWidget : public QOpenGLWidget, protected QOpenGLExtraFunctions {
	Q_OBJECT
public:
	explicit OutputWidget(QWidget* parent): QOpenGLWidget(parent) {}
	Mandelbrot& getMandelbrot() {return mandelbrot;}
	void saveToImage(const std::function<void(void)>&, const std::function<void(bool)>&);
private:
	void initializeGL() override;
	void paintGL() override;
	void resizeGL(int, int) override;

	void wheelEvent(QWheelEvent*) override;
	void mouseMoveEvent(QMouseEvent*) override;
	void mousePressEvent(QMouseEvent*) override;
	void mouseReleaseEvent(QMouseEvent*) override;
	void keyPressEvent(QKeyEvent*) override;

	QPoint mousePos;
	QSize oldSize {0, 0};

	GLuint createVAO();

	Mandelbrot mandelbrot;
};


