#pragma once

#include <QWidget>
#include "OutputWidget.h"

class MainWindow : public QWidget {
	Q_OBJECT
public:
	explicit MainWindow(QWidget *parent = nullptr);
public slots:
	void sizeChanged(int newValue);
private:
	void buildUI();

	OutputWidget* outputWidget = new OutputWidget;
};


