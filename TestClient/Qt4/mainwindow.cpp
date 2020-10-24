/*

	LatencyTest with Qt4

	(c) 2020 by Christian.Lorenz@gromeck.de


	This file is part of LatencyMeasure.

    LatencyMeasure is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    LatencyMeasure is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with LatencyMeasure.  If not, see <https://www.gnu.org/licenses/>.

*/
#include <stdlib.h>
#include <unistd.h>
#include "mainwindow.h"

#define __TITLE__	"Qt4 TestClient for LatencyMeasure"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{	
	toggle = false;

	mainWidget = new QWidget();
	this->setWindowTitle(__TITLE__);
	this->setCentralWidget(mainWidget);

	this->setFixedSize(300,340);
	latencyLabel = new QLabel("Latency to add [ms]:");
	latencyLabel->setFixedHeight(30);
	latencyInput = new QLineEdit("0");
	latencyInput->setMaxLength(5);
	latencyInput->setInputMask("00000");

	toggleButton = new QPushButton("Toggle sensor areas background");
	connect(toggleButton,SIGNAL(clicked()),this,SLOT(clickedToggleButton()));

	triggerButton = new QPushButton("Place mouse cursor here!");
	connect(triggerButton,SIGNAL(clicked()),this,SLOT(clickedTriggerButton()));

	sensorArea = new QLabel("Place sensor here!");
	//sensorArea->setFixedSize(180,180);
	sensorArea->setStyleSheet(toggle ? STYLE_RED_ON_WHITE : STYLE_RED_ON_BLACK);
	sensorArea->setAlignment(Qt::AlignTop);

	layout = new QVBoxLayout();
	layout->addWidget(latencyLabel);
	layout->addWidget(latencyInput);
	layout->addWidget(toggleButton);
	layout->addWidget(triggerButton);
	layout->addWidget(sensorArea);

	mainWidget->setLayout(layout);

	timerBlack = new QTimer();
	timerBlack->setSingleShot(true);
	connect(timerBlack,SIGNAL(timeout()),this,SLOT(timeoutTimerRise()));

	timerWhite = new QTimer();
	timerWhite->setSingleShot(true);
	connect(timerWhite,SIGNAL(timeout()),this,SLOT(timeoutTimerFall()));
}

void MainWindow::clickedToggleButton()
{
	toggle = !toggle;
	sensorArea->setStyleSheet(toggle ? STYLE_RED_ON_WHITE : STYLE_RED_ON_BLACK);
}

void MainWindow::clickedTriggerButton()
{
	int timeout = latencyInput->text().toInt();
	latencyInput->setText(QString::number(timeout));
	timerBlack->start(timeout);
}

void MainWindow::timeoutTimerRise()
{
	sensorArea->setStyleSheet(!toggle ? STYLE_RED_ON_WHITE : STYLE_RED_ON_BLACK);
	timerWhite->start(500);
}

void  MainWindow::timeoutTimerFall()
{
	sensorArea->setStyleSheet(toggle ? STYLE_RED_ON_WHITE : STYLE_RED_ON_BLACK);
}

MainWindow::~MainWindow()
{
}

/**/
