#include<iostream>
#include<vector>
#define MAX 201
using namespace std;
int n, m;
int map[MAX][MAX];
int parent[MAX];

int findParent(int n1) {// n1의 부모 찾기
	if (n1 == parent[n1])
		return n1;
	return n1 = findParent(parent[n1]);
}
void unionParent(int n1, int n2) { // n1과 n2의 부모 합치기
	n1 = findParent(n1);
	n2 = findParent(n2);
	if (n1 != n2) {
		if (n1 < n2)
			parent[n2] = n1;
		else
			parent[n1] = n2;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);	cout.tie();
	freopen("input.txt", "r", stdin);
	cin >> n;
	cin >> m;
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (map[i][j] == 1) {
				unionParent(i, j);
			}
		}
	}

	int tmp = 0;
	int tmp_parent;
	int n_tmp = 0;
	int n_tmp_parent = 0;
	cin >> tmp;
	tmp_parent = findParent(tmp);

	for (int i = 1; i < m; i++) {
		cin >> n_tmp;
		n_tmp_parent = findParent(n_tmp);
		if (tmp_parent != n_tmp_parent) {
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
}
