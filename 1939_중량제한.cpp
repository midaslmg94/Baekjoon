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
vector<pair<int, int>>map[MAX]; // ������, ���
bool visit[MAX];
int start_fatctory;
int finish_factory;
bool bfs(int start, int limitWeight) { // �ش� ���Է� ���� ���忡�� ���� ������� �� �� �ִ°�
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
			if (!visit[next] && limitWeight <= nextCost) { // �� <= �ΰ�����
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
		if(bfs(start_fatctory, mid)==true) { // �߷��� �� �÷��� ��
			low = mid + 1;
		}
		else { // �ش� ���Է� �� �� ������ �߷��� ����
			high = mid - 1;
		}
	}
	cout << high;
	return 0;
}