#include<iostream>
#include<queue>
#include<vector>
#define MAX 32001
using namespace std;

int n, m;
vector<int>adj[MAX]; // 서로 연결
int indegree[MAX]; // indegree 정보

void topo_sort() { // 위상정렬
	int result[MAX];
	queue<int>q;
	// 진입차수가 0인 노드를 큐에 삽입
	for (int i = 1; i <= n; i++) {
		if (indegree[i] == 0) {
			q.push(i);
		}
	}
	//위상정렬이 완전히 수행되려면 n개의 노드방문
	for (int i = 1; i <= n; i++) {
		if (q.empty()) {
			cout << "사이클이 발생";
			return;
		}
		int x = q.front();
		q.pop();
		result[i] = x; // 위상정렬이 완성된 배열
		for (int i = 0; i < adj[x].size(); i++) {
			int y = adj[x][i];
			if (--indegree[y] == 0) {
				q.push(y);
			}
		}
	}
	for (int i = 1; i <= n;i++) {
		cout << result[i] << ' ';
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);	cout.tie();
	freopen("input.txt", "r", stdin);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int front, back;
		cin >> front >> back;
		adj[front].push_back(back);
		indegree[back]++;
	}
	topo_sort();
}