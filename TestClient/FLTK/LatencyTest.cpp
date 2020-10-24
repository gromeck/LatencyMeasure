/*

	LatencyTest with FLTK 1.3

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
#include <FL/Fl.H>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Int_Input.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Box.H>
#include <FL/fl_ask.H>

#define __TITLE__	"FLTK TestClient for LatencyMeasure"

static Fl_Double_Window* window;
static Fl_Box *latencyLabel;
static Fl_Int_Input *latencyInput;
static Fl_Button *toggleButton;
static Fl_Button *triggerButton;
static Fl_Box *sensorArea;

static bool toggle = false;

static void timeoutTimerFall(void *)
{
	sensorArea->color(toggle ? FL_WHITE : FL_BLACK);
	sensorArea->redraw();
}

static void timeoutTimerRise(void *)
{
	sensorArea->color(!toggle ? FL_WHITE : FL_BLACK);
	sensorArea->redraw();
	Fl::add_timeout(0.5,timeoutTimerFall);
}

static void clickedToggleButton(Fl_Widget *widget)
{
	toggle = !toggle;
	sensorArea->color(toggle ? FL_WHITE : FL_BLACK);
	sensorArea->redraw();
}

static void clickedTriggerButton(Fl_Widget *widget)
{
	char buffer[10];

	int timeout = atoi(latencyInput->value());
	sprintf(buffer,"%d",timeout);
	latencyInput->value(buffer);
	Fl::add_timeout((double) timeout / 1000,timeoutTimerRise);
}

int main(int argc,char **argv)
{
	window = new Fl_Double_Window(300,340,__TITLE__);

	latencyLabel = new Fl_Box(10,10,280,30,"Latency to add [ms]:");
	latencyLabel->align(FL_ALIGN_INSIDE|FL_ALIGN_LEFT|FL_ALIGN_TOP);

	latencyInput = new Fl_Int_Input(10,40,280,30,"");
	latencyInput->color((Fl_Color) 55);
	latencyInput->value("0");
	latencyInput->maximum_size(5);

	toggleButton = new Fl_Button(10,80,280,30,"Toggle sensors area background");
	toggleButton->callback(clickedToggleButton);

	triggerButton = new Fl_Button(10,120,280,30,"Place mouse cursor here!");
	triggerButton->callback(clickedTriggerButton);

	sensorArea = new Fl_Box(FL_FRAME_BOX,10,160,280,170,"Place sensor here!");
	sensorArea->align(FL_ALIGN_INSIDE|FL_ALIGN_LEFT|FL_ALIGN_TOP);
	sensorArea->color(FL_BLACK);
	sensorArea->labelcolor(FL_RED);

	window->end();
	window->show(argc,argv);

	return Fl::run();
}/**/
