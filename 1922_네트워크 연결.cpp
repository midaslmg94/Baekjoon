#include<iostream>
#include<vector>
#include<queue>
#define INF 12'345'678
#define MAX 1001
using namespace std;
typedef pair<int, int> pii;
int n, m;
int a, b, cost;
vector<pii>v[MAX];
bool visit[MAX];
/*
 �� ��ǻ�͸� �����ϴµ� �ʿ��� ����� �־����� �� 
 ��� ��ǻ�͸� �����ϴµ� �ʿ��� �ּҺ���� ����϶�. 
 ��� ��ǻ�͸� ������ �� ���� ���� ����.
 --> ���� �˰���, �켱���� ť ���
*/

void prim(int start) {
	visit[start] = true;
	priority_queue< pii, vector< pii>, greater<pii>>pq; // ������, ���, �ּ����̶� ����ġ�� ������ ����
	for (int i = 0; i < v[start].size(); i++) {
		int nextNode = v[start][i].first;
		int nextCost = v[start][i].second;
		pq.push({ nextCost, nextNode });// first�� �������� �ּ����� �����ϹǷ� ����� first�� ���� 
	}
	int ans = 0;
	while (!pq.empty()) {
		int cost = pq.top().first;
		int cur = pq.top().second;
		pq.pop();
		if (visit[cur])
			continue;
		visit[cur] = true;
		ans += cost;
		// ���� ������ ť�� ����
		for (int i = 0; i < v[cur].size(); i++) {
			int next = v[cur][i].first;
			int next_cost = v[cur][i].second;
			pq.push({ next_cost, next });
		}
	}
	cout << ans;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	freopen("input.txt", "r", stdin);
	cin >> n >> m;

	for (int i = 1; i <= m; i++) {
		// a�� b�� �����ϴµ� cost��ŭ ���.
		cin >> a >> b >> cost;
		v[a].push_back({ b,cost });
		v[b].push_back({ a,cost });
	}
	prim(1); // 1�� ��ǻ�ͺ��� ����
}