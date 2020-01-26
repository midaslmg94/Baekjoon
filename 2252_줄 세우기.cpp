#include<iostream>
#include<queue>
#include<vector>
#define MAX 32001
using namespace std;

int n, m;
vector<int>adj[MAX]; // ���� ����
int indegree[MAX]; // indegree ����

void topo_sort() { // ��������
	int result[MAX];
	queue<int>q;
	// ���������� 0�� ��带 ť�� ����
	for (int i = 1; i <= n; i++) {
		if (indegree[i] == 0) {
			q.push(i);
		}
	}
	//���������� ������ ����Ƿ��� n���� ���湮
	for (int i = 1; i <= n; i++) {
		if (q.empty()) {
			cout << "����Ŭ�� �߻�";
			return;
		}
		int x = q.front();
		q.pop();
		result[i] = x; // ���������� �ϼ��� �迭
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