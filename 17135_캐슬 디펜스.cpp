#include<iostream>
#include<algorithm>
#include<string.h>
#include<queue>
#include<vector>
#define MAX 15
#define endl "\n"
#define pii pair<int,pair<int,int>> 
using namespace std;
int n, m, d;
struct INFO
{
	int state; // 0:��, 1:��
	bool isAttacked; // ���� ȭ�쿡 �¾Ҵ��� �ƴ���
};
INFO map[MAX][MAX];
vector<int>archer_candi; // �ü��� �� �� �ִ� ��ġ
vector<int>archer; // �ü��� ��ġ�� �� 
bool visit[MAX];
int result = -1;
struct ENEMY {
	int dist;
	int y;
	int x;
};
bool cmp(const ENEMY &a, const ENEMY &b ) {// �Ÿ��� ª�� ��, �Ÿ��� ���ٸ� ���� ���ʿ� �ִ� ��
	return a.dist < b.dist || (a.dist == b.dist && a.x < b.x);
}
int attack(vector<int>my_archer) {
	INFO backup[MAX][MAX];
	int kill = 0;
	memcpy(backup, map, sizeof(backup));
	int turn = n;
	while (turn--) // y���� ���̸�ŭ ������ ����
	{
		queue<pair<int, int>>dead_enemy; // ���� ���� ��ġ
		vector<ENEMY>enemy; // ���� ��ġ			
		for (int t = 0; t < my_archer.size(); t++) {
			// �ü��� ��ġ 
			int archer_y = n;
			int archer_x = my_archer[t];
			enemy.clear();
			// ���� ����� �Ÿ����� �ִ� ���� ���ʿ��� ���� ���
			for (int i = n - 1; i >= 0; i--) {
				for (int j = 0; j < m; j++) {
					if (backup[i][j].state == 1) { // ���̶�� 
						int dist = abs(archer_y - i) + abs(archer_x - j); // ������ �Ÿ� Ȯ��							
						if (dist <= d) { // ��Ÿ� ���� ���̶�� ��ġ ����
							// ���� ����� ���� ã��, ���� ����� ���� �����̶��, �� �� ���� ������ ã�´�.
							enemy.push_back({dist,i,j});
						}
					}
				}
			}
			if (!enemy.empty()) { // �����Ÿ� �� ���� 1���̶� ���� ���
				sort(enemy.begin(), enemy.end(), cmp); // �� ���� �ִܰŸ�, �� ���ʿ� ��ġ�� ��
				//int enemy_dist = enemy.front().dist;
				int enemy_y = enemy.front().y;
				int enemy_x = enemy.front().x;
				if (backup[enemy_y][enemy_x].isAttacked == false) { // ���� ����ִ� ���̶��  
					backup[enemy_y][enemy_x].isAttacked = true; // ���̰�
					dead_enemy.push({ enemy_y,enemy_x }); // ���� ���� ��ġ�� ����
					kill++; // ���� ���� �� �߰�
				}
			}
		}
		// ���� ���� ���ش�
		while (!dead_enemy.empty()) {
			int dead_y = dead_enemy.front().first;
			int dead_x = dead_enemy.front().second;
			backup[dead_y][dead_x].state = 0;
			backup[dead_y][dead_x].isAttacked = false;
			dead_enemy.pop();				
		}
		// ���� �Ʒ��� ��ĭ�� �̵�
		for (int i = n - 1; i >= 0; i--) {
			for (int j = 0; j < m; j++) {
				if (i == n - 1) {
					backup[i][j].state = 0;
					backup[i][j].isAttacked = 0;
				}
				else {
					backup[i + 1][j] = backup[i][j];
				}
			}
		}
		for (int j = 0; j < m; j++) {
			backup[0][j].state = 0;
			backup[0][j].isAttacked = 0;
		}
	}
	return kill;
}

void dfs(int idx, int cnt) { // ������ 3���� �ü��� ��ġ(�������� ����)
	if (cnt == 3) {		
		int cur = attack(archer);
		result = max(result, cur);		
		return;
	}
	for (int i = idx; i <m; i++) {
		if (visit[i]) continue;
		archer.push_back(archer_candi[i]);
		visit[i] = true;
		dfs(i, cnt + 1);
		archer.pop_back();
		visit[i] = false;
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);
	cin >> n >> m >> d;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j].state;
			map[i][j].isAttacked = false;
		}
	}
	for (int j = 0; j < m; j++)
		archer_candi.push_back(j); // �ü��� �� �� �ִ� ��ġ
	dfs(0, 0);
	cout << result;

}