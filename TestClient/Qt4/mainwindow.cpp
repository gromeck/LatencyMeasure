#include <stdlib.h>
#include <unistd.h>
#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{	
	toggle = false;

	mainWidget = new QWidget();
	this->setCentralWidget(mainWidget);

	this->setFixedSize(300,340);
	label = new QLabel("Latency to add [ms]:");
	latency = new QLineEdit("0");
	latency->setMaxLength(5);
	latency->setInputMask("00000");

	toggleButton = new QPushButton("Toggle sensor areas background");
	connect(toggleButton,SIGNAL(clicked()),this,SLOT(clickedToggleButton()));

	triggerButton = new QPushButton("Place mouse cursor here!");
	connect(triggerButton,SIGNAL(clicked()),this,SLOT(clickedTriggerButton()));

	sensorarea = new QLabel("Place sensor here!");
	sensorarea->setFixedSize(180,180);
	sensorarea->setStyleSheet(toggle ? STYLE_RED_ON_WHITE : STYLE_RED_ON_BLACK);
	sensorarea->setAlignment(Qt::AlignTop);

	layout = new QVBoxLayout();
	layout->addWidget(label);
	layout->addWidget(latency);
	layout->addWidget(toggleButton);
	layout->addWidget(triggerButton);
	layout->addWidget(sensorarea);

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
	sensorarea->setStyleSheet(toggle ? STYLE_RED_ON_WHITE : STYLE_RED_ON_BLACK);
}

void MainWindow::clickedTriggerButton()
{
	int timeout = latency->text().toInt();
	latency->setText(QString::number(timeout));
	timerBlack->start(timeout);
}

void MainWindow::timeoutTimerRise()
{
	sensorarea->setStyleSheet(!toggle ? STYLE_RED_ON_WHITE : STYLE_RED_ON_BLACK);
	timerWhite->start(500);
}

void  MainWindow::timeoutTimerFall()
{
	sensorarea->setStyleSheet(toggle ? STYLE_RED_ON_WHITE : STYLE_RED_ON_BLACK);
}

MainWindow::~MainWindow()
{
}

/**/
