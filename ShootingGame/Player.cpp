//Player.cpp
#include "Player.h"

Player::Player(int n){
    player_no = n;
    hp = 3;
    gameover = GO;
    
    if (n == 1)
    {
        x = WIDTH / 2;  // x축 중심
        y = HEIGHT - 4; //아래
    }
    else if (n == 2){
        x = WIDTH / 2;
        y = 3;
    }
}

void Player::damage(int i){
    hp -= i;
    if (hp == 0){
        gameover = STOP;
    }
}


