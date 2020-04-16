#include<iostream>
#include<vector>
#include<string.h>
#include<algorithm>
#define MAX 10
using namespace std;
int dy[8] = { -1,-1,-1,0,0,1,1,1 };
int dx[8] = { -1,0,1,-1,1,-1,0,1 };
int N, M, K; // �� ũ��, ������ ����, K��
struct TREE {
	int age;
	bool isAlive;
};
bool cmp(TREE a, TREE b) {// ���̼����� �������� ����
	return a.age < b.age;
}
vector<TREE>map[MAX][MAX]; // �� ������ ����
int energy[MAX][MAX]; // �� ĭ�� ������ �ִ� ���
int robot[MAX][MAX]; // �� ĭ�� �߰��Ǵ� ���
int die_energy = 0;
void spring_summer() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j< N; j++) {
			if (map[i][j].size()) {// ������ �����ϸ� ����� �Դ´�
				sort(map[i][j].begin(), map[i][j].end(),cmp); // ���̰� ������� ����
				die_energy = 0;
				for (int k = 0; k < map[i][j].size(); k++) {
					if (energy[i][j] >= map[i][j][k].age &&map[i][j][k].age != 0 && map[i][j][k].isAlive==true) { // �̷��� ���Ͱ� ���°� ��  �𸣰ڴ�..
						int age = map[i][j][k].age;
						energy[i][j] = energy[i][j] - age;
						map[i][j][k].age++;
					}
					else { // ����� ���� ���ϴ� ��� --> �� ����						
						map[i][j][k].isAlive = false;
						die_energy += map[i][j][k].age / 2; // ���� ����е�
					}
				}
			}
			energy[i][j] += die_energy;
		}
	}
}

void fall() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j].size()) {
				for (int k = 0; k < map[i][j].size(); k++) {
					if (map[i][j][k].isAlive == true && map[i][j][k].age%5==0) { // ����ִ� ����, ���̰� 5�� ���
						// 8ĭ���� ��������
						for (int dir = 0; dir < 8; dir++) {
							int ny = i + dy[dir];
							int nx = j + dx[dir];
							if (nx >= 0 && ny >= 0 && nx < N && ny < N)
							{
								map[ny][nx].push_back({ 1,true });
							}
						}
					}
				}
			}
		}
	}
}

void winter() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			energy[i][j] += robot[i][j];			
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);
	freopen("input.txt", "r", stdin);
	cin >> N >> M >> K;	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {			
			cin >> robot[i][j];
			energy[i][j] = 5; 
		}
	}
	for (int i = 0; i < M; i++) {
		int r, c, age;
		cin >> r >> c >> age;
		map[r-1][c-1].push_back({ age, true });
	}
	while (K--) {		
		spring_summer();		
		fall();
		winter();
	}
	int ans = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < map[i][j].size(); k++) {
				if (map[i][j][k].isAlive == true && map[i][j][k].age>=1) {
					ans++;
				}
			}
		}
	}
	cout << ans;
}