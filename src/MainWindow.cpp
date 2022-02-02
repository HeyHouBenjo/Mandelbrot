#include <QVBoxLayout>
#include <QSlider>
#include <iostream>
#include "../headers/MainWindow.h"

MainWindow::MainWindow(QWidget *parent): QWidget(parent) {
	buildUI();
}

void MainWindow::buildUI() {

	auto sizeSlider = new QSlider(Qt::Horizontal);
	sizeSlider->setRange(100, 800);
	QSlider::connect(sizeSlider, &QSlider::valueChanged, this, &MainWindow::sizeChanged);
	sizeSlider->setValue(500);

	auto controls = new QGridLayout;
	controls->addWidget(sizeSlider);

	QVBoxLayout lyt;

	lyt.addWidget(outputWidget);
	lyt.addLayout(controls);

	setLayout(&lyt);
}

void MainWindow::sizeChanged(int newValue) {
	std::cout << newValue << std::endl;
}
