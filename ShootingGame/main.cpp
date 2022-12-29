//main.cpp
#include "main_header.h"
#include "Gun.h"
#include "Player.h"
#include "GameEngine.h"
#include "Key.h"
using namespace std;

int gameStatus[HEIGHT][WIDTH] = { 0, };

int main(){
    GameEngine *engine = new GameEngine();
	srand(time(0));
    Player *p1 = new Player(1);
    Player *p2 = new Player(2);
    Gun *g1 = new Gun(1);
    Gun *g2 = new Gun(2);
    float prev = (float)clock() / CLOCKS_PER_SEC;
    while (p1->gameover == Player::GO && p2->gameover == Player::GO){
		float curr = (float)clock() / CLOCKS_PER_SEC;
		float dt = curr - prev;
    
		if (dt < INTERVAL) continue; //while 처음으로 돌아감.
		prev = curr;
    
		bool left = keyState('a');
		bool right = keyState('d');
		bool down = keyState('s');
		bool up = keyState('w');
		bool shoot = keyState('z');

		if (left){
        
			p1->d = LEFT;
			engine->next(g1, p1, dt, 'a');
		}
		else if (right){
			p1->d = RIGHT;
			engine->next(g1, p1, dt, 'd');
		}
		else if (down){
			p1->d = DOWN;
			engine->next(g1, p1, dt, 's');
		}
		else if (up){
			p1->d = UP;
			engine->next(g1, p1, dt, 'w');
		}
		else if(shoot){
			p1->d = SHOOT;
			engine->next(g1, p1, dt, 'z');
		}
		engine->next(g2, p2, dt, 0);
		engine->next(g1, p1, dt, 0); //총알 이동
		engine->statusPrint(); //게임 데이터 출력
		string h1 = "Player 1 : " + to_string(p1->hp);
		string h2 = "Player 2 : " + to_string(p2->hp);
		drawPosition(22, 5, h1.c_str());
		drawPosition(22, 6, h2.c_str());
		
    }
    return 0;
}


