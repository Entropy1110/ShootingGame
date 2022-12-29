//Key.cpp
#include "Key.h"
#include "main_header.h"

bool consoleInitialized = false;
int lastX = 0;
int lastY = 0;

void putStringOnPosition(int x, int y, const char* content){
   char buff[100] = { 0, };
   sprintf(buff, "\033[%d;%dH", y, x);
   printf("%s", buff);
   printf("%s", content);
   lastX = x;
   lastY = y;
}

void showConsoleCursor(bool showFlag) {
    
}

void drawPosition(int x, int y, const char* filled) {
    if(!consoleInitialized) {
        consoleInitialized = true;
        printf("\033[2J");
    }
    putStringOnPosition(x + 1, y, filled);
}


Boolean isPressed( unsigned short inKeyCode ){
    unsigned char keyMap[16];
    GetKeys((BigEndianUInt32*) &keyMap);
    drawPosition(lastX, lastY, "           ");
    return (0 != ((keyMap[ inKeyCode >> 3] >> (inKeyCode & 7)) & 1));
}

bool keyState(char c) {
    bool ret;
    switch (c) {
        case 'a': ret = isPressed(123); break;
        case 'd': ret = isPressed(124); break;
        case 's': ret = isPressed(125); break;
        case 'w': ret = isPressed(126); break;
        case 'z': ret = isPressed(56); break;
        default: ret = false;
    }
    
    return ret;
}
