
#include <iostream>
#include <QResource>
#include "../headers/OutputWidget.h"

using std::cout, std::endl;

void OutputWidget::initializeGL() {
	cout << "Initialize OpenGL" << endl;
	initializeOpenGLFunctions();
	getMandelbrot()->init();
	initShader();

	auto format = this->format();
	cout << "OpenGL version: " << format.majorVersion() << "." << format.minorVersion() << endl;

	vao = createVAO();

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
}

void OutputWidget::paintGL() {
	glClear(GL_COLOR_BUFFER_BIT);
	getMandelbrot()->draw(vao, vertCount, shader);
}

void OutputWidget::resizeGL(int w, int h) {
	//glViewport(0, 0, w, h);
}

GLuint OutputWidget::createVAO() {
	GLuint vboId;
	glGenBuffers(1, &vboId);
	glBindBuffer(GL_ARRAY_BUFFER, vboId);

	auto vertices = genVertices();
	size_t size = vertices.size() * sizeof(QVector2D);
	vertCount = int(vertices.size());
	glBufferData(GL_ARRAY_BUFFER, (GLsizeiptr)size, &vertices[0], GL_STATIC_DRAW);

	GLuint vaoId;
	glGenVertexArrays(1, &vaoId);
	glBindVertexArray(vaoId);
	glBindBuffer(GL_ARRAY_BUFFER, vboId);

	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(QVector2D), (GLvoid const*) 0);
	glEnableVertexAttribArray(0);

	glBindVertexArray(0);

	return vaoId;
}

std::vector<QVector2D> OutputWidget::genVertices() {
	return {
			{-1, -1},
			{1, -1},
			{1, 1},
			{-1, 1}
	};
}

void OutputWidget::initShader() {
	if (!shader.addShaderFromSourceFile(QOpenGLShader::Vertex, "Vertex.glsl")) close();
	if (!shader.addShaderFromSourceFile(QOpenGLShader::Fragment, "Fragment.glsl")) close();
	if (!shader.link()) close();
	if (!shader.bind()) close();
}

void OutputWidget::wheelEvent(QWheelEvent *e) {

}

void OutputWidget::mouseMoveEvent(QMouseEvent *e) {

}

void OutputWidget::mousePressEvent(QMouseEvent *e) {

}

void OutputWidget::mouseReleaseEvent(QMouseEvent *e) {

}

void OutputWidget::keyPressEvent(QKeyEvent *e) {

}
