#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string.h>
#define endl "\n"
#define MAX 100000+1
using namespace std;
int n, m;
int a, b, c;
vector<pair<int, int>>map[MAX]; // 연결노드, 비용
bool visit[MAX];
int start_fatctory;
int finish_factory;
bool bfs(int start, int cost) { // 해당 무게로 시작 공장에서 최종 공장까지 갈 수 있는가
	queue<int>q;
	q.push(start);
	visit[start] = true;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		if (cur == finish_factory) {
			return true;
		}
		for (int i = 0; i < map[cur].size(); i++) {
			int next = map[cur][i].first;
			int nextCost = map[cur][i].second;
			if (!visit[next] && cost <= nextCost) { // 해당 무게가 지나갈 수 있는지 확인
				visit[next] = true;
				q.push(next);
			}
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);
	cin >> n >> m;
	int low = 0;
	int high = 0;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;		
		map[a].push_back({ b,c });
		map[b].push_back({ a,c });
		high = max(high, c);
	}
	cin >> start_fatctory >> finish_factory;

	while (low <= high) {
		int mid = (low + high) / 2;
		memset(visit, false, sizeof(visit));
		if(bfs(start_fatctory, mid)==true) { // 중량을 더 늘려야 함
			low = mid + 1;
		}
		else { // 해당 무게로 갈 수 없으면 중량을 줄임
			high = mid - 1;
		}
	}
	cout << high;
	return 0;
}