#include<iostream>
#include<algorithm>
#include<string.h>
#include<queue>
#include<vector>
#define MAX 6
#define endl "\n"
using namespace std;
char map[MAX][MAX];
char backup[MAX][MAX]; // ��ֹ� ������� ������ ����
vector<pair<int, int>>space; // �� ���� : ��ֹ��� �� ��
vector<pair<int, int>>teacher; // �������� ��ġ

bool visit[MAX * MAX];
int n;
bool findStudent() {	
	bool isFind = false;  // �л��� �߰��Ͽ�����
	for (int i = 0; i < teacher.size(); i++) {
		int ty = teacher[i].first;
		int tx = teacher[i].second;
		bool findRight = true; bool findLeft = true;  // �ش� ���⿡ ��ֹ��� �ִٸ� �� Ž�� X 
		bool findUp = true; bool findDown = true;
		for (int dir = 1; dir < n; dir++) {
			if (tx + dir < n && findRight) { // ���������� Ȯ��
				if (backup[ty][tx + dir] == 'O') { // ��ֹ�
					findRight = false;
					isFind = false;
				}
				else if (backup[ty][tx + dir] == 'S') { // �л�
					isFind = true;
					return true;
				}
				else { // �����
					isFind = false;
				}
			}
			if (tx - dir >= 0 && findLeft) { // �������� Ȯ��
				if (backup[ty][tx - dir] == 'O') {
					findLeft = false;
					isFind = false;
				}
				else if (backup[ty][tx - dir] == 'S') {
					isFind = true;
					return true;
				}
				else {
					isFind = false;
				}
			}
			if (ty + dir < n && findDown) { // �Ʒ������� Ȯ��
				if (backup[ty + dir][tx] == 'O') {
					findDown = false;
					isFind = false;					
				}
				else if (backup[ty + dir][tx] == 'S') {
					isFind = true;
					return true;
				}
				else {
					isFind = false;
				}
			}
			if (ty - dir >= 0 && findUp) { // �������� Ȯ��
				if (backup[ty - dir][tx] == 'O') {
					findUp = false;
					isFind = false;
				}
				else if (backup[ty - dir][tx] == 'S') {
					isFind = true;		
					return true;
				}
				else {
					isFind = false;
				}
			}
		}
	}
	return isFind;
}

void dfs(int idx, int depth) {
	if (depth == 3) { // 3���� ��ֹ��� ��ġ�� �����
		memcpy(backup, map, sizeof(backup));
		for (int i = 0; i < space.size(); i++) {
			if (visit[i]) {
				int y = space[i].first;
				int x = space[i].second;
				backup[y][x] = 'O';
			}
		}
		if (!findStudent()) {
			cout << "YES";
			exit(0);
		}
		return;
	}

	// �� �������� ��ֹ��� �� ��ġ ���� (����)
	for (int i = idx; i < space.size(); i++) {
		if (visit[i]) continue;
		visit[i] = true;
		dfs(i, depth + 1);
		visit[i] = false;
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'X')
				space.push_back({ i,j });
			else if (map[i][j] == 'T')
				teacher.push_back({ i,j });
		}
	}
	dfs(0, 0);
	cout << "NO";
	return 0;	
}