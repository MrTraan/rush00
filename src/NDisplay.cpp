#include "../includes/NDisplay.hpp"
//#include <InputManager.class.hpp>

int NDisplay::sNbWindows = 0;

NDisplay::NDisplay(void) {
	initscr();
	cbreak();
	noecho();
	timeout(1);
	curs_set(FALSE);
	for (int i = 0; i < NB_W_MAX; i++)
		_Windows[i] = NULL;
	// std::cout<<"Default constructor called"<<std::endl;
}

NDisplay::NDisplay(NDisplay const& src) {
	// std::cout<<"Copy constructor called"<<std::endl;
	*this = src;
}

NDisplay::~NDisplay(void) {
	endwin();
	// std::cout<<"Destructor called"<<std::endl;
}
void NDisplay::draw(Shape& shape) 
{
	for (int i=0; i < shape.getHeight(); i++)
	{
		for (int j=0; j < shape.getWidth(); j++)
			print(shape.getshape()[i*(j+1)], shape.getPosX() + i, shape.getPosY() + j);
	}
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

void NDisplay::waitForQuitW(int id, char c) {
	if (getch() == c)
		if (id && id < NB_W_MAX && _Windows[id]) {
			clrW(id);
			delwin(_Windows[id]);
			sNbWindows--;
		}
}


void NDisplay::subWinStdr(int id, int width, int height, int x, int y) {
	if (sNbWindows < NB_W_MAX - 1) {
		_Windows[id] = subwin(stdscr, width, height, y, x);
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


NDisplay& NDisplay::operator=(NDisplay const& rhs) {
	// std::cout<<"Assignation operator called"<<std::endl;
	if (&rhs != this)
		*this = rhs;
	return *this;
}
