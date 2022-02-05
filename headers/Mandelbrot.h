#pragma once

#include <QVector2D>
#include <QOpenGLExtraFunctions>
#include <QOpenGLShaderProgram>

class Mandelbrot : public QObject, protected QOpenGLExtraFunctions {
	Q_OBJECT
public:
	void init(GLuint);
	void draw();
	void updateAnimation();
	void toggleAnimation();
	void setIterations(int);
	void translateRelative(QVector2D);
	void zoomRelative(int, QVector2D);
	void resizeRelative(QVector2D);
	bool initShader();
private:
	int iterations = 0;
	float hueAdd = 0.0;
	QVector2D origin {-2, -1};
	QVector2D size {2, 2};
	float zoomModifier = 1.05;

	bool animating = true;

	GLuint vao;

	QOpenGLShaderProgram shader;
	void setShaderValues();
};


