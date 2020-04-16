#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string.h>
#define endl "\n"
#define pii pair<int,int>
#define MAX 20
using namespace std;
int map[MAX][MAX];
bool visit[MAX][MAX];
int backup[MAX][MAX];
bool backup_visit[MAX][MAX];
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
//int dx[4] = { 0,0 - 1,1 }; // �̷��� �Ǿ��־���;;
int n, m;
int answer = -1;
int death = 0;// ���� ���� ����� ����
vector<pii>empty_space; // �� ����
vector<pii>mydol; // 2���� ���� �� ��ġ

int bfs(int y, int x) {
	queue<pii>q;	
	q.push({ y,x });
	int cnt = 1; // ���� ���� ����
	bool isDeath = true; // ������ �ٵϵ����� �״��� Ȯ��
	while (!q.empty()) {
		y = q.front().first;
		x = q.front().second;
		backup_visit[y][x] = true;
		q.pop();
		for (int k = 0; k < 4; k++) {
			int ny = y + dy[k];
			int nx = x + dx[k];
			if (0 > ny || ny >= n || 0 > nx || nx >= m)continue;
			if (backup_visit[ny][nx])continue;
			if (backup[ny][nx] == 0) { // ����� ���ܹ���
				isDeath = false; // ����� �ٵϵ��� ���� ����
			}
			else if (backup[ny][nx] == 2) {
				backup_visit[ny][nx] = true;
				q.push({ ny,nx });
				cnt++;
			}
		}
	}
	if (isDeath==false)
		cnt = 0;
	return cnt;
}
void play() {
	memcpy(backup, map, sizeof(backup));
	memset(backup_visit, false, sizeof(backup_visit));
	death = 0;
	// ���� �д�
	for (int i = 0; i < 2; i++) {
		int y = mydol[i].first;
		int x = mydol[i].second;
		backup[y][x] = 1;
	}	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (backup[i][j] == 2 && !backup_visit[i][j]) {
				death+=bfs(i, j);
			}
		}
	}
	answer = max(death, answer);
}

void dfs(int idx, int cnt) {
	if (cnt == 2) {
		mydol.clear();
		for (int i = 0; i < empty_space.size(); i++) {
			int y = empty_space[i].first;
			int x = empty_space[i].second;
			if (!visit[y][x])continue;
			mydol.push_back({ y,x });
		}
		play();
		return;
	}
	for (int i = idx; i < empty_space.size(); i++) {
		int y = empty_space[i].first;
		int x = empty_space[i].second;
		if (visit[y][x])continue;
		visit[y][x] = true;
		dfs(i, cnt + 1);
		visit[y][x] = false;		
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 0)
				empty_space.push_back({ i,j });
		}
	}
	dfs(0, 0);
	cout << answer;
	return 0;
}