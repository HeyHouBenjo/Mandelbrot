#pragma once

#include <QVector2D>
#include <QOpenGLExtraFunctions>
#include <QOpenGLShaderProgram>

class Mandelbrot : public QObject, protected QOpenGLExtraFunctions {
Q_OBJECT
public:
	void init();
	void draw(GLuint, QOpenGLShaderProgram&);
	void setIterations(int);
	void translateRelative(QVector2D);
	void zoomRelative(double, QVector2D);
private:
	int iterations = 0;
	QVector2D origin {-2, 1};
	QVector2D size {2, 2};
	void setShaderValues(QOpenGLShaderProgram&) const;
};


