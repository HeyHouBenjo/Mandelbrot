#include <QVBoxLayout>
#include <QSlider>
#include <QLabel>
#include <iostream>
#include <QPushButton>
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

	auto saveInfo = new QLabel;
	auto saveButton = new QPushButton("Save high resolution image");
	connect(
			saveButton,
			&QPushButton::clicked,
			this,
			[this, saveInfo](){
				saveInfo->setText("Receiving image...");
				update();
				this->outputWidget.saveToImage([saveInfo](){
					saveInfo->setText("Saving...");
				}, [saveInfo](bool success){
					QString result = success ? "Success" : "Failure";
					saveInfo->setText(result);
				});
			});

	auto animButton = new QPushButton("Toggle animation");
	connect(
			animButton,
			&QPushButton::clicked,
			this,
			[this](){
				this->outputWidget.getMandelbrot().toggleAnimation();
			});

	auto controls = new QGridLayout;
	controls->addWidget(iterationsCaption, 1, 1);
	controls->addWidget(iterationsLabel, 1, 2);
	controls->addWidget(iterationsSlider, 1, 3);
	controls->addWidget(saveInfo, 2, 1, 1, 2);
	controls->addWidget(saveButton, 2, 3, 1, 1);
	controls->addWidget(animButton, 3, 1, 1, 3);

	auto lyt = new QVBoxLayout(this);
	lyt->addWidget(&outputWidget);
	lyt->addLayout(controls);
}
