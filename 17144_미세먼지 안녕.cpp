#include<iostream>
#include<string.h>
#include<vector>
#include<queue>
using namespace std;
int r, c, t;
int map[50][50];
int tmp[50][50];
int dx[4] = { 0,-1,0,1 };
int dy[4] = { -1,0,1,0 };
queue<pair<int, int>>q;
int cango(int x, int y) {// 확산 가능한 지점이 몇개인지
	int cnt = 0;
	for (int k = 0; k < 4; k++) {
		int nx = x + dx[k];
		int ny = y + dy[k];
		if (0 <= nx && nx < r && 0 <= ny && ny < c && map[nx][ny] != -1) {
			cnt++;
		}
	}
	return cnt;
} 

void spread() { //미세먼지 확산	
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (map[i][j] != -1) {
				int cnt = cango(i, j);
				int dust = map[i][j] / 5; //확산되는 먼지양
				int rest = map[i][j] - (dust * cnt); //확산후 남는 먼지양
				for (int k = 0; k < 4; k++) {
					int nx = i + dx[k];
					int ny = j + dy[k];
					if (0 <= nx && nx < r && 0 <= ny && ny < c && map[nx][ny] != -1) {
						tmp[nx][ny] += dust;
					}
				}
				map[i][j] = rest;
			}
		}
	}
	/*cout << endl<<"기존먼지들" << endl;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << map[i][j] << ' ';
		}
		cout << endl;
	}
	cout << endl <<"확산된 먼지들"<< endl;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << tmp[i][j] << ' ';
		}
		cout << endl;
	}


	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			map[i][j] += tmp[i][j];
		}
	}
	cout  <<endl <<"합쳐진 먼지들"<< endl;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << map[i][j] << ' ';
		}
		cout << endl;
	}*/
}
void move(queue<pair<int, int>>q) {//공기청정기 가동 후 미세먼지 이동
	int x1 = q.front().first;
	int y1 = q.front().second;
	q.pop();
	int x2 = q.front().first;
	int y2 = q.front().second;
	// 윗부분
	for (int i = x1; i < r; i++) {

	}
	// 아랫부분 
}

int main() {
	int n = 0;
	cin >> r >> c >> t;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> n;
			map[i][j] = n;
			if (n == -1) {
				q.push(make_pair(i, j));
			}
		}
	}
	spread();
	move(q);

	for (int i = 0; i < t; i++) {
		memset(tmp, 0, sizeof(tmp));
		spread();
		memset(tmp, 0, sizeof(tmp));	//  fill(&tmp[0][0],&tmp[49][50],5); 이건 0이 아닌 값으로 초기화 할때 씀
		move(q);
	}
	int ans = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (map[i][j] != -1)
				ans += map[i][j];
		}
	}
	cout << "\n" << ans;
}