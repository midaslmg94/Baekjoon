#include<iostream>
#include<vector>
#include<queue>
using namespace std;
/*
	���� 1�� ���� �丶��, 
	���� 0�� ���� ���� �丶��,
	���� -1�� �丶�䰡 ������� ���� ĭ

	�丶�䰡 ��� ���� �������� �ּ� ��¥�� ����ؾ� �Ѵ�. 
	����, ����� ������ ��� �丶�䰡 �;��ִ� �����̸� 0�� ����ؾ� �ϰ�, 
	�丶�䰡 ��� ������ ���ϴ� ��Ȳ�̸� -1�� ����ؾ� �Ѵ�.
*/

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int tomato[1000][1000];
queue<pair<int, int>>q;


int main() {
	int M, N; 
	int total = 0; // �丶�䰡 �ִ� ĭ�� �丶�䰡 ���� ĭ�� ���� Ȯ�����ֱ� ����
	cin >> M >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> tomato[i][j];
			//d[i][j] = -1;
			if (tomato[i][j] == 1) { 
				q.push({i, j}); 
			}
			else if (tomato[i][j] == -1) { // �丶�䰡 ����
				total++;
			}
		}
	}
	int size = 0;
	int day = 0;

	while (!q.empty()) {
		size = q.size(); // ���� �丶���� ����
		total += size; // �丶�䰡 ���� ĭ + ���� �丶�䰡 �ִ� ĭ

		if (total == N * M) { //�丶�䰡 ���� ĭ + ���� �丶�䰡 �ִ� ĭ�� ���� ��ü â���� ũ��� ������ ��
			cout << day;
			break;
		}
		for (int i = 0; i < size; i++) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			for (int j = 0; j < 4; j++) {
				int nx = x + dx[j];
				int ny = y + dy[j];
				if (0 <= nx && nx < N && 0 <= ny && ny < M) {
					if (tomato[nx][ny] == 0) { // �ֺ��� ���� ���� �丶����
						tomato[nx][ny] = 1;
						q.push({ nx, ny });
					}
				}
			}
		}
		day++;
	}
	if (total != N * M) {
		cout << -1;
	}
	return 0;
}