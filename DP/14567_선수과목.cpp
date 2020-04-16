#include<iostream>
#include<algorithm>
#include<vector>
#define MAX 1000+1
#define endl "\n"
using namespace std;
int n, m;
int course[MAX][MAX];
int indegree[MAX];
int semester[MAX];

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);
	cin >> n >> m;	
	int prev= 0;
	int next = 0;
	
	for (int i = 0; i < m; i++) {
		cin >> prev >> next;
		course[next][prev] = 1;
		indegree[next]++;
	}
	for (int i = 1; i <= n; i++) {
		if (indegree[i] == 0) { // ���������� ���� : 1�б⸸�� ���� ����
			semester[i] = 1;
			continue;
		}
		for (int j = 1; j <= n; j++) {
			if (course[i][j]==1) { // i�� ������ ��� ���� j�� ������ �����ؾ� ��
				int preSemester = semester[j]; // j�� ������ �����ϴµ� �ʿ��� �б� ��
				semester[i] = max(semester[i], preSemester+1);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		cout << semester[i] << ' ';
	}

	return 0;
}