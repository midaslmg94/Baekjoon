#include<iostream>
#include<algorithm>
#include<vector>
#include<string.h>
#define endl "\n"
#define MAX 10000+1

using namespace std;
int n, m, money;
vector<int>v[MAX];
int parent[MAX];
int student[MAX];// i번째 친구를 사귀는데 드는 비용(친구 관계 연결 전)
int cost[MAX]; // i번째 친구를 사귀는데 드는 비용(친구 관계 연결 후)
int total = 0; // 모든 친구를 사귀는데 드는 총 비용
int findParent(int n1) {
	if (n1 != parent[n1]) {
		return parent[n1] = findParent(parent[n1]);
	}
	else {
		return n1;
	}
}
void unionParent(int n1, int n2) {
	n1 = findParent(n1);
	n2 = findParent(n2);	
	if (n1 != n2) {
		if (n1 < n2) {
			parent[n2] = n1;
		}
		else {
			parent[n1] = n2;
		}
	}
	return;
}


int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);
	cin >> n >> m >> money;
	for (int i = 1; i <= n; i++) {
		cin >> student[i];
		parent[i] = i;
		cost[i] = MAX; 
 	}
	int a; int b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}	

	for (int i = 1; i <= n; i++) {
		int cur = i;
		for (int j = 0; j < v[i].size(); j++) {
			int next = v[i][j];
			if (parent[cur] != parent[next]) { // 부모가 다를 경우 
				unionParent(cur, next); // 부모를 합침
			}
		}
	}
	
	for (int i = 1; i <= n; i++) {	 
		int cur = findParent(parent[i]); // 여기서 문제가 발생 --> int cur = parent[i];로 했었음
		cost[cur] = min(cost[cur], student[i]); // 부모가 cur인 학생의 비용 중, 최소를 찾음
	}
	for (int i = 1; i <= n; i++) {
		if (cost[i] <= 10000) { // cost[i]>10000은 부모가 다른 값인 것
			total += cost[i];
		}
	}

	if (money >= total) {
		cout << total;
	}
	else { 
		cout << "Oh no";
	}
	return 0;
}