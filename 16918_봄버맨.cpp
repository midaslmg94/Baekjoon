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
	freopen("input.txt", "r", stdin);
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
		// ∆¯≈∫¿Ã ∫Û ∫Œ∫–ø° ∆¯≈∫¿Ã ªı∑Œ ª˝±Ë			
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
		// «ˆ¿Á Ω√∞£∫∏¥Ÿ 3√ ¿¸ø° ∏∏µÈæÓ¡¯ ∆¯≈∫¿Ã ∆¯πﬂ«‘
		queue<pair<int, int>>q;
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (arr[i][j].state == 'O' && arr[i][j].madeTime == curTime - 3) {
					for (int k = 0; k < 5; k++) {
						int ny = i + dy[k];
						int nx = j + dx[k];
						if (0 > ny || ny >= r || 0 > nx || nx >= c)continue;
						q.push({ ny,nx }); // ≈•ø° æ»≥÷∞Ì πŸ∑Œ πŸ≤Ÿ¥œ ø¿¥‰¿Ã ∂πæ˙¿Ω
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