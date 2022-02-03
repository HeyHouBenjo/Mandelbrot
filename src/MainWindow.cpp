#include <QVBoxLayout>
#include <QSlider>
#include <QLabel>
#include <iostream>
#include "../headers/MainWindow.h"

MainWindow::MainWindow() {
	buildUI();
}

void MainWindow::buildUI() {
	resize(700, 700);

	auto iterationsCaption = new QLabel("Iteration count:");
	auto iterationsLabel = new QLabel;
	//iterationsLabel->setAlignment(Qt::AlignRight);
	auto iterationsSlider = new QSlider(Qt::Horizontal);
	iterationsSlider->setRange(5, 300);
	connect(
			iterationsSlider,
			&QSlider::valueChanged,
			this,
			[iterationsLabel, this](int value) -> void {
				this->outputWidget->getMandelbrot()->setIterations(value);
				this->outputWidget->update();
				iterationsLabel->setNum(value);
			});
	iterationsSlider->setValue(100);

	auto limitCaption = new QLabel("Diverge threshold:");
	auto limitLabel = new QLabel;
	//limitLabel->setAlignment(Qt::AlignRight);
	auto limitSlider = new QSlider(Qt::Horizontal);
	limitSlider->setRange(100, 500);
	connect(
			limitSlider,
			&QSlider::valueChanged,
			this,
			[limitLabel, this](int value) -> void {
				this->outputWidget->getMandelbrot()->updateLimit(value);
				this->outputWidget->update();
				limitLabel->setNum(double(value) / 100);
			});
	limitSlider->setValue(200);

	auto controls = new QGridLayout;
	controls->addWidget(iterationsCaption, 1, 1);
	controls->addWidget(iterationsLabel, 1, 2);
	controls->addWidget(iterationsSlider, 1, 3);
	controls->addWidget(limitCaption, 2, 1);
	controls->addWidget(limitLabel, 2, 2);
	controls->addWidget(limitSlider, 2, 3);

	auto lyt = new QVBoxLayout(this);
	lyt->addWidget(outputWidget);
	lyt->addLayout(controls);
}

void MainWindow::iterationsSliderChanged(int newValue) {
	//TODO update text label
	outputWidget->update();
}

void MainWindow::limitSliderChanged(int newValue) {
	//TODO update text label
	outputWidget->update();
}
