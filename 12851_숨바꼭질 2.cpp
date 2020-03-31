#include<bits/stdc++.h>
#define endl "\n"
#define MAX 100000+1
using namespace std;
int arr[MAX];
int answer[MAX]; // n�ʿ� ã�� ����� ��
int moving[3] = { -1,1,0 }; // �ڷΰ���, �����ΰ���, �����̵�
int n, k;

void bfs() {
	queue<pair<int, int>>q;
	q.push({ n,0 }); // ���� ��ġ, �ð�
	arr[n] = 0;
	while (!q.empty()) {
		int cur_pos = q.front().first;
		int cur_time = q.front().second;
		q.pop();
		arr[cur_pos] = cur_time;
		if (cur_pos == k) {
			answer[cur_time] += 1;
		}
		moving[2] = cur_pos; // �����̵�
		for (int i = 0; i < 3; i++) {
			int next_pos = cur_pos + moving[i];
			int next_time = cur_time + 1;
			if (next_pos<0 || next_pos>MAX)continue; // ���� �ʰ�
			if (arr[next_pos] == 0) {
				q.push({ next_pos, next_time });
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);
	cin >> n >> k;
	bfs();
	for (int i = 0; i < MAX; i++) {
		if (answer[i] != 0) { // ���� ���� �ð��� ���
			cout << i << endl;
			cout << answer[i];
			return 0;
		}
	}
}