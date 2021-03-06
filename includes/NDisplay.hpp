#ifndef NDISPLAY_HPP
#define NDISPLAY_HPP

#include <iostream>
#include <ncurses.h>
#include "../includes/Shape.hpp"
#include "../includes/Vector2.class.hpp"

#define NB_W_MAX 10

class NDisplay {
   public:
	static int sNbWindows;

	NDisplay(int l, int r);
	NDisplay(NDisplay const& src);
	~NDisplay(void);

	// Display function
	void draw(Shape& shape);
	//char
	void print(char c);
	void print(char c, int x, int y);
	void print(int id, char c, int x, int y);
	//string
	void prints(std::string s);
	void prints(std::string s, int x, int y);
	void prints(int id, std::string s, int x, int y);
	// End Display function

	void rfh(void);
	void clr(void);
	void clrW(int id);
	void rfhW(int id);
	
	void waitForQuit();

	void subWinStdr(int id, int width, int height, int x, int y);

	int getX(void) const;
	int getY(void) const;
	Vector2 getBoundaries();

	NDisplay& operator=(NDisplay const& rhs);

   private:
   NDisplay(void);
   Vector2 _boundaries;
	WINDOW* _Windows[NB_W_MAX];
};

#endif
