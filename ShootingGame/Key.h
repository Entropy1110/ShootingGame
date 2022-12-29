//Key.h
#ifndef Key_h
#define Key_h


#include <termios.h>
#include <cstdio>
#include <thread>
#include <Carbon/Carbon.h>


void putStringOnPosition(int x, int y, const char* content);

void showConsoleCursor(bool showFlag);

void drawPosition(int x, int y, const char* filled);


Boolean isPressed( unsigned short inKeyCode );


bool keyState(char c);




#endif
