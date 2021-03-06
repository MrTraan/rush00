#include "../includes/NDisplay.hpp"
//#include <InputManager.class.hpp>
#include "../includes/Game.class.hpp"
#include <signal.h>

int NDisplay::sNbWindows = 0;

void resizeHandler(int u)
{
	u = 0;
	Game::triggerLose();
	std::cout<<"resize not allowed !"<<std::endl;
}

NDisplay::NDisplay(int l, int r) {
	initscr();
	//color handling
	start_color();
	init_color(COLOR_CYAN, 150,150, 150);
	init_color(COLOR_RED, 900,0, 0);
	init_pair(1, COLOR_CYAN,COLOR_BLACK);
	init_pair(2, COLOR_RED,COLOR_BLACK);
	//end color

	_boundaries.x = l;
	_boundaries.y = r;

	cbreak();
	noecho();
	keypad(stdscr, TRUE);
	timeout(1);
	curs_set(FALSE);
	signal(SIGWINCH, resizeHandler);
	for (int i = 0; i < NB_W_MAX; i++)
		_Windows[i] = NULL;
}

NDisplay::NDisplay(NDisplay const& src) {
	// std::cout<<"Copy constructor called"<<std::endl;
	*this = src;
}

NDisplay::~NDisplay(void) {
	endwin();
	// std::cout<<"Destructor called"<<std::endl;
}
void NDisplay::draw(Shape& shape) {
	if (shape.getshape() == "o")
		 attron(COLOR_PAIR(1));
	for (int i = 0; i < shape.getHeight(); i++)
		for (int j = 0; j < shape.getWidth(); j++)
			print(shape.getshape()[i * shape.getWidth() + j],
			      shape.getPosX() + j, shape.getPosY() + i);
	 attroff(COLOR_PAIR(1));
}

void NDisplay::print(char c) {
	addch(c);
}

void NDisplay::print(char c, int x, int y) {
	mvaddch(y, x, c);
}

void NDisplay::print(int id, char c, int x, int y) {
	if (id < NB_W_MAX && id < NDisplay::sNbWindows)
		mvwaddch(_Windows[id], y, x, c);
	else
		prints("ERROR: Index refers to a windows that doesn't exist", 1, 1);
}
void NDisplay::prints(std::string s) {
	printw(s.c_str());
}

void NDisplay::prints(std::string s, int x, int y) {
	mvprintw(y, x, s.c_str());
}
void NDisplay::prints(int id, std::string s, int x, int y) {
	if (id < NB_W_MAX && id < NDisplay::sNbWindows)
		mvwprintw(_Windows[id], y, x, s.c_str());
	else
		prints("ERROR: Index is too big", 1, 1);
}

void NDisplay::rfh(void) {
	refresh();
}

void NDisplay::clr(void) {
	clear();
}

void NDisplay::clrW(int id) {
	wclear(_Windows[id]);
}

void NDisplay::waitForQuit() {}



void NDisplay::subWinStdr(int id, int width, int height, int x, int y) {
	if (sNbWindows < NB_W_MAX - 1) {
		_Windows[id] = subwin(stdscr, width, height, y, x);
		box(_Windows[0], ACS_VLINE, ACS_HLINE);
		wrefresh(_Windows[0]);
		NDisplay::sNbWindows++;
	} else
		prints("ERROR: Index too big", 1, 1);
}

int NDisplay::getX(void) const {
	return COLS;
}
int NDisplay::getY(void) const {
	return LINES;
}

Vector2 NDisplay::getBoundaries()
{
	return _boundaries;
}

NDisplay& NDisplay::operator=(NDisplay const& rhs) {
	// std::cout<<"Assignation operator called"<<std::endl;
	if (&rhs != this)
		*this = rhs;
	return *this;
}
