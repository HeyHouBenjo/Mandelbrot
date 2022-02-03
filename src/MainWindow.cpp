#include <QVBoxLayout>
#include <QSlider>
#include <iostream>
#include "../headers/MainWindow.h"

MainWindow::MainWindow() {
	buildUI();
}

void MainWindow::buildUI() {
	resize(700, 700);

	auto iterationsSlider = new QSlider(Qt::Horizontal);
	iterationsSlider->setRange(5, 300);
	QSlider::connect(
			iterationsSlider,
			&QSlider::valueChanged,
			this->outputWidget->getMandelbrot(),
			&Mandelbrot::setIterations
			);
	QSlider::connect(
			iterationsSlider,
			&QSlider::valueChanged,
			this,
			&MainWindow::iterationsSliderChanged
			);

	iterationsSlider->setValue(100);

	auto controls = new QGridLayout;
	controls->addWidget(iterationsSlider);

	auto lyt = new QVBoxLayout(this);
	lyt->addWidget(outputWidget);
	lyt->addLayout(controls);
}

void MainWindow::iterationsSliderChanged(int newValue) {
	//TODO update text label
	update();
}
