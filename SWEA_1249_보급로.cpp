#include<iostream>
#include<queue>
#include<vector>
#include<string.h>
#include<algorithm>
using namespace std;
int arr[100][100];
int d[100][100];
int dy[4] = { 0,0,-1,1 };
int dx[4] = { 1,-1,0,0 };
int n;

void dijkstra() {
	memset(d, -1, sizeof(d));
	priority_queue<pair<int, pair<int, int>>>pq; // cost, ���1, ���2
	// cost�� ���� ������ �ּ� ���� �����ؾ��ϱ� ������, first�� cost�� ���´�
	pq.push({ 0,{0,0} }); // ���������� 0,0
	while (!pq.empty()) {
		int cost = -pq.top().first;
		int y = pq.top().second.first;
		int x = pq.top().second.second;
		pq.pop();
		if (d[y][x] == -1)
			d[y][x] = cost;
		for (int k = 0; k < 4; k++) {
			int ny = y + dy[k];
			int nx = x + dx[k];
			if (0 > nx || nx >= n || 0 > ny || ny >= n)continue;
			int ncost = -cost - arr[ny][nx];
			if (d[ny][nx] == -1)
				pq.push({ ncost,{ny,nx} });
		}
	}
}
int main() {
	/*ios::sync_with_stdio(false);
	cin.tie(0);	cout.tie();*/
	freopen("input.txt", "r", stdin);
	int t=1;
	int c;
	cin >> c;
	while (t<=c) {	
		cin >> n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				scanf("%1d", &arr[i][j]); // �Է��� ���� ���� 01102 ó�� ���ö� ��
			}
		}
		dijkstra();
		cout << "#" << t << ' '<<d[n-1][n-1]<< "\n";
		t++;
	}

}