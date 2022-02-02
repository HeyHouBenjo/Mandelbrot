#pragma once

#include <QWidget>
#include "OutputWidget.h"

class MainWindow : public QWidget {
	Q_OBJECT
public:
	explicit MainWindow();
private slots:
	void sizeSliderChanged(int);
private:
	void buildUI();

	OutputWidget* outputWidget = new OutputWidget;
};


