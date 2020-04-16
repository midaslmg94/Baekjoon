#include<bits/stdc++.h>
#define endl "\n"
#define MAX 201
#define INF 987564321
using namespace std;
int n, m;
int from, to, cost;
int station[MAX][MAX];
int result[MAX][MAX];
void floyd() {
	for (int k = 1; k <= n; k++) { // 거쳐가는 노드
		for (int i = 1; i <= n; i++) { // from
			for (int j = 1; j <= n; j++) { // to 
				if (station[i][j] > station[i][k] + station[k][j]) {// k부터 j까지 가는데 i를 거쳐간다
					station[i][j] = station[i][k] + station[k][j];
					result[i][j] = result[i][k];  // 이 부분이 이해가 잘 안감
				}
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> from >> to >> cost;
		station[from][to] = cost;
		station[to][from] = cost;
		result[from][to] = to;
		result[to][from] = from;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i != j) {
				if (station[i][j] == 0) {
					station[i][j] = INF;
				}
			}
		}
	}
	floyd();
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j)cout << '-';
			else cout << result[i][j];
			cout << ' ';
		}
		cout << endl;
	}

	return 0;
}