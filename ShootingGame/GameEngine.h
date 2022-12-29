//GameEngine.h

#ifndef __GAMEENGINE_H__
#define __GAMEENGINE_H__

#include "main_header.h"
#include "Player.h"



class Gun;

enum OBJECT
{
    EMPTY,
    BULLET_1,
    BULLET_2,
    BLOCK,
    WALL
};

enum GAMEMODE
{
    P2P,
    AI
};


class GameEngine
{
public:
    enum GAMEMODE gamemode = AI;
    float elapsed1 = 0.0f;
    float elapsed2 = 0.0f;
    float control = 0.0f;
    GameEngine();
    void next(Gun *g, Player *p, float elapsed, char Input);
    static void statusPrint(); // gameStatus 출력
    static bool check(Player* p);
    static void printWall();

    void goLeft(Player *p, float dt);
    void goRight(Player *p, float dt);
    void goDown(Player *p, float dt);
    void goUp(Player *p, float dt);

    bool canGoLeft(Player *p);
    bool canGoRight(Player *p);
    bool canGoUp(Player *p);
    bool canGoDown(Player *p);
};

#endif


