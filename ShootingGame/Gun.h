//Gun.h
#ifndef __GUN_H__
#define __GUN_H__

#include "main_header.h"
#include "GameEngine.h"
#include "Player.h"


enum GUNS
{
    SINGLE,
    MACHINE
};

class Gun {
    
    private:
        int bullets;
        

    public:
        int x, y; //총알 좌표
        enum GUNS hand;
        Gun(int n);
        void fire(Player* p, int x_, int y_);     //발사
        void gunSet(enum GUNS hand); // 총 설정
        bool isFired1();
        bool isFired2();
};

#endif
