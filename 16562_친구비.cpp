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
int student[MAX];// i��° ģ���� ��ʹµ� ��� ���(ģ�� ���� ���� ��)
int cost[MAX]; // i��° ģ���� ��ʹµ� ��� ���(ģ�� ���� ���� ��)
int total = 0; // ��� ģ���� ��ʹµ� ��� �� ���
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
			if (parent[cur] != parent[next]) { // �θ� �ٸ� ��� 
				unionParent(cur, next); // �θ� ��ħ
			}
		}
	}
	
	for (int i = 1; i <= n; i++) {	 
		int cur = findParent(parent[i]); // ���⼭ ������ �߻� --> int cur = parent[i];�� �߾���
		cost[cur] = min(cost[cur], student[i]); // �θ� cur�� �л��� ��� ��, �ּҸ� ã��
	}
	for (int i = 1; i <= n; i++) {
		if (cost[i] <= 10000) { // cost[i]>10000�� �θ� �ٸ� ���� ��
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