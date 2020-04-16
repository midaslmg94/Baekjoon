#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string.h>
#define MAX 1000+1
#define endl "\n"
using namespace std;
int n,k,x,y,w;
int building[MAX];
bool visit[MAX];
int result = 0;
vector<int>graph[MAX];
queue<int>q;
void bfs() {
	int q_size = q.size();
	while (!q.empty()) {
		for (int i = 0; i < q_size; i++) {
			int next = q.front();
			int next_cost = building[next];
			q.pop();
		}
	}
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);
	int t;
	int b1; int b2;
	cin >> t;
	while (t--) {
		cin >> n >> k;
		for (int i = 1; i <= n; i++) {
			cin >> building[i]; // 각 건물을 만드는데 드는 시간
		}
		for (int i = 0; i < k; i++) {
			cin >> b1 >> b2;
			graph[b1][b2] = 1;
		}
		for (int i = 1; i <= n; i++) {
			bool flag = true;
			for (int j = 1; j <= n; j++) {
				if (graph[j][i] == 1) {
					flag = false;
				}
			}
			if (flag) {
				q.push(i); // 시작지점 삽입
			}
		}
		cin >> w; // 승리하기 위해 지어야할 건물
		bfs();		
		memset(visit, false, sizeof(visit));
		memset(graph, false, sizeof(graph));
		memset(building, false, sizeof(building));
		result = 0;
	}

	return 0;
}