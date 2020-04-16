#include<iostream>
#include<vector>
#include<string.h>
#include<algorithm>
#define MAX 10
using namespace std;
int dy[8] = { -1,-1,-1,0,0,1,1,1 };
int dx[8] = { -1,0,1,-1,1,-1,0,1 };
int N, M, K; // 땅 크기, 나무의 개수, K년
struct TREE {
	int age;
	bool isAlive;
};
bool cmp(TREE a, TREE b) {// 나이순으로 오름차순 정렬
	return a.age < b.age;
}
vector<TREE>map[MAX][MAX]; // 각 나무의 나이
int energy[MAX][MAX]; // 각 칸이 가지고 있는 양분
int robot[MAX][MAX]; // 각 칸에 추가되는 양분
int die_energy = 0;
void spring_summer() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j< N; j++) {
			if (map[i][j].size()) {// 나무가 존재하면 양분을 먹는다
				sort(map[i][j].begin(), map[i][j].end(),cmp); // 나이가 어린순으로 정렬
				die_energy = 0;
				for (int k = 0; k < map[i][j].size(); k++) {
					if (energy[i][j] >= map[i][j][k].age &&map[i][j][k].age != 0 && map[i][j][k].isAlive==true) { // 이렇게 벡터가 들어가는걸 잘  모르겠다..
						int age = map[i][j][k].age;
						energy[i][j] = energy[i][j] - age;
						map[i][j][k].age++;
					}
					else { // 양분을 먹지 못하는 경우 --> 다 죽음						
						map[i][j][k].isAlive = false;
						die_energy += map[i][j][k].age / 2; // 죽은 영양분들
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
					if (map[i][j][k].isAlive == true && map[i][j][k].age%5==0) { // 살아있는 나무, 나이가 5의 배수
						// 8칸으로 나무번식
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