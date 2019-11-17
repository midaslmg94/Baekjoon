#include<iostream>
#include<vector>
using namespace std;
const int MAX = 1001;
int m, n;
vector<int> graph[MAX];
bool visited[MAX];

void dfs(int idx) {
	visited[idx] = true;
	for (int i = 0; i < graph[idx].size(); i++) {
		int next = graph[idx][i];
		if (!visited[next]) {
			dfs(next);
		}
	}
}
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int node1, node2;
		cin >> node1 >> node2;
		graph[node1].push_back(node2);
		graph[node2].push_back(node1);
	}
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			dfs(i);
			cnt++;
		}
	}
	cout << cnt;
}