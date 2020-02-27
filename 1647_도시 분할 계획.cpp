#include<iostream>
#include<vector>
#include<algorithm>
#define MAX 100000+1
using namespace std;
int n, m;
int n1, n2,cost;
int result = 0; 
int parent[MAX];
vector<pair<int, pair<int,int>>>graph; // ����ġ, ���� A, ���� B
int findParent(int n1) {
	if (n1 != parent[n1]) {
		return parent[n1] = findParent(parent[n1]);
	}
	else {
		return n1;
	}
}
void mergeParent(int n1, int n2) { // n1<n2��� ����
	n1 = findParent(n1);
	n2 = findParent(n2);
	if (n1 != n2) {	
		parent[n2] = n1;
	}
}
void prt() {
	for (int i = 1; i <= n; i++) {
		cout << parent[i]<<' ';
	}
	cout << endl;
}
int main() {
	ios::sync_with_stdio(false);  cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}
	for (int i = 1; i <= m; i++) {
		cin >> n1 >> n2 >> cost;
		graph.push_back({cost,{n1,n2}});
	}
	sort(graph.begin(), graph.end()); // �ּ� ����� ���ϱ� ���� ����
	int cnt = 0;
	for (int i = 0; i < graph.size(); i++) {
		int cur_cost = graph[i].first;
		int home1 = min(graph[i].second.first, graph[i].second.second);
		int home2 = max(graph[i].second.first, graph[i].second.second);
		if (findParent(home1) != findParent(home2)) { // �̰� �־�� �ð��ʰ��� �ȳ���.
			mergeParent(home1, home2);
			result += cur_cost;
			cnt++;
		}
		if (cnt == n - 2) { break; }
	}
	cout << result;
}