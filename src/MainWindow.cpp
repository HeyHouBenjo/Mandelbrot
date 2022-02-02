#include <QVBoxLayout>
#include <QSlider>
#include <iostream>
#include "../headers/MainWindow.h"

MainWindow::MainWindow() {
	buildUI();
}

void MainWindow::buildUI() {

	auto sizeSlider = new QSlider(Qt::Horizontal);
	sizeSlider->setRange(100, 800);
	QSlider::connect(sizeSlider, &QSlider::valueChanged, this, &MainWindow::sizeSliderChanged);
	sizeSlider->setValue(500);

	auto controls = new QGridLayout;
	controls->addWidget(sizeSlider);

	auto lyt = new QVBoxLayout(this);
	lyt->addWidget(outputWidget);
	lyt->addLayout(controls);
}

//TODO Handle size change
void MainWindow::sizeSliderChanged(int newValue) {

}
