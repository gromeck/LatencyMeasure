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
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <stdlib.h>
#include <unistd.h>
#include <QMainWindow>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QBoxLayout>
#include <QLayout>
#include <QTimer>

#define USEC_PER_MSEC	1000

#define STYLE_RED_ON_BLACK	"background-color:black;color:red;"
#define STYLE_RED_ON_WHITE	"background-color:white;color:red;"

namespace Ui {
    class MainWindow;
}

class MainWindow: public QMainWindow {
	Q_OBJECT

	public:
		explicit MainWindow(QWidget *parent = 0);
		~MainWindow();

	private:
		QWidget *mainWidget;
		QVBoxLayout *layout;
		QLabel *latencyLabel;
		QLineEdit *latencyInput;
		QPushButton *toggleButton;
		QPushButton *triggerButton;
		QLabel *sensorArea;
		QTimer *timerBlack,*timerWhite;
		bool toggle;

	private slots:
		void clickedToggleButton();
		void clickedTriggerButton();
		void timeoutTimerRise();
		void timeoutTimerFall();
};

#endif
