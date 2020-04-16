#include<bits/stdc++.h>
#define endl "\n"
#define MAX 1000
#define pii pair<int,int>
using namespace std;
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
int n, m;
int ground[MAX][MAX];
int component[MAX][MAX];
bool visit[MAX][MAX];
int cnt = 1;
int result = 0;
vector<pii>v;
vector<pii>graph;
void Prt() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << component[i][j] << ' ';
		}
		cout << endl;
	}
}

int dfs(int y, int x, int cnt) {
	result = max(result, cnt);	
	for (int k = 0; k < 4; k++) {
		int ny = y + dy[k];
		int nx = x + dx[k];
		if (0 > ny || ny >= n || 0 > nx || nx >= m)continue;
		if (visit[ny][nx])continue;
		if (ground[ny][nx] == 0 && component[ny][nx] == 0) {
			visit[ny][nx] = true;
			graph.push_back({ ny,nx });
			dfs(ny, nx, cnt + 1);	
			
		}
	}
	return result;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string str; cin >> str;
		for (int j = 0; j < m; j++) {
			ground[i][j] = str[j] - '0';
			if (ground[i][j] == 0)
				v.push_back({ i,j });
		}
	}

	for (int i = 0; i < v.size(); i++) {
		int y = v[i].first;
		int x = v[i].second;
		if (component[y][x] == 0) {
			graph.push_back({ y,x });
			visit[y][x] = true;
			int res = dfs(y, x, 1);
			result = 0;
			for (int j = 0; j < graph.size(); j++) {
				component[graph[j].first][graph[j].second] = res;
			}
			graph.clear();
		}
	}

	Prt();
	cout << endl;
	return 0;
}