#include<bits/stdc++.h>
#define endl "\n"
#define MAX 100000+1
using namespace std;
int arr[MAX];
int answer[MAX]; // n초에 찾는 경우의 수
int moving[3] = { -1,1,0 }; // 뒤로가기, 앞으로가기, 순간이동
int n, k;

void bfs() {
	queue<pair<int, int>>q;
	q.push({ n,0 }); // 현재 위치, 시간
	arr[n] = 0;
	while (!q.empty()) {
		int cur_pos = q.front().first;
		int cur_time = q.front().second;
		q.pop();
		arr[cur_pos] = cur_time;
		if (cur_pos == k) {
			answer[cur_time] += 1;
		}
		moving[2] = cur_pos; // 순간이동
		for (int i = 0; i < 3; i++) {
			int next_pos = cur_pos + moving[i];
			int next_time = cur_time + 1;
			if (next_pos<0 || next_pos>MAX)continue; // 범위 초과
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
		if (answer[i] != 0) { // 가장 빠른 시간을 출력
			cout << i << endl;
			cout << answer[i];
			return 0;
		}
	}
}