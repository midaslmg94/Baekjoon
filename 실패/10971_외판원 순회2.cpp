#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#define MAX 10
using namespace std;
typedef pair<int, int>pii;
vector<pii>map[MAX];
bool visit[MAX];
int n;
int min_cost = 987'654'321;
int tsp(int start) {
	int cost=0;	
	bool flag = false;
	priority_queue<pii, vector<pii>, greater<pii>>pq;
	for (int i = 0; i < map[start].size(); i++) {
		int next = map[start][i].first;
		int next_cost = map[start][i].second;
		pq.push({next_cost, next}); // cost¸ÕÀú
	}
	while (!pq.empty()) {
		int cur_cost = pq.top().first;
		int cur = pq.top().second;
		pq.pop();
		if (visit[cur])
			continue;
		cost += cur_cost;
		visit[cur] = true;
		flag = true;
		for (int i = 0; i < map[cur].size(); i++) {
			int next = map[cur][i].first;
			int next_cost = map[cur][i].second;
			pq.push({ next_cost, next });			
		}
	}
	return cost;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int tmp;
			cin >> tmp;
			map[i].push_back({j,tmp});
		}
	}
	for (int i = 0; i < n; i++) {
		int res = tsp(i);
		min_cost = min(min_cost, res);
		memset(visit, false, sizeof(visit));
	}
	cout << min_cost;
}