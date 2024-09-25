#include <graphics.h>
#include <time.h>
#include <iostream>
#include <stack>
#include <vector>
#include "Show.h"
#include "Chess.h"
#include "Users.h"
#pragma comment(lib,"Winmm.lib")
using namespace std;
constexpr int  Width = 800;
constexpr int  High = 640;
vector<vector<int>> map(18, vector<int>(18, -1)), cop(map);		/*map�����̣�-1�գ�0���ԣ�1�ѷ�*/
stack<pair<int, int>> stk;			/*���Կ��ƻ���*/
double myPos = 0, aiPos = 0;		/*�ҷ��͵�����ֵ÷�*/
int aiset;							/*��¼������һ���µ�λ��*/

int main() {
	MyChess mychs;
	Show s;
	AiChess ai;
	Users user;
	std::mutex mt;
	user.Read();
Start:
	map = cop;
	mychs.steps = 0;
	initgraph(Width,High);
	while (1) {		
		ai.Get_key_Setchess(mychs);	//Al first set chess
		s.show(mychs, user);		//show the map
		if (ai.gameOver(s, user))	goto Start;
		mychs.now = true;			// now is you 
		s.Mouse(mychs, user);		// you secondly set the chess,set now = false
		s.show(mychs, user);
		if (mychs.gameOver(s, user))	goto Start;
	}
}

