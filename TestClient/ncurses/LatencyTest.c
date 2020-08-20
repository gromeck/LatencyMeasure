#include <unistd.h>
#include <string.h>
#include <ncurses.h>

#define __TITLE__	"LatencyTest with ncurses"

#define WIN_HEIGHT		22
#define WIN_WIDTH		60

#define TEXTAREA_HEIGHT		(WIN_HEIGHT / 2 - 1)
#define TEXTAREA_WIDTH		(WIN_WIDTH - 4)

#define SENSORAREA_HEIGHT		(WIN_HEIGHT / 2 - 1)
#define SENSORAREA_WIDTH		(WIN_WIDTH - 2)

#define MAX_LATENCY			5000

void setup_window(int ch)
{
	static WINDOW *_win = NULL;
	static WINDOW *_textarea = NULL;
	static WINDOW *_sensorarea = NULL;
	static int _win_x = 0,_win_y = 0;
	static bool _toggle = false;
	bool moved = false;
	bool redraw = false;
	static int latency = 0;

	if (!_win) {
		/*
		**	create the window
		*/
		_win_x = (COLS - WIN_WIDTH) / 2;
		_win_y = (LINES - WIN_HEIGHT) / 2;
		_win = newwin(WIN_HEIGHT,WIN_WIDTH,0,0);
		_textarea = newwin(TEXTAREA_HEIGHT,TEXTAREA_WIDTH,0,0);
		_sensorarea = newwin(SENSORAREA_HEIGHT,SENSORAREA_WIDTH,0,0);
		moved = true;
	}

	switch (ch) {
		case KEY_LEFT:
			if (_win_x > 0) {
				--_win_x;
				moved = true;
			}
			break;
		case KEY_RIGHT:
			if (_win_x < COLS - WIN_WIDTH) {
				++_win_x;
				moved = true;
			}
			break;
		case KEY_UP:
			if (_win_y > 0) {
				--_win_y;
				moved = true;
			}
			break;
		case KEY_DOWN:
			if (_win_y < LINES - WIN_HEIGHT) {
				++_win_y;
				moved = true;
			}
			break;

			/*
			**	increase the latency
			*/
		case '*':
			latency += 9;
		case '+':
			latency++;
			if (latency > MAX_LATENCY)
				latency = MAX_LATENCY;
			redraw = true;
			break;

			/*
			**	decrease the latency
			*/
		case '_':
			latency -= 9;
		case '-':
			latency--;
			if (latency < 0)
				latency = 0;
			redraw = true;
			break;

		case 't':
			/*
			**	toggle background/foreground of the sensor area
			*/
			_toggle = !_toggle;
			redraw = true;
			break;

		case '\n':
		case ' ':
			/*
			**	trigger
			*/
			if (latency)
				napms(latency);
			wbkgd(_sensorarea,COLOR_PAIR((!_toggle) ? 3 : 2));
			wrefresh(_sensorarea);
			refresh();
			napms(500);
			wbkgd(_sensorarea,COLOR_PAIR((_toggle) ? 3 : 2));
			wrefresh(_sensorarea);
			break;
		default:
			printf("char=%d 0%o 0x%x\n",ch,ch,ch);
	}
	if (moved) {
		mvwin(_win,_win_y,_win_x);
		mvwin(_textarea,_win_y + 2,_win_x + (WIN_WIDTH - TEXTAREA_WIDTH) / 2);
		mvwin(_sensorarea,_win_y + (WIN_HEIGHT - SENSORAREA_HEIGHT) - 1,_win_x + (WIN_WIDTH - SENSORAREA_WIDTH) / 2);
		redraw = true;
	}

	if (redraw) {
		/*
		**	redraw the window
		*/
		char buffer[1000];

		clear();
		refresh();

		wclear(_win);
		wbkgd(_win,COLOR_PAIR(1));
		wattrset(_win,A_NORMAL);
		box(_win,0,0);
		wattron(_win,A_BOLD|A_REVERSE);
		mvwaddstr(_win,0,(WIN_WIDTH - strlen(" " __TITLE__ " ")) / 2," " __TITLE__ " ");
		wrefresh(_win);

		wclear(_textarea);
		wbkgd(_textarea,COLOR_PAIR(1));
		sprintf(buffer,
			"Latency to add [ms]: %d\n"
			"\nPress <cursor-keys> to place window on your screen,"
			"\npress '+'/'-' to change latency to add,"
			"\n hold SHIFT to speed-up by 10,"
			"\npress 't' to toggle sensor areas background,"
			"\npress RETURN or SPACE to trigger,"
			"\npress 'q' to quit.",
			latency);
		wattrset(_textarea,A_BOLD);
		wprintw(_textarea,buffer);
		wrefresh(_textarea);

		wclear(_sensorarea);
		wbkgd(_sensorarea,COLOR_PAIR((_toggle) ? 3 : 2));
		wattrset(_sensorarea,A_BOLD);
		wprintw(_sensorarea,"Place the sensor here!");
		wrefresh(_sensorarea);
	}
	refresh();
}

int main()
{
	int ch;

	/*
	**	init ncurses
	*/
	initscr();
	cbreak();
	noecho();
	//curs_set(FALSE);
	keypad(stdscr, TRUE);
	start_color();
	init_color(COLOR_BLACK,0,0,0);
	init_color(COLOR_WHITE,1000,1000,1000);
	init_color(COLOR_RED,1000,0,0);
	init_color(COLOR_BLUE,0,0,700);
	init_pair(1,COLOR_WHITE,COLOR_BLUE);
	init_pair(2,COLOR_RED,COLOR_BLACK);
	init_pair(3,COLOR_RED,COLOR_WHITE);

	setup_window(0);

	while ((ch = getch()) != 'q') {
		setup_window(ch);
	}

	/*
	**	wer're done
	*/
	endwin();

	return 0;
}
