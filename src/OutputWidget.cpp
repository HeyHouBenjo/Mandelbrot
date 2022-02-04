#include <iostream>
#include <QResource>
#include <thread>
#include <future>
#include <QOpenGLFramebufferObject>
#include <QFileDialog>
#include <utility>
#include "../headers/OutputWidget.h"

using std::cout, std::endl;

void OutputWidget::initializeGL() {
	cout << "Initialize OpenGL" << endl;
	initializeOpenGLFunctions();
	getMandelbrot().init(createVAO());
	if (!getMandelbrot().initShader()) close();

	auto format = this->format();
	cout << "OpenGL version: " << format.majorVersion() << "." << format.minorVersion() << endl;

	glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
}

void OutputWidget::paintGL() {
	getMandelbrot().draw();
}

std::vector<QVector2D> genVertices() {
	return {
			{-1, -1},
			{1, -1},
			{1, 1},
			{1, 1},
			{-1, 1},
			{-1, -1}
	};
}

GLuint OutputWidget::createVAO() {
	GLuint vboId;
	glGenBuffers(1, &vboId);
	glBindBuffer(GL_ARRAY_BUFFER, vboId);

	auto vertices = genVertices();
	size_t size = vertices.size() * sizeof(QVector2D);
	glBufferData(GL_ARRAY_BUFFER, (GLsizeiptr)size, &vertices[0], GL_STATIC_DRAW);

	GLuint vaoId;
	glGenVertexArrays(1, &vaoId);
	glBindVertexArray(vaoId);
	glBindBuffer(GL_ARRAY_BUFFER, vboId);

	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(QVector2D), (void*) nullptr);
	glEnableVertexAttribArray(0);

	glBindVertexArray(0);

	return vaoId;
}

QVector2D divide(QPoint p, QSize s){
	return {
			float(p.x()) / float(s.width()),
			float(p.y()) / float(s.height())
	};
}
QVector2D divide(QSize s1, QSize s2){
	return divide(QPoint(s1.width(), s1.height()), s2);
}

void OutputWidget::resizeGL(int w, int h) {
	QSize newSize = QSize(w, h);
	if (oldSize == QSize(0, 0)){
		oldSize = newSize;
		return;
	}
	QSize diff = oldSize - newSize;
	QVector2D relative = QVector2D(1, 1) - divide(diff, oldSize);
	getMandelbrot().resizeRelative(relative);
	oldSize = newSize;
}

void OutputWidget::wheelEvent(QWheelEvent *e) {
	QPoint pos = e->position().toPoint();
	int direction = e->angleDelta().y() > 0 ? 1 : -1;
	QVector2D relativePos = divide(pos, size());
	relativePos.setY(1 - relativePos.y());
	getMandelbrot().zoomRelative(direction, relativePos);
	update();
}

void OutputWidget::mouseMoveEvent(QMouseEvent *e) {
	QPoint newMousePos = e->pos();
	QPoint diff = newMousePos - mousePos;
	mousePos = newMousePos;
	QVector2D relativeDiff = divide(diff, size());
	relativeDiff.setY(-relativeDiff.y());
	getMandelbrot().translateRelative(relativeDiff);
	update();
}

void OutputWidget::mousePressEvent(QMouseEvent *e) {
	mousePos = e->pos();
}

void OutputWidget::mouseReleaseEvent(QMouseEvent *e) {

}

void OutputWidget::keyPressEvent(QKeyEvent *e) {

}

void OutputWidget::saveToImage(const std::function<void(void)>& receiveCb, const std::function<void(bool)>& saveCb) {
	double maxSize = pow(2, 14);

	double div = double(width()) / height();
	int w, h;
	if (div > 1){
		w = int(maxSize);
		h = int(maxSize / div);
	} else {
		h = int(maxSize);
		w = int(maxSize * div);
	}

	QOpenGLFramebufferObject fbo(w, h);
	fbo.bind();

	glViewport(0, 0, w, h);
	getMandelbrot().draw();
	QOpenGLFramebufferObject::bindDefault();

	QImage img = fbo.toImage();
	receiveCb();

	QString fileName = QFileDialog::getSaveFileName(this, "", "", tr("Images (*.png *.xpm *.jpg)"));
	if (fileName.isNull()){
		saveCb(false);
		return;
	}

	std::thread job([saveCb](const QImage& img, const QString& fileName) {
		saveCb(img.save(fileName));
	}, img, fileName);
	job.detach();
}
