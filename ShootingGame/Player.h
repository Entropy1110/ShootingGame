
#ifndef __PLAYER_H__
//Player.h
#define __PLAYER_H__

#include "main_header.h"


enum DIR
{
    UP,
    DOWN,
    LEFT,
    RIGHT,
    SHOOT
};

class Player{

public:
    int player_no;
    int hp;
    int x;
    int y;
    enum DIR d;
    enum GAMEOVER{GO, STOP};
    enum GAMEOVER gameover;
    Player(int n);
    void damage(int i); //데미지, hp 게임오버 판정
    
};


#endif
