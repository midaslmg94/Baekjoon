#include<bits/stdc++.h>
#define endl "\n"
#define MAX 11
#define INF 987654321
using namespace std;
int arr[MAX][MAX];
int people[MAX]; // ������ �α���
int sector[MAX]; // �ش� ������ ��� ���ű��� ���ԵǴ� ��
bool visit[MAX];
int n;
int m, k;
vector<int>groupA; // A ����
vector<int>groupB; // B ����

bool bfs(vector<int>v) {
	memset(visit, false, sizeof(visit));
	queue<int>q;
	int idx = sector[v[0]]; // A���� : 1, B���� : 2
	int cnt = 1; // ��� ����Ǿ� �ִ���
	q.push(v[0]);
	visit[v[0]] = true;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int i = 1; i <= n; i++) {
			if (arr[cur][i] == 1 && sector[i] == idx && visit[i] == false) { // ����, ���� ����, �̹湮
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
	for (int i = 1; i <= n / 2; i++) { // n�� �� i�� �̱�
		vector<int>v(n, 1);
		for (int j = 0; j < i; j++) {
			v[j] = 0;
		}
		do {
			groupA.clear();
			groupB.clear();
			// ���ű� A, B�� ����
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
			// ���� ���ű������� �̾�����,  �ٸ� ���ű������� �������ִ��� Ȯ��
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