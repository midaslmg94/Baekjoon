#include<iostream>
#include<string.h>
#include<queue>
#include<algorithm>
using namespace std;
/*
	높이 : F층
	현위치:S층
	목적지:G층
	U버튼 : 위로 U층 가는 버튼
	D버튼 : 아래로 D층을 가는 버튼

*/
int f, s, g, u, d;
int button[1'000'001]; // 해당 지점까지 가는데 누른 버튼의 개수
void bfs(int start) {
	queue<int>q;
	q.push(start);
		button[start] = 0;
	while (!q.empty()) {
		start = q.front();
		q.pop();
		int next_up = start + u;
		int next_down = start - d;
		// 위로 가는 경우
		if (next_up <= f && button[next_up] == -1) {
			button[next_up] = button[start] + 1;
			q.push(next_up);
		}
		//	아래로 가는 경우
		if (next_down >= 1 && button[next_down] == -1) {
			button[next_down] = button[start] + 1;
			q.push(next_down);
		}
	}
	if (button[g] == -1) {
		cout << "use the stairs";
		return;
	}
	cout << button[g];
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);

	cin >> f >> s >> g >> u >> d;
	memset(button, -1, sizeof(button));
	bfs(s);
}