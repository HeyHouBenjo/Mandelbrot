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
	void setMaxIterations(int);
	void translateRelative(QVector2D);
	void zoomRelative(int, QVector2D);
	void resizeRelative(QVector2D);
	bool initShader();
	void initView(QSize);
public slots:
	void toggleAnimation();
	void toggleNormalize();
private:
	const QVector2D startCenter {-0.66, 0};
	const float startMaxSize = 3;

	int maxIterations = 0;
	float hueAdd = 0;
	QVector2D origin;
	QVector2D size;
	float zoomModifier = 1.05;
	bool normalize = true;
	bool animating = true;

	GLuint vao;

	QOpenGLShaderProgram shader;
	void setShaderValues();
};


