#include<iostream>
#include<vector>
using namespace std;
int n, m;
vector<int>map[101];
bool check[101];

int cnt = 0;
void dfs(int idx) {
	check[idx] = true;
	for (int i = 0; i < map[idx].size(); i++) {
		int next = map[idx][i];
		if (!check[next]) {
			dfs(next);
			cnt++;
		} 
	}
}
int main() {
	cin >> n;
	cin >> m;

	int node1, node2;
	for (int i = 0; i < m; i++) {
		cin >> node1 >> node2;
		map[node1].push_back(node2);
		map[node2].push_back(node1);
	}
	dfs(1);
	cout << cnt;

}