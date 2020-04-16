#include<bits/stdc++.h>
#define endl "\n"
#define MAX 200
using namespace std;
struct BOOM {
	char state;
	int madeTime;
};
BOOM arr[MAX][MAX];
int dy[5] = { 0,-1,1,0,0 };
int dx[5] = { 0,0,0,-1,1 };
int r, c, n;
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//freopen("input.txt", "r", stdin);
	cin >> r >> c >> n;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> arr[i][j].state;
			if (arr[i][j].state == 'O')
				arr[i][j].madeTime = 0;
		}
	}
	int curTime = 1;
	while (curTime<n) {
		// 폭탄이 빈 부분에 폭탄이 새로 생김			
		curTime++;
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (arr[i][j].state == '.') {
					arr[i][j].state = 'O';
					arr[i][j].madeTime = curTime;
				}
			}
		}
		if (curTime == n)break;
		curTime++;
		// 현재 시간보다 3초전에 만들어진 폭탄이 폭발함
		queue<pair<int, int>>q;
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (arr[i][j].state == 'O' && arr[i][j].madeTime == curTime - 3) {
					for (int k = 0; k < 5; k++) {
						int ny = i + dy[k];
						int nx = j + dx[k];
						if (0 > ny || ny >= r || 0 > nx || nx >= c)continue;
						q.push({ ny,nx });
					}
				}
			}
		}
		while (!q.empty()) {
			int y = q.front().first;
			int x = q.front().second;
			arr[y][x].state = '.';
			arr[y][x].madeTime = 0;
			q.pop();
		}
		if (curTime == n)break;
	}

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << arr[i][j].state;
		}
		cout << endl;
	}
	cout << endl;
	return 0;
}