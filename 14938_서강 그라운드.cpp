#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<deque>
#include<string.h>
#define endl "\n"
#define MAX 100+1
#define INF 987564321
using namespace std;
int n, m, r;
int t;
int from, to, dist;
int item[MAX];
int map[MAX][MAX];
int result = -1;
void floyd() {
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (map[i][k] + map[k][j] < map[i][j]) {
					map[i][j] = map[i][k] + map[k][j];
				}
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);
	cin >> n >> m >> r;

	for (int i = 1; i <= n; i++) {
		cin >> item[i];
	}
	for (int i = 0; i < r; i++) {
		cin >> from >> to >> dist;
		map[from][to] = dist;
		map[to][from] = dist;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j)continue;
			if (map[i][j] == 0) {
				map[i][j] = INF;
			}
		}
	}
	floyd();
	for (int i = 1; i <= n; i++) {
		int cur = 0;
		for (int j = 1; j <= n; j++) {			
			if (map[i][j] <= m) {
				cur += item[j];
			}
		}
		result = max(result, cur);
	}
	cout << result;
	return 0;
}