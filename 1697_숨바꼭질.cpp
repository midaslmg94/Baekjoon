#include<iostream>
#include<queue>
#include<string.h>
#define MAX 100'001
using namespace std;
int n, k;
bool visit[MAX];
int time;
/*
	- �ڷ� 1ĭ
	- ������ 1ĭ
	- ������ 2��
	--> �� ���Ǻ��� ť�� ���� �ְ� �ɰ��°� �߿�
*/
int bfs(int n, int k) {
	queue<pair<int, int>>q; // ��ġ, �ð� ����
	q.push({ n, 0 });
	visit[n] = true;

	while (!q.empty())
	{
		int pos = q.front().first;
		int time = q.front().second;
		q.pop();

		if (pos == k)
			return time;

		if (pos + 1 < MAX && !visit[pos + 1]) {
			q.push({ pos + 1, time + 1 });
			visit[pos + 1] = true;
		}
		if (pos - 1 >=0 && !visit[pos - 1]) {
			q.push({ pos - 1, time + 1 });
			visit[pos - 1] = true;
		}
		if (pos * 2 < MAX && !visit[pos * 2]) {
			q.push({ pos *2, time + 1 });
			visit[pos*2] = true;
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);	cout.tie();
	freopen("input.txt", "r", stdin);
	cin >> n >> k;
	cout<<bfs(n, k);
}