#include <bits/stdc++.h>
#define endl "\n"
#define MAX 12
using namespace std;
struct CHESS
{
	int dir;
	int y;
	int x;
};
int n, k;
int turn = 1;
int board[MAX][MAX];			   // 체스판의 정보 : 흰, 빨, 파
vector<int> board_state[MAX][MAX]; // 체스판의 상태 : (y,x)의 위치에 몇번 말이 있는 지
CHESS chess[MAX];				   // i번 말의 정보
int dy[4] = {0, 0, -1, 1};
int dx[4] = {1, -1, 0, 0};
int changeDir(int dir)
{
	if (dir == 0)return 1;
	if (dir == 1)return 0;
	if (dir == 2)return 3;
	if (dir == 3)return 2;
}
void prt()
{
	for (int i = 0; i < k; i++)
	{
		cout << chess[i].y << ' ' << chess[i].x << ' ' << chess[i].dir << ' ';
		cout << endl;
	}
	cout << endl << endl;
}
bool isFinish()
{ // 한 지점에 말이 4개 이상 모여있을 경우 종료
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (board_state[i][j].size() >= 4)
			{
				return true;
			}
		}
	}
	return false;
}
void moving(int num, int y, int x, int ny, int nx)
{ // 이동 -> 현재 말의 위의 말들도 함께 이동해야 함
	vector<int> tmp;
	int idx = 0; // i번 말이 몇번째에 쌓여 있는지
	for (int j = 0; j < board_state[y][x].size(); j++)
	{
		if (num == board_state[y][x][j])
		{
			idx = j;
			break;
		}
	}
	int len = board_state[y][x].size();
	for (int i = idx; i < len; i++)
	{ // idx 위에 쌓인 말들은 다 이동
		tmp.push_back(board_state[y][x][i]);
		chess[board_state[y][x][i]].y = ny; // 말 정보 변경
		chess[board_state[y][x][i]].x = nx;
	}
	for (int i = idx; i < len; i++)
	{		
		board_state[y][x].pop_back(); // 기존 위치의 말 제거
	}
	for (int i = 0; i < tmp.size(); i++)
	{
		board_state[ny][nx].push_back(tmp[i]); // 새로운 위치에 말을 쌓음
	}
}

void reverse_moving(int num, int y, int x, int ny, int nx)
{ // 순서 바꿔서이동 -> 현재 말의 위의 말들도 함께 이동해야 함
	vector<int> tmp;
	int idx = 0; // i번 말이 몇번째에 쌓여 있는지
	for (int j = 0; j < board_state[y][x].size(); j++)
	{
		if (num == board_state[y][x][j])
		{
			idx = j;
			break;
		}
	}
	int len = board_state[y][x].size();
	for (int i = idx; i < len; i++)
	{
		tmp.push_back(board_state[y][x][i]);
		chess[board_state[y][x][i]].y = ny; // 말 정보 변경
		chess[board_state[y][x][i]].x = nx;		
	}
	for (int i = idx; i < len; i++)
	{
		board_state[y][x].pop_back();
	}
	reverse(tmp.begin(), tmp.end()); // 역순 삽입을 위함
	for (int i = 0; i < tmp.size(); i++)
	{
		board_state[ny][nx].push_back(tmp[i]);
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("input.txt", "r", stdin);
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> board[i][j];
		}
	}
	int dir;
	int y;
	int x;
	for (int i = 0; i < k; i++)
	{
		cin >> y >> x >> dir; // 좌표, 방향	: 0,0 부터 시작하기 위해 1씩 빼줌
		y=y-1; x=x-1; dir=dir-1;
		chess[i].y = y;
		chess[i].x = x;
		chess[i].dir = dir;
		board_state[y][x].push_back(i); // i번 말이 들어감
	}
	while (turn <= 1000)
	{
		//prt();
		for (int i = 0; i < k; i++)
		{ // 0번 말부터 이동
			y = chess[i].y;
			x = chess[i].x;
			dir = chess[i].dir;
			int ny = y + dy[dir];
			int nx = x + dx[dir];
			if (0 > ny || ny > n - 1 || 0 > nx || nx > n - 1)
			{ // 범위를 넘어감 -> 파란색으로 처리
				int ndir = changeDir(dir);
				ny = y + dy[ndir];
				nx = x + dx[ndir];
				chess[i].dir=ndir;
				if (0 > ny || ny > n - 1 || 0 > nx || nx > n - 1)continue;
				else if (board[ny][nx] == 0)
				{							 // 흰색
					moving(i, y, x, ny, nx); // i번 말이 (y,x)->(ny,nx)
				}
				else if (board[ny][nx] == 1)
				{ // 빨간색
					reverse_moving(i, y, x, ny, nx);
				}
				else continue; // 또 파란색
			}
			else if (board[ny][nx] == 0)
			{							 // 흰색
				moving(i, y, x, ny, nx); // i번 말이 (y,x)->(ny,nx)
			}
			else if (board[ny][nx] == 1)
			{ // 빨간색
				reverse_moving(i, y, x, ny, nx);
			}
			else
			{ // 파란색
				int ndir = changeDir(dir);
				ny = y + dy[ndir];
				nx = x + dx[ndir];
				chess[i].dir=ndir;
				if (0 > ny || ny > n - 1 || 0 > nx || nx > n - 1)continue;
				else if (board[ny][nx] == 0)
				{							 // 흰색
					moving(i, y, x, ny, nx); // i번 말이 (y,x)->(ny,nx)
				}
				else if (board[ny][nx] == 1)
				{ // 빨간색
					reverse_moving(i, y, x, ny, nx);
				}
				else continue; // 또 파란색
			}
			if (isFinish())
			{
				cout << turn;
				return 0;
			}
		}		 
		turn++;
	}
	cout << -1;
	return 0;
}