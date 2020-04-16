#include<iostream>
#include<vector>
#include<queue>
#define MAX 100
using namespace std;
int n;
queue<pair<int, int>>v[MAX];
bool visit[MAX];
int map[MAX][MAX];
void floyd() {
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (map[i][k] == 1 && map[k][j] == 1) {
					map[i][j] = 1;
				}
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);
	cin >> n;
	int tmp;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> tmp;
			map[i][j] = tmp;
		}
	}
	floyd();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << map[i][j]<<' ';
		}
		cout << "\n";
	}
}