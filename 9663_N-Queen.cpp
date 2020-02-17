#include<iostream>
using namespace std;
int map[15][15];
int res = 0;
int n;
bool possible(int num, int x) { // ���� �������� ����,����, �밢���� �ٸ� ���� �����ϴ��� Ȯ��
	for (int i = 0; i < num; i++) {
		if (map[i][x] == 1) {
			return false;
		}
	}

}
void dfs(int cnt) {
	if (cnt==n) {
		res++;
		return;
	}
	for (int i = 0; i < n; i++) {
		if (possible(cnt, i)) {
			map[cnt][i]=1;
			dfs(cnt + 1);
			map[cnt][i] = 0;
		}
	}

}
int main() {
	freopen("input.txt", "r", stdin);
	cin >> n;
	dfs(0);
	cout << res;
}