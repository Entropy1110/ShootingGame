//Gun.cpp
#include "Gun.h"

Gun::Gun(int n){
    x = 0;
    y = 0;
    hand = SINGLE;
}



void Gun::fire(Player* p, int x_, int y_){ //인수->총알 이전 좌표 starts with 플레이어1 y-1 플레이어2 y+1
    x = x_;
    y = y_;
    
    
    if (p->player_no == 1 && y > 1)
    {
        gameStatus[y][x] = EMPTY;
        y--;
        gameStatus[y][x] = BULLET_1;

    }
    
    else if (p->player_no == 2 && y < HEIGHT - 2)
    {
        gameStatus[y][x] = EMPTY;
        y++;
        gameStatus[y][x] = BULLET_2;

    }

    

   //벽과 충돌
    if (y == 1){
        gameStatus[y][x] = EMPTY; //총알 소멸
        return;
    }
    if (y == HEIGHT - 2)
        gameStatus[y][x] = EMPTY;
        return;
}


bool Gun::isFired1(){
    if (gameStatus[y][x] == BULLET_1)
        return true;

    return false;
}

bool Gun::isFired2(){
    if(gameStatus[y][x] == BULLET_2)
        return true;
    return false;
}
