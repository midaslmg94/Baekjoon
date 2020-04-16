#include<bits/stdc++.h>
#define endl "\n"
#define MAX 11
#define INF 987654321
using namespace std;
int arr[MAX][MAX];
int people[MAX]; // 구역별 인구수
int sector[MAX]; // 해당 구역이 어느 선거구에 포함되는 지
bool visit[MAX];
int n;
int m, k;
vector<int>groupA; // A 구역
vector<int>groupB; // B 구역

bool bfs(vector<int>v) {
	memset(visit, false, sizeof(visit));
	queue<int>q;
	int idx = sector[v[0]]; // A구역 : 1, B구역 : 2
	int cnt = 1; // 몇개가 연결되어 있는지
	q.push(v[0]);
	visit[v[0]] = true;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int i = 1; i <= n; i++) {
			if (arr[cur][i] == 1 && sector[i] == idx && visit[i] == false) { // 연결, 같은 구역, 미방문
				visit[i] = true;
				q.push(i);
				cnt++;
			}
		}
	}
	if (cnt == v.size())return true;
	else return false;	
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> people[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> m;
		for (int j = 0; j < m; j++) {
			cin >> k;
			arr[i][k] = 1;
			arr[k][i] = 1;
		}
	}
	int res = INF;
	for (int i = 1; i <= n / 2; i++) { // n개 중 i개 뽑기
		vector<int>v(n, 1);
		for (int j = 0; j < i; j++) {
			v[j] = 0;
		}
		do {
			groupA.clear();
			groupB.clear();
			// 선거구 A, B로 나눔
			for (int k = 1; k <= n; k++) {
				if (v[k - 1] == 0) {
					sector[k] = 1;
					groupA.push_back(k);
				}
				else {
					sector[k] = 2;
					groupB.push_back(k);
				}
			}
			// 같은 선거구끼리는 이어지고,  다른 선거구끼리는 떨어져있는지 확인
			bool flagA = bfs(groupA);
			bool flagB = bfs(groupB);

			if (flagA && flagB) {
				int peopleA = 0;
				int peopleB = 0;
				for (int i = 0; i < groupA.size(); i++) {
					peopleA += people[groupA[i]];
				}
				for (int i = 0; i < groupB.size(); i++) {
					peopleB += people[groupB[i]];
				}
				res = min(res, abs(peopleA - peopleB));
			}
		} while (next_permutation(v.begin(), v.end()));
	}

	if (res == INF)cout << -1;
	else cout << res;
	return 0;
}