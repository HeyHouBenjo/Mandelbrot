#pragma once

#include <QVector2D>
#include <QOpenGLExtraFunctions>
#include <QOpenGLShaderProgram>

class Mandelbrot : public QObject, protected QOpenGLExtraFunctions {
Q_OBJECT
public:
	void init();
	void draw(GLuint, QOpenGLShaderProgram&);
	void zoom(double);
public slots:
	void setIterations(int);
private:
	int iterations = 0;
	double scale = 1;
	QVector2D translation;
	void setShaderValues(QOpenGLShaderProgram&);
};


