#include<iostream>
#include<algorithm>
#define MAX 101
#define INF 987654321
using namespace std;
int arr[MAX][MAX];
int result[MAX][MAX];
int n, m;
int from, to, cost;
/*
	플로이드 와샬 :모든 정점에 대해 모든 다른 정점에 대한 최단 경로를 다 구함

*/
void floyd() {
	for (int k = 1; k <= n; k++) {// k : 거쳐가는 노드
		for (int i = 1; i <= n; i++) { // i : from
			for (int j = 1; j <= n; j++) { // j : to
				if (arr[i][k] + arr[k][j] < arr[i][j]) { // k를 거쳐가는게 더 작으면
					arr[i][j] = arr[i][k] + arr[k][j];
				}
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);	cout.tie();
	freopen("input.txt", "r", stdin);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> from >> to >> cost;
		if (arr[from][to] != 0) {
			arr[from][to] = min(arr[from][to], cost);
		}
		else {
			arr[from][to] = cost;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j)continue;
			if (arr[i][j] == 0)
				arr[i][j] = INF;
		}
	}
	floyd();

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
	// 갈 수 없는 경우 INF를 0으로 바꿈
			if (arr[i][j] == INF)
				arr[i][j] = 0;
			cout << arr[i][j] << ' ';
		}
		cout << "\n";
	}
}