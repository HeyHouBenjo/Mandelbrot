
#pragma once


#include <QWidget>
#include <QOpenGLFunctions>
#include <QOpenGLWidget>

class OutputWidget : public QOpenGLWidget, protected QOpenGLFunctions {
	Q_OBJECT
private:
	void initializeGL() override;
	void paintGL() override;
	void resizeGL(int, int) override;

	void wheelEvent(QWheelEvent*) override;
	void mouseMoveEvent(QMouseEvent*) override;
	void mousePressEvent(QMouseEvent*) override;
	void mouseReleaseEvent(QMouseEvent*) override;
	void keyPressEvent(QKeyEvent*) override;
};


