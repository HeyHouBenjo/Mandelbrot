
#pragma once

#include <QVector2D>
#include <QOpenGLFunctions>

class Mandelbrot : protected QOpenGLFunctions {
public:
	Mandelbrot();
	void draw();
	void zoom(double);
private:
	double scale;
	QVector2D translation;
};


