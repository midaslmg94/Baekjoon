#include<iostream>
#include<queue>
#include<string.h>
#define endl "\n"
#define MAX 1000
using namespace std;

struct INFO {
	bool visit; // �湮�ߴ���
	bool next_fire; // ������ �� �� ��ġ�ΰ�
};

int t;
int w, h;
int result; // ����
bool visit[MAX][MAX];
char map[MAX][MAX];
//INFO visit[MAX][MAX];
queue<pair<int, int>>sang;// ������� ��ġ
queue<pair<int, int>>fire;// ���� ��ġ
int dy[4] = { 0,0,1,-1 };
int dx[4] = { 1,-1,0,0 };
void ptr() {
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cout << map[i][j] << ' ';
		}
		cout << endl;
	}
	cout << "=============" << endl;
}

void bfs() {
	while(!sang.empty()) {		
		// ����̰� Ż�� ������ ��ġ����?
		/*for (int i = 0; i < sang.size(); i++) {
			int sang_y = sang[i].first;
			int sang_x = sang[i].second;
			if (sang_y == 0 || sang_y == h - 1 || sang_x == 0 || sang_x == w - 1) {
				cout << result + 1 << endl;
				return;
			}
		}*/
		// �� Ȯ��, ��ġ ����
		bool is_move = false;
		int fire_size = fire.size();
		for (int i = 0; i < fire_size; i++) {
			int fire_y = fire.front().first;
			int fire_x = fire.front().second;
			fire.pop();
			for (int k = 0; k < 4; k++) {
				int fire_ny = fire_y + dy[k];
				int fire_nx = fire_x + dx[k];
				if (0 > fire_ny || fire_ny >= h || 0 > fire_nx || fire_nx >= w) continue;
				if (map[fire_ny][fire_nx] != '#' && map[fire_ny][fire_nx] != '*') { // ���� �ƴ϶�� ���� �ٴ´�
					map[fire_ny][fire_nx] = '*';					
					fire.push({ fire_ny,fire_nx }); // ���Ӱ� Ȯ��� ���� ��ġ ����
				}
			}
		}
		// ����� �̵�, ��ġ ����
		int sang_size = sang.size();
		for (int i = 0; i < sang_size; i++) {
			int y = sang.front().first;
			int x = sang.front().second;
			visit[y][x] = true;
			sang.pop();
			if (y == 0 || y == h - 1 || x == 0 || x == w - 1) {
				cout << result + 1 << endl;
				return;
			}
			for (int k = 0; k < 4; k++) {
				int ny = y + dy[k];
				int nx = x + dx[k];
				if (0 > ny || ny >= h || 0 > nx || nx >= w) continue; // ��������� ���� �ʰ�
				if (map[ny][nx] == '#' || map[ny][nx] == '*' || visit[ny][nx] == true) continue; // ��������� ��, ��, �湮�ߴ� ��ġ			
				map[ny][nx] = '@';
				sang.push({ ny,nx });
				visit[ny][nx] = true;
				is_move = true;
			}
		}
		result++;
		//ptr();
		if (!is_move) {
			cout << "IMPOSSIBLE" << endl;
			return;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);

	cin >> t;
	while (t--) {	
		result = 0;
		cin >> w >> h;
		for (int i = 0; i < h; i++) {
			string str; 
			cin >> str;
			for (int j = 0; j < w; j++) {
				map[i][j] = str[j];
				if (str[j] == '@') {
					sang.push({ i,j });
				}
				else if (str[j] == '*') {
					fire.push({ i,j });
				}
			}
		}
		bfs();
		// �ʱ�ȭ
		while (!sang.empty())sang.pop(); 
		while (!fire.empty())fire.pop();
		memset(visit, false, sizeof(visit));
		memset(map, '#', sizeof(map));
	}
}