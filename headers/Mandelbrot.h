
#pragma once

#include <QVector2D>
#include <QOpenGLFunctions_3_3_Core>

class Mandelbrot : public QObject, protected QOpenGLFunctions_3_3_Core {
Q_OBJECT
public:
	void init();
	void draw();
	void zoom(double);
public slots:
	void setIterations(int);
private:
	static float* genVertices();
	GLuint createVAO();
	GLuint vao;
	int iterations = 0;
	double scale = 1;
	QVector2D translation;
};


