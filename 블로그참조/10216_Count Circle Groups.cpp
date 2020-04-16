#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<string.h>
#define endl "\n"
using namespace std;
int tc;
int n;
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,1,-1 };
int y, x, range;
int parent[3000 + 1];
struct TOWER {
	int y;
	int x;
	int scope;
};
int findParent(int n) {
	if (n != parent[n]) {
		return parent[n] = findParent(parent[n]);
	}
	return n;
}
void mergeParent(int n1, int n2) {
	n1 = findParent(n1);
	n2 = findParent(n2);
	if (n1 != n2) {
		if (n1 > n2) {
			parent[n1] = n2;
		}
		else {
			parent[n2] = n1;
		}
	}
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//freopen("input.txt", "r", stdin);
	cin >> tc;
	while (tc--) {
		cin >> n;
		vector<TOWER>tower;
		int answer = 0;
		memset(parent, 0, sizeof(parent));
		for (int i = 0; i < n; i++) {
			cin >> y >> x >> range;
			tower.push_back({ y,x,range });
			parent[i] = i;
		}
		for (int i = 0; i < tower.size(); i++) {
			int y = tower[i].y;
			int x = tower[i].x;
			int scope = tower[i].scope;
			for (int j = i + 1; j < tower.size(); j++) {
				// i��° �δ밡 i+1��°~ n-1��° �δ� �� � �δ�� ����� �������� Ȯ��
				int ny = tower[j].y;
				int nx = tower[j].x;
				int nscope = tower[j].scope;
				int dist = ((ny - y) * (ny - y)) + ((nx - x) * (nx - x)); // �� �� ������ �Ÿ�
				int dist_scope = (scope + nscope) * (scope + nscope); // �� ������ �Ÿ� --> ��Ʈ�� ���ϱ� ���� ��������								
				if (dist <= dist_scope) { // �� �� ������ �Ÿ��� �� �۴� --> �� �δ�� �̾���
					if (findParent(i) != findParent(j)) {
						mergeParent(i, j);
					}
				}
			}
		}
		// �θ��Ʈ�� ������ ã��
		for (int i = 0; i < n; i++) {
			if (parent[i] == i) {
				answer++;
			}
		}
		cout << answer << endl;
	}
	return 0;
}