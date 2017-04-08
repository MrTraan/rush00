#include <NDisplay.hpp>
#include <ncurses.h>
int main ()
{	
	NDisplay mainWindow;

	mainWindow.prints("salut", mainWindow.getX()/2, mainWindow.getY()/2);
	while (1)
	{
		mainWindow.waitForQuit(27);
	}
}