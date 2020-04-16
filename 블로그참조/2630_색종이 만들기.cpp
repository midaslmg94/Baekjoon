#include<iostream>
#include<vector>
#define endl "\n"
using namespace std;
vector<vector<int>>map;
int n;
int white = 0;
int blue = 0;
void dfs(int y, int x, int len) {
	int color = map[y][x];
	for (int i = y; i < y + len; i++) { // y+len 
		for (int j = x; j < x + len; j++) { // x+len 이 범위를 생각 못함.. 
			if (color != map[i][j]) {
				dfs(y, x, len / 2); // 좌상단
				dfs(y, x + len / 2, len / 2); // 우상단
				dfs(y + len / 2, x, len / 2); // 좌하단
				dfs(y + len / 2, x + len / 2, len / 2); // 우하단
				return; // 여기에 return 넣기
			}
		}
	}
	if (color == 0)white++;
	else blue++;

}
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);
	cin >> n;
	int val;
	for (int i = 0; i < n; i++) {
		vector<int>tmp;
		for (int j = 0; j < n; j++) {
			cin >> val; // 0:하얀색, 1:파란색
			tmp.push_back(val);
		}
		map.push_back(tmp);
	}
	dfs(0, 0, n);
	cout << white << endl << blue << endl;
	return 0;
}