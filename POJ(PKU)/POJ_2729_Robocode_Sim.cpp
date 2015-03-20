#include <cstdio>
#include <cstring>
#include <string>
#include <map>
#include <list>

#define MAX_TANK 12
#define MAX_EVENT 1002
#define MAX_T 30

#define V_TANK 1 // moves 1 in 1/6 sec
#define V_SHOT 2 // moves 2 in 1/6 sec

#define E_MOVE 0
#define E_STOP 1
#define E_TURN 2
#define E_SHOOT 3

using namespace std;

inline void conv(int &n) { n = n * 6 / 10; }
inline void convAng(int &ang)
{
	ang /= 90;
	while (ang < 0) ang += 4;
	ang %= 4;
}
inline bool valid(int &n) { return n >= 0 && n <= 72; } // 120 * 6 / 10 = 72

struct obj
{
	bool alive;
	int x, y;
	int dir;
	int v;
	char name[20];
};
obj lTank[MAX_TANK];
list<obj> lShot;

struct event
{
	int time;
	int id, type, ang;
};
event lEvent[MAX_EVENT];

int mx[4] = {1, 0, -1, 0};
int my[4] = {0, 1, 0, -1};
int a[73][73]; // 0~72
map<string, int> objId;

int main()
{
	int i, j, n, m, nx, ny;
	char name[20], cmd[10];
	int shotCnt, aliveCnt, itE;
	list<obj>::iterator itS;
	map<string, int>::iterator itId;
	list<int> lDead; list<int>::iterator itD;
	while (scanf("%d%d", &n, &m) == 2 && !(n == 0 && m == 0))
	{
		// init
		memset(a, -1, sizeof(a));
		lShot.clear();
		shotCnt = 0;
		aliveCnt = n;
		itE = 0;
		lDead.clear();
		
		// input
		for (i = 0; i < n; i++)
		{
			obj &o = lTank[i];
			o.alive = true;
			o.v = 0;
			scanf("%s %d %d %d", o.name, &o.x, &o.y, &o.dir);
			conv(o.x);
			conv(o.y);
			convAng(o.dir);
			
			objId[string(o.name)] = i;
			a[o.x][o.y] = i;
		}
		for (i = 0; i < m; i++)
		{
			event &e = lEvent[i];
			scanf("%d %s %s", &e.time, name, cmd);
			itId = objId.find(string(name));
			e.id = itId->second;
			if (strcmp(cmd, "MOVE") == 0)
				e.type = E_MOVE;
			else if (strcmp(cmd, "STOP") == 0)
				e.type = E_STOP;
			else if (strcmp(cmd, "TURN") == 0)
			{
				e.type = E_TURN;
				scanf("%d", &e.ang);
				convAng(e.ang);
			}
			else if (strcmp(cmd, "SHOOT") == 0)
				e.type = E_SHOOT;
		}
		
		// start
		for (i = 0; itE < m || shotCnt > 0; i++) // increment by 1/6 sec. actual sec = i/6
		{
			// move the tanks
			for (j = 0; j < n; j++)
			{
				obj &o = lTank[j];
				if (o.alive && o.v > 0)
				{
					nx = o.x + mx[o.dir] * o.v;
					ny = o.y + my[o.dir] * o.v;
					if (!valid(nx) || !valid(ny))
						o.v = 0;
					else
					{
						a[o.x][o.y] = -1;
						a[nx][ny] = j;
						o.x = nx;
						o.y = ny;

					}
				}
				// printf("%d (%d, %d)\n", j, o.x,  o.y);
			}
			
			// move shots and detect collision
			lDead.clear();
			for (itS = lShot.begin(); itS != lShot.end(); )
			{
				int &x = (*itS).x, &y = (*itS).y;
				x += mx[(*itS).dir] * V_SHOT;
				y += my[(*itS).dir] * V_SHOT;
				if (!valid(x) || !valid(y)) // out of map
				{
					--shotCnt;
					itS = lShot.erase(itS);
					continue;
				}
				if (a[x][y] >= 0) // hit a tank
				{
					--shotCnt;
					lDead.push_back(a[x][y]);
					lTank[ a[x][y] ].alive = false; // note we didn't clean up our map here, since multiple shots can collide with 1 tank at the same tank
					itS = lShot.erase(itS);
					continue; 
				}
				itS++;
				// printf("S (%d, %d)\n", x, y);
			}
			// clean up our map
			for (itD = lDead.begin(); itD != lDead.end(); itD = lDead.erase(itD))
			{
				int &ori = a[ lTank[(*itD)].x ][ lTank[(*itD)].y ];
				if (ori >= 0) // hasn't been cleaned up before
				{
					--aliveCnt;
					ori = -1;
				}
			}
			
			// execute the commands
			for ( ; itE < m && lEvent[itE].time <= double(i) / 6; itE++)
			{
				event &e = lEvent[itE];
				obj &o = lTank[e.id];
				if (o.alive)
				{
					switch (e.type)
					{
						case E_MOVE:
							o.v = V_TANK;
							break;
						case E_STOP:
							o.v = 0;
							break;
						case E_TURN:
							o.dir += e.ang;
							o.dir %= 4;
							break;
						case E_SHOOT:
							++shotCnt;
							lShot.push_back( (obj){true, o.x, o.y, o.dir, V_SHOT} );
							break;
					}
				}
			}
		}
		if (aliveCnt != 1)
			puts("NO WINNER!");
		else
		{
			for (i = 0; i < n; i++)
				if (lTank[i].alive)
				{
					puts(lTank[i].name);
					break;
				}
		}
	}
	return 0;
}
