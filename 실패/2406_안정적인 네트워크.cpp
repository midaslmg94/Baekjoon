#include<bits/stdc++.h>
#define endl "\n"
#define MAX 1001
#define pii pair<pair<int,int>,int>
using namespace std;
priority_queue<pii, vector<pii>, greater<pii>>pq;
vector <vector<pair<int, int>>>v;
int parent[MAX];
int n, m;
int Find(int n) {
	if (parent[n] != n) {
		return parent[n] = Find(parent[n]);
	}
	return n;
}
void Union(int n1, int n2) {
	n1 = Find(n1);
	n2 = Find(n2);
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
	freopen("input.txt", "r", stdin);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		parent[i] = i; // ÃÊ±âÈ­
	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		Union(a, b);
	}
	int cost;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> cost;
			if (cost == 0)continue;
			v[i].push_back({ cost,j });
			pq.push({ {i,j},cost });
		}
	}
	
	cout << endl << "-----\n";

	return 0;
}