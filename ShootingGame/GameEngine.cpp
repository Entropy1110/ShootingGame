//GameEngine.cpp
#include "GameEngine.h"
#include "Gun.h"
#include "Key.h"


GameEngine::GameEngine(){
    for (int i = 0; i < HEIGHT; i++){
        gameStatus[i][0] = WALL;
        gameStatus[i][WIDTH - 1] = WALL;
    }
    for (int i = 0; i < WIDTH; i++){
        gameStatus[0][i] = WALL;
        gameStatus[HEIGHT - 1][i] = WALL;
    }
}

void GameEngine::statusPrint(){
    for (int i = 0; i < HEIGHT; i++)
    {
        for (int k = 0; k < WIDTH; k++){
            if (gameStatus[i][k] == BULLET_1 || gameStatus[i][k] == BULLET_2){
                drawPosition(k, i, "l");
            }
            else if (gameStatus[i][k] == BLOCK){
                drawPosition(k, i, "A");
            }
            else if (gameStatus[i][k] == EMPTY){
                drawPosition(k, i, " ");
            }
        }
    }
    printWall();
}

void GameEngine::next(Gun* g, Player* p, float dt, char Input){
  // 입력 받기 -> 캐릭터 움직임&총발사, 총알 데미지 판정
    
    gameStatus[p->y][p->x] = BLOCK;
    elapsed1 += dt;
    elapsed2 += dt;
    
    
    if (p->player_no == 2){
        switch(rand() % 4){
            case 0:
                if (g->isFired2()) return;
                goLeft(p, dt);
                break;
            case 1:
                if (g->isFired2()) return;
                goRight(p, dt);
                break;
            case 2:
                if (g->isFired2()) return;
                if (elapsed2 <= 2.0f) return;
                g->fire(p, p->x, p->y + 1);
                elapsed2 -= 2.0f;
                
                break;
            default:
                
                    if (elapsed2 >= 0.2f && g->isFired2()){
                //총알 궤적
                        g->fire(p, g->x, g->y);
                        elapsed2 -= 0.2f;
                    }
                if (GameEngine::check(p)){
                    gameStatus[p->y - 1][p->x] = EMPTY; //총알 소멸
                    p->damage(1); //체력 감소
                    return;
                }
                return;
                
        }
    }
  

    else{
        switch (Input)
        {
        case 'a':
//            if (g->isFired1()) return;
            goLeft(p, dt);
            break;
        case 'd':
//            if (g->isFired1()) return;
            goRight(p, dt);
            break;
        case 'w':
//            if (g->isFired1()) return;
            goUp(p, dt);
            break;
        case 's':
//            if (g->isFired1()) return;
            goDown(p, dt);
            break;
        case 'z':
            if (g->isFired1() || g->isFired2()) return;
            g->fire(p, p->x, p->y - 1);
            break;
        default:
                
            if (elapsed1 >= 0.2f && g->isFired1()){
            //총알 궤적
                g->fire(p, g->x, g->y);
                elapsed1 -= 0.2f;
            }
            if (GameEngine::check(p)){
                gameStatus[p->y - 1][p->x] = EMPTY; //총알 소멸
                p->damage(1); //체력 감소
                return;
            }
            return;
        }
    }
}




void GameEngine::printWall(){
    for (int i = 0; i < HEIGHT; i++){
        for (int k = 0; k < WIDTH; k++)
        {
            if (gameStatus[i][k] == WALL){
            drawPosition(k, i, "#");
            }
        }
    }
}

bool GameEngine::check(Player* p){ //매개변수 x, y 플레이어의 좌표
    //총알 충돌 체크->매번 실행해야함. 플레이어와 충돌시 총알 사라짐, 충돌 안할 경우 wall까지 진행
    if (p->player_no == 2 && gameStatus[p->y + 1][p->x] == BULLET_1){
        
        return true;
    }
    if (p->player_no == 1 && gameStatus[p->y - 1][p->x] == BULLET_2){
        return true;
    }

    return false;
}

void GameEngine::goRight(Player* p, float dt){
    control += dt;
    if (!GameEngine::canGoRight(p) || control < 0.1f)
        return;
    control = 0;
    gameStatus[p->y][p->x] = EMPTY;
    (p->x)++;
    gameStatus[p->y][p->x] = BLOCK;
    
}

void GameEngine::goLeft(Player* p, float dt){
    control += dt;
    if (!GameEngine::canGoLeft(p) || control < 0.1f)
        return;
    control = 0;
    gameStatus[p->y][p->x] = EMPTY;
    (p->x)--;
    gameStatus[p->y][p->x] = BLOCK;
}

void GameEngine::goDown(Player* p, float dt){
    control += dt;
    if (!GameEngine::canGoDown(p) || control < 0.1f)
        return;
    control = 0;
    gameStatus[p->y][p->x] = EMPTY;
    (p->y)++;
    gameStatus[p->y][p->x] = BLOCK;
}

void GameEngine::goUp(Player* p, float dt){
    control += dt;
    if (!GameEngine::canGoUp(p) || control < 0.1f)
        return;
    control = 0;
    gameStatus[p->y][p->x] = EMPTY;
    (p->y)--;
    gameStatus[p->y][p->x] = BLOCK;
}

bool GameEngine::canGoRight(Player* p){
    if (gameStatus[p->y][p->x + 1] == BLOCK || p->x + 1 >= WIDTH - 1)
        return false;
    return true;
}
bool GameEngine::canGoLeft(Player* p){
    if (gameStatus[p->y][p->x - 1] == BLOCK || p->x - 1 <= 0){
        return false;
    }
    return true;
}
bool GameEngine::canGoDown(Player* p){
    if (gameStatus[p->y + 1][p->x] == BLOCK || p->y + 1 >= HEIGHT - 1){
        return false;
    }
    return true;
}
bool GameEngine::canGoUp(Player* p){
    if(gameStatus[p->y - 1][p->x] == BLOCK || p->y - 1 <= 0){
        return false;
    }
    return true;
}
