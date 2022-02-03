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

	QPoint mousePos;

	void initShader();
	static std::vector<QVector2D> genVertices();
	GLuint createVAO();
	GLuint vao;
	int vertCount;
	QOpenGLShaderProgram shader;

	Mandelbrot mandelbrot;
};


