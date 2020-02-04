#include<iostream>
#include<queue>
#include<algorithm>
#include<string.h>
#define MAX 8
using namespace std;
int n, m;
// 0�� �� ĭ, 1�� ��, 2�� ���̷����� �ִ� ��ġ
int map[MAX][MAX];
bool visit[MAX][MAX];
bool virous[MAX][MAX]; // ���̷��� Ȯ�� ���� üũ
int dy[4] = { 0,0,-1,1 };
int dx[4] = { 1,-1,0,0 };
int min_virous = 987654;
vector<pair<int, int>>possible;

int bfs(int y, int x) {
	int cnt = 1;
	queue<pair<int, int>>q;	
	q.push({ y,x });
	virous[y][x] = true;
	while (!q.empty()) {
		y = q.front().first;
		x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (0 <= ny &&	ny < n && 	0 <= nx &&	nx < m && 	map[ny][nx] == 0 &&	virous[ny][nx] != true) {
				q.push({ ny,nx });
				virous[ny][nx] = true;
				cnt++;
			}
		}
	}
	return cnt;
}
int spread() {
	int area = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 2 && virous[i][j]!=true) {
				area += bfs(i, j); // Ȯ���� �� ���̷����� ����
			}
		}
	}
	return area;
}
void init() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (visit[i][j] == true)
				map[i][j] = 0;
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);	cout.tie();
	freopen("input.txt", "r", stdin);
	cin >> n >> m;
	int tmp;
	vector<int>select;
	int wall = 0; // ���� ����
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> tmp;
			map[i][j] = tmp;
			if (tmp == 0) { //  ���� ���� �� �ִ� ��ġ
				possible.push_back({ i,j });
				select.push_back(0);
			}
			else if (tmp == 1) {
				wall++;
			}
		}
	}
	wall += 3; // ���� 3�� �� ����
	select.pop_back();
	select.pop_back();
	select.pop_back();
	select.push_back(1);
	select.push_back(1);
	select.push_back(1);
	sort(select.begin(), select.end());
	
	int virous_area=0;
	do
	{
		for (int i = 0; i < select.size(); i++) {
			if (select[i] == 1) {// ���� ���� �� �ִ� ��ġ�� 3�� --> ��� ������ 3? 8*=8 = 64C3 ==> ���۹� : 4��1õ
				//cout << possible[i].first << ',' << possible[i].second << ' ';
				int y = possible[i].first;
				int x = possible[i].second;
				map[y][x] = 1;
				visit[y][x] = true; // ���� ���� ���������� üũ
			}
		}
		virous_area = spread(); // 3���� ���� ����� ���̷����� ���� ��, ���������� � �ֳ� Ȯ��
		min_virous = min(min_virous, virous_area);
		init();// ������ �� �ʱ�ȭ1
		memset(visit, false, sizeof(visit)); // ������ �� �ʱ�ȭ2
		memset(virous, false, sizeof(virous)); // Ȯ�� ���̷��� �ʱ�ȭ
	} while (next_permutation(select.begin(), select.end()));

	int res = (n * m) - min_virous - wall; // ��������=��ü ��ũ�� - ���̷����� �ּҷ� ���� ���� - ���� ����
	cout << res;
}