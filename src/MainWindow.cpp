#include <QVBoxLayout>
#include <QSlider>
#include <QLabel>
#include <iostream>
#include "../headers/MainWindow.h"

MainWindow::MainWindow(): outputWidget(OutputWidget(this)) {
	buildUI();
}

void MainWindow::buildUI() {
	resize(700, 700);

	auto iterationsCaption = new QLabel("Iteration count: ");
	auto iterationsLabel = new QLabel;
	iterationsLabel->setFixedWidth(50);
	iterationsLabel->setAlignment(Qt::AlignVCenter | Qt::AlignRight);
	auto iterationsSlider = new QSlider(Qt::Horizontal);
	iterationsSlider->setRange(5, 1000);
	connect(
			iterationsSlider,
			&QSlider::valueChanged,
			this,
			[iterationsLabel, this](int value) -> void {
				this->outputWidget.getMandelbrot().setIterations(value);
				this->outputWidget.update();
				iterationsLabel->setNum(value);
			});
	iterationsSlider->setValue(100);

	auto controls = new QGridLayout;
	controls->addWidget(iterationsCaption, 1, 1);
	controls->addWidget(iterationsLabel, 1, 2);
	controls->addWidget(iterationsSlider, 1, 3);

	auto lyt = new QVBoxLayout(this);
	lyt->addWidget(&outputWidget);
	lyt->addLayout(controls);
}
