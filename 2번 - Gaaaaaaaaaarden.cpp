#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<deque>
#include<string.h>
#define endl "\n"
#define MAX 50
#define pii pair<int,int>
using namespace std;
struct GROUND {//���� ����
	int state; // 0:ȣ��, 1:������ �Ѹ��� ����, 2:������ �Ѹ� �� ����
	int red; // ������ ������ �ѷ��� ����
	int green; // �ʷϻ� ������ �ѷ��� ����
	bool flower; // ���� �Ǿ���� Ȯ��
};
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
int n, m, g, r;
GROUND map[MAX][MAX];
GROUND backup[MAX][MAX];
bool backup_visit[MAX][MAX];
bool dfs_visit[MAX];

vector<pii>candi_space; // ���� ���� �� �ִ� ��(�ִ� 10��)
vector<pii>choosen_space; // ���� �ɴ� ��
queue<pii>green_space; // �ʷϹ��� ���� ��(�ִ� 5��)
queue<pii>red_space;  // �������� ���� ��(�ִ� 5��)
bool nutrients_visit[10]; // ���� �� �� ��
int answer = -1;


int bfs() {
	memcpy(backup, map, sizeof(backup));
	memset(backup_visit, false, sizeof(backup_visit));
	int spread_time = 0;
	int flower_cnt = 0;		
	while (true) {
		if (green_space.empty() && red_space.empty())
			break;
		// ���� ������ �Ѹ���.
		int red_size = red_space.size();
		for (int i = 0; i < red_size; i++) {
			int red_y = red_space.front().first;
			int red_x = red_space.front().second;
			backup[red_y][red_x].red = spread_time;
			backup_visit[red_y][red_x] = true;
			red_space.pop();
			if (backup[red_y][red_x].flower == true)continue; // ���� �� ���̸� ����
			for (int k = 0; k < 4; k++) {
				int red_ny = red_y + dy[k];
				int red_nx = red_x + dx[k];
				if (0 > red_ny || red_ny >= n || 0 > red_nx || red_nx >= m)continue; // ���� �ʰ�
				if (backup_visit[red_ny][red_nx])continue; // �湮����
				if (backup[red_ny][red_nx].state == 0)continue; // ȣ������ Ȯ�� �Ұ�
				if (backup[red_ny][red_nx].flower == true)continue;// ���� �� �������� Ȯ�� �Ұ�
				backup[red_ny][red_nx].red = spread_time + 1;
				red_space.push({ red_ny,red_nx });
			}			
		}
		// �ʷ� ������ �Ѹ���.
		int green_size = green_space.size();
		for (int i = 0; i < green_size; i++) {
			int y = green_space.front().first;
			int x = green_space.front().second;
			backup[y][x].green = spread_time;
			backup_visit[y][x] = true;
			green_space.pop();
			if (backup[y][x].flower == true)continue; // ���� �� ���̸� ����
			for (int k = 0; k < 4; k++) {
				int ny = y + dy[k];
				int nx = x + dx[k];
				if (0 > ny || ny >= n || 0 > nx || nx >= m)continue; // ���� �ʰ�
				if (backup_visit[ny][nx])continue; // �湮����
				if (backup[ny][nx].state == 0)continue; // ȣ������ Ȯ�� �Ұ�
				if (backup[ny][nx].flower == true)continue;// ���� �� �������� Ȯ�� �Ұ�				
				backup[ny][nx].green = spread_time + 1; 
				green_space.push({ ny,nx });
			}		
		}

		// ���� �Ǵ��� Ȯ��
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (backup[i][j].state == 0)continue;
				if (backup[i][j].red == backup[i][j].green) {
					if (backup[i][j].red == -1 || backup[i][j].green==-1)continue;
					backup[i][j].flower = true;
				}
			}
		}
		spread_time++;
	}
	// ���� ���� Ȯ��
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (backup[i][j].flower == true) {
				flower_cnt++;
			}
		}
	}
	return flower_cnt;
}

void choice_color(int idx, int cnt) {
	if (cnt == g) {		
		for (int i = 0; i < choosen_space.size(); i++) {
			if (nutrients_visit[i]) { // �ʷ� ����
				green_space.push({ choosen_space[i].first,choosen_space[i].second });
			}
			else {
				red_space.push({ choosen_space[i].first,choosen_space[i].second });
			}
		}
		int res = bfs();
		answer = max(res, answer);
		return;
	}
	for (int i = idx; i < choosen_space.size(); i++) {
		if (nutrients_visit[i])continue;
		nutrients_visit[i] = true;
		choice_color(i, cnt + 1);
		nutrients_visit[i] = false;
	}
}

void dfs(int idx, int cnt) {
	if (cnt == g + r) {
		choosen_space.clear();
		for (int i = 0; i < candi_space.size(); i++) {
			if (dfs_visit[i] == true) {
				int y = candi_space[i].first;
				int x = candi_space[i].second;
				choosen_space.push_back({ y,x }); // ������ �Ѹ� ����
			}
		}
		// ������ �ɴ� �� �߿� �ʷ�or���� ������ �Ѹ� ���� �� --> ���۹·� �ؾ��ϳ�..
		choice_color(0, 0);
		//memset(nutrients_visit, false, sizeof(nutrients_visit));
		return;
	}
	for (int i = idx; i < candi_space.size(); i++) {
		if (dfs_visit[i])continue;
		dfs_visit[i] = true;
		dfs(i, cnt + 1);
		dfs_visit[i] = false;
	}
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);
	cin >> n >> m >> g >> r;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j].state;
			map[i][j].red = -1;
			map[i][j].green = -1;
			map[i][j].flower = false;
			if (map[i][j].state == 2) {
				candi_space.push_back({ i,j });
			}
		}
	}
	dfs(0, 0);
	cout << answer;
	return 0;
}