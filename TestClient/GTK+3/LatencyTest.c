/*

	LatencyTest with GTK+-3

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
#include <gdk/gdk.h>
#include <gtk/gtk.h>

#define USEC_PER_MSEC	1000

static int toggle = FALSE;

static GdkRGBA colorBlack;
static GdkRGBA colorWhite;
static GtkWidget *window;
static GtkWidget *container;
static GtkWidget *latencyLabel;
static GtkWidget *latencyInput;
static GtkWidget *toggleButton;
static GtkWidget *triggerButton;
static GtkWidget *sensorArea;

static gboolean timeoutTimerFall(gpointer data)
{
	gtk_widget_override_background_color(sensorArea,GTK_STATE_FLAG_NORMAL,toggle ? &colorWhite : &colorBlack);
	return FALSE;
}

static gboolean timeoutTimerRise(gpointer data)
{
	gtk_widget_override_background_color(sensorArea,GTK_STATE_FLAG_NORMAL,!toggle ? &colorWhite : &colorBlack);
	g_timeout_add(500,timeoutTimerFall,NULL);
	return FALSE;
}

static void clickedToggleButton(GtkApplication* app,gpointer user_data)
{
	toggle = !toggle;
	gtk_widget_override_background_color(sensorArea,GTK_STATE_FLAG_NORMAL,toggle ? &colorWhite : &colorBlack);
}

static void clickedTriggerButton(GtkApplication* app,gpointer user_data)
{
	char buffer[10];

	int timeout = atoi(gtk_entry_get_text(GTK_ENTRY(latencyInput)));
	sprintf(buffer,"%d",timeout);
	gtk_entry_set_text(GTK_ENTRY(latencyInput),buffer);
	g_timeout_add(timeout,timeoutTimerRise,NULL);
}

static void openMainWindow(GtkApplication* app,gpointer user_data)
{
	gdk_rgba_parse(&colorBlack,"black");
	gdk_rgba_parse(&colorWhite,"white");

	window = gtk_application_window_new(app);
	gtk_window_set_title(GTK_WINDOW(window),"LatencyTest");
	gtk_window_set_default_size(GTK_WINDOW(window),300,340);
	gtk_window_set_resizable(GTK_WINDOW(window),FALSE);

	latencyLabel = gtk_label_new("Latency to add [ms]:");
	gtk_label_set_xalign(GTK_LABEL(latencyLabel),0.0);

	latencyInput = gtk_entry_new();
	gtk_entry_set_max_length(GTK_ENTRY(latencyInput),5);
	gtk_entry_set_input_purpose(GTK_ENTRY(latencyInput),GTK_INPUT_PURPOSE_DIGITS);
	gtk_entry_set_text(GTK_ENTRY(latencyInput),"0");

	toggleButton = gtk_button_new_with_label("Toggle sensor areas background");
	gtk_widget_set_can_focus(toggleButton,FALSE);
	g_signal_connect(toggleButton,"clicked",G_CALLBACK(clickedToggleButton),NULL);

	triggerButton = gtk_button_new_with_label("Place mouse cursor here!");
	gtk_widget_set_can_focus(triggerButton,FALSE);
	g_signal_connect(triggerButton,"clicked",G_CALLBACK(clickedTriggerButton),NULL);

	sensorArea = gtk_label_new("");
	gtk_label_set_xalign(GTK_LABEL(sensorArea),0.0);
	gtk_label_set_yalign(GTK_LABEL(sensorArea),0.0);
	gtk_label_set_markup(GTK_LABEL(sensorArea),"<span foreground=\"red\">Place sensor here!</span>");
	gtk_widget_override_background_color(sensorArea,GTK_STATE_FLAG_NORMAL,&colorBlack);
	gtk_widget_set_vexpand(sensorArea,TRUE);

	container = gtk_box_new(GTK_ORIENTATION_VERTICAL,10);
	gtk_container_set_border_width(GTK_CONTAINER(window),10);
	gtk_container_add(GTK_CONTAINER(container),latencyLabel);
	gtk_container_add(GTK_CONTAINER(container),latencyInput);
	gtk_container_add(GTK_CONTAINER(container),toggleButton);
	gtk_container_add(GTK_CONTAINER(container),triggerButton);
	gtk_container_add(GTK_CONTAINER(container),sensorArea);
	gtk_container_add(GTK_CONTAINER(window),container);

	gtk_widget_show_all(window);
}

int main(int argc,char **argv)
{
	GtkApplication *app;
	int status;

	app = gtk_application_new(NULL,G_APPLICATION_FLAGS_NONE);
	g_signal_connect(app,"activate",G_CALLBACK(openMainWindow),NULL);

	status = g_application_run(G_APPLICATION(app),argc,argv);
	g_object_unref(app);

	return status;
}/**/
