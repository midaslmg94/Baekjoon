#include<iostream>
#include<algorithm>
#include<string.h>
#include<queue>
#include<vector>
#define MAX 5
#define endl "\n"
using namespace std;
int n,m;
int map[MAX][MAX];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	if (n == 1 || m == 1) {
		cout << 0;
		return 0;
	}

}