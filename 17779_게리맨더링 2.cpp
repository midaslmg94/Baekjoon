#include<iostream>
#include<string.h>
#include<algorithm>
#include<vector>
#define MAX 20+1
struct {
	int sector;
	int people;
}map[MAX][MAX];

using namespace std;

int n;
int cnt[6]; // ���ű� �� �α���

int calculate() { // ���ű� �� �α����� ����
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int idx = map[i][j].sector;
			cnt[idx] += map[i][j].people;			
		}
	}
	sort(cnt, cnt + 6); 
	return cnt[5]-cnt[1];
}

/*
	1�� ���ű�: 1 �� r < x+d1, 1 �� c �� y
	2�� ���ű�: 1 �� r �� x+d2, y < c �� N
	3�� ���ű�: x+d1 �� r �� N, 1 �� c < y-d1+d2
	4�� ���ű�: x+d2 < r �� N, y-d1+d2 �� c �� N

	int d1 = 1;
	int d2=1; // ������ d1,d2>=1, d1=1, d2=1
	int x; // ������ 1<= x < x+d1+d2 <=N,  1<=x && x<=N-2
	int y; // ������ 1<= y-d1 < y < y+d2 <=N,  2<=y && y<=N-1
*/

void dfs(int x, int y, int d1, int d2) {
	// 1������
	// 2������
	// 3������
	// 4������
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);
	freopen("input.txt", "r", stdin);

	cin >> n;
	int tmp;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin>>map[i][j].people;			
			map[i][j].sector = 0;
		}
	}
}