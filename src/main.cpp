#include <NDisplay.hpp>
#include <ncurses.h>
#include <stdlib.h>
#include <unistd.h>

#include <Input.class.hpp>
#include <debug.hpp>

int main() {
	fprintf(debugFile, "lets go\n");
	fflush(debugFile);
	InputManager im;
	NDisplay mainWindow;


	mainWindow.prints("salut", mainWindow.getX() / 2, mainWindow.getY() / 2);
	while (1) {
		im.readInput();
		mainWindow.waitForQuit();
		usleep(1000);
	}
}
