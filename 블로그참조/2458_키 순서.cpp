#include<iostream>
#include<algorithm>
#include<string.h>
#define endl "\n"
#define MAX 500+1
#define INF 987654321
using namespace std;
int n, m;
int map[MAX][MAX];
int come_in[MAX]; // 나보다 키가 작은 학생
int come_out[MAX]; // 키가 더 큰 학생
int answer = 0;
void floyd() {
	for (int k = 1; k <= n; k++) { // 거쳐가는 노드 
		for (int i = 1; i <= n; i++) { // 시작 노드 
			for (int j = 1; j <= n; j++) { // 도착 노드
				map[i][j] = min(map[i][j], map[i][k] + map[k][j]);				
			}
		}
	}
	for (int i = 1; i <= n; i++) { // 시작 노드 
		for (int j = 1; j <= n; j++) { // 도착 노드
			if (map[i][j] == INF||map[i][j]==0)continue;
			come_out[i] += 1;
			come_in[j] += 1;
		}
	}
	for (int i = 1; i <= n; i++) {
		int tmp = n - (come_in[i] + come_out[i]);
		if (tmp == 1) {
			answer++;
		}
	}

}
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);
	cin >> n >> m;
	int small; int tall;
	for (int i = 0; i < m; i++) {
		cin >> small >> tall;
		map[small][tall] = 1;
	}
	// 이 부분을 놓쳤었다.
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j)continue;
			if (map[i][j] == 0)
				map[i][j] = INF; // 갈 수 없는 곳은 무한대
		}
	}
	floyd();
	cout << answer;
	return 0;
}