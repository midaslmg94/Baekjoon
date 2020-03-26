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
		sort(tower.begin(), tower.end(), cmp); // 0,0 부터 차례대로 오름차순
		for (int i = 0; i < n; i++) {
			int y = tower[i].y;
			int x = tower[i].x;
			int scope = tower[i].scope;
			for (int j = i + 1; j < n; j++) {
				// i번째 부대가 i+1번째~ n-1번째 부대 중 어떤 부대와 통신이 가능한지 확인
				int ny = tower[j].y;
				int nx = tower[j].x;
				int nscope = tower[j].scope;
				int dist = ((ny - y) * (ny - y)) + ((nx - x) * (nx - x)); // 두 점 사이의 거리
				int dist_scope = (scope + nscope) * (scope + nscope); // 원 사이의 거리 --> 루트를 안하기 위해 제곱해줌								
				if (dist <= dist_scope) { // 두 점 사이의 거리가 더 작다 --> 두 부대는 통신 가능(하나의 그룹)				
					mergeParent(parent[i], parent[j]);					
				}
			}
		}
		// 몇개의 집합으로 나뉘었는 지 확인
		for (int i = 0; i < n; i++) {
			cout << parent[i] << ' ';
		}
		cout << endl;

		for (int i = 0; i < n - 1; i++) { // 부모 노드의 개수를 찾는 것
			if (parent[i] != parent[i + 1]) {
				answer++;
			}
		}
		cout << answer << endl;
	}
	return 0;
}