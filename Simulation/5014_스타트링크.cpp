#include<iostream>
#include<string.h>
#include<queue>
#include<algorithm>
using namespace std;
/*
	���� : F��
	����ġ:S��
	������:G��
	U��ư : ���� U�� ���� ��ư
	D��ư : �Ʒ��� D���� ���� ��ư

*/
int f, s, g, u, d;
int button[1'000'001]; // �ش� �������� ���µ� ���� ��ư�� ����
void bfs(int start) {
	queue<int>q;
	q.push(start);
		button[start] = 0;
	while (!q.empty()) {
		start = q.front();
		q.pop();
		int next_up = start + u;
		int next_down = start - d;
		// ���� ���� ���
		if (next_up <= f && button[next_up] == -1) {
			button[next_up] = button[start] + 1;
			q.push(next_up);
		}
		//	�Ʒ��� ���� ���
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