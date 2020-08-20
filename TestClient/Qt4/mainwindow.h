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
		QLabel *label;
		QLineEdit *latency;
		QPushButton *toggleButton;
		QPushButton *triggerButton;
		QLabel *sensorarea;
		QTimer *timerBlack,*timerWhite;
		bool toggle;

	private slots:
		void clickedToggleButton();
		void clickedTriggerButton();
		void timeoutTimerRise();
		void timeoutTimerFall();
};

#endif
