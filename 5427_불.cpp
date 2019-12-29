#include<iostream>
#include<vector>
#include<deque>
#include<queue>
#include<string>
#include<string.h>
using namespace std;

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int w,h=0;
vector<vector<char>>map;

int dist[1000][1000];
deque<pair<int, int>>fire; // ���� ��ġ

bool isAlive(int x, int y) {
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (map[i][j] == '@') {
				return true;
			}
		}
	}
	return false;
}


bool canGo(int x, int y) {
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (0 <= nx && nx < h && 0 <= ny && ny < w) {
			if (map[nx][ny] == '.') { // �ϳ��� ������� ������ �̵� ����
				return true;
			}
		}
	}	
	return false;
}

void movefire(){ // ���� �����ϰ� �ֺ��� * �� �ٲ�
	int size = fire.size();
	for (int i = 0; i < size; i++) {
		int x = fire[0].first;
		int y = fire[0].second;
		fire.pop_front();
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (0 <= nx && nx < h && 0 <= ny && ny < w) {
				if (map[nx][ny] == '.' ) { 
					map[nx][ny] = '*';
					fire.push_back({ nx,ny });
				}
			}
		}		
	}

}
void bfs(int x, int y) {
	queue<pair<int, int>> q;
	q.push({ x,y });
	while (!q.empty()) {
		movefire();
		x = q.front().first;
		y = q.front().second;
		q.pop();
		int nx; int ny;
		for (int i = 0; i < 4; i++) {
			nx = x + dx[i];
			ny = y + dy[i];
			if (0 <= nx && nx < h && 0 <= ny && ny < w && map[nx][ny] == '.') {// ����̰� �̵� ����
				// �̵��� �� ������ ���� ���� ���� ���� �ȵ�. ����̰� ���� �̵��ؾ� ��.
				// �̵��ϴ� ��� ���� @�� �־����.
				map[nx][ny] = '@';
				q.push({ nx,ny });				
				dist[nx][ny] = dist[x][y] + 1;
			}
			
		// Ż�� �������� Ȯ�� : ���� �ڸ��� ����̰� ������ �ȴ�.
		if (nx == 0 || nx == h-1 || ny == 0 || ny == w-1) {
			cout << dist[nx][ny] + 1<<endl;
			return;
		}
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int startX = 0; int startY = 0; // ������� ������
		cin >> w >> h;
		map.clear();  fire.clear();
		map.resize(h); 
		for (int i = 0; i < h; i++) {
			string str;
			cin >> str;
			for (int j = 0; j < w; j++) {
				map[i].push_back(str[j]);
				dist[i][j]=0;
				if (str[j] == '@') {// ������� ��ġ
					startX = i;
					startY = j;
				}
				else if (str[j] == '*') { // ��
					fire.push_back({ i,j });
				}
			}
		}

		// �� or �ҷ� �ѷ������� Ȯ��
		if (!canGo(startX, startY)) {
			cout << "IMPOSSIBLE" << endl;
		}
		 //	�����, �� �̵�
		else {			
			bfs(startX, startY);
		}		
	}

}