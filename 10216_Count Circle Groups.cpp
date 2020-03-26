#include<iostream>
#include<algorithm>
#include<vector>
#include<string.h>
#define endl "\n"
using namespace std;
int tc;
int n;
int y, x, scope;
int parent[5050];
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
	else
		return;
}
bool cmp(const TOWER& a, const TOWER& b) {

	if (a.scope > b.scope) {
		return true;
	}
	else if (a.scope == b.scope) {
		if (a.y < b.y)
			return true;
		else
			return false;
	}
	return false;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);
	cin >> tc;
	while (tc--) {
		cin >> n;
		vector<TOWER>tower;
		int answer = 1;
		memset(parent, 0, sizeof(parent));
		for (int i = 0; i < n; i++) {
			cin >> y >> x >> scope;
			tower.push_back({ y,x,scope });
			parent[i] = i;
		}
		sort(tower.begin(), tower.end(), cmp); // 0,0 ���� ���ʴ�� ��������
		for (int i = 0; i < n; i++) {
			int y = tower[i].y;
			int x = tower[i].x;
			int scope = tower[i].scope;
			for (int j = i + 1; j < n; j++) {
				// i��° �δ밡 i+1��°~ n-1��° �δ� �� � �δ�� ����� �������� Ȯ��
				int ny = tower[j].y;
				int nx = tower[j].x;
				int nscope = tower[j].scope;
				int dist = ((ny - y) * (ny - y)) + ((nx - x) * (nx - x)); // �� �� ������ �Ÿ�
				int dist_scope = (scope + nscope) * (scope + nscope); // �� ������ �Ÿ� --> ��Ʈ�� ���ϱ� ���� ��������								
				if (dist <= dist_scope) { // �� �� ������ �Ÿ��� �� �۴� --> �� �δ�� ��� ����(�ϳ��� �׷�)				
					mergeParent(parent[i], parent[j]);					
				}
			}
		}
		// ��� �������� �������� �� Ȯ��
		for (int i = 0; i < n; i++) {
			cout << parent[i] << ' ';
		}
		cout << endl;

		for (int i = 0; i < n - 1; i++) { // �θ� ����� ������ ã�� ��
			if (parent[i] != parent[i + 1]) {
				answer++;
			}
		}
		cout << answer << endl;
	}
	return 0;
}