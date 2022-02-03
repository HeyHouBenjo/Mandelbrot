
#pragma once

#include <QVector2D>
#include <QOpenGLFunctions>

class Mandelbrot : public QObject, protected QOpenGLFunctions {
Q_OBJECT
public:
	void init();
	void draw();
	void zoom(double);
public slots:
	void setIterations(int);
private:
	int iterations = 0;
	double scale = 1;
	QVector2D translation;
};


