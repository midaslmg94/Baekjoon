#include<iostream>
#include<algorithm>
#include<vector>
#include<string.h>
#define endl "\n"
#define MAX 2000
using namespace std;
int n, m;
int a, b;
vector<int>v[MAX];
bool visit[MAX];
bool flag = false;
void dfs(int idx, int cnt) {
	if (cnt == 5) {
		flag = true;
		return;
	}
	visit[idx] = true;
	for (int i = 0; i < v[idx].size(); i++) {
		int next = v[idx][i]; 
		if (!visit[next]) { // visit[i]로 해서 틀렸었다
			visit[next] = true;
			dfs(next, cnt + 1);
			visit[next] = false;
		}
	}
	visit[idx] = false;
}
void prt() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < v[i].size(); j++) {
			cout << v[i][j] << ' ';
		}
		cout << endl;
	}
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}	
	for (int i = 0; i < n; i++) {		
		dfs(i, 1);
		if (flag == true)break;
	}
	if (flag) {
		cout << 1;
	}
	else cout << 0;
	return 0;
}