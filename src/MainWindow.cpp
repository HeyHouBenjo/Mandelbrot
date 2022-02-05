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

	auto maxIterationsCaption = new QLabel("Max iteration count: ");
	auto maxIterationsLabel = new QLabel;
	maxIterationsLabel->setFixedWidth(50);
	maxIterationsLabel->setAlignment(Qt::AlignVCenter | Qt::AlignRight);
	auto maxIterationsSlider = new QSlider(Qt::Horizontal);
	maxIterationsSlider->setRange(5, 1000);
	connect(
			maxIterationsSlider,
			&QSlider::valueChanged,
			this,
			[maxIterationsLabel, this](int value) -> void {
				this->outputWidget.getMandelbrot().setMaxIterations(value);
				this->outputWidget.update();
				maxIterationsLabel->setNum(value);
			});
	maxIterationsSlider->setValue(100);

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
	controls->addWidget(maxIterationsCaption, 1, 1);
	controls->addWidget(maxIterationsLabel, 1, 2);
	controls->addWidget(maxIterationsSlider, 1, 3);
	controls->addWidget(saveInfo, 2, 1, 1, 2);
	controls->addWidget(saveButton, 2, 3, 1, 1);
	controls->addWidget(animButton, 3, 1, 1, 3);

	auto lyt = new QVBoxLayout(this);
	lyt->addWidget(&outputWidget);
	lyt->addLayout(controls);
}
