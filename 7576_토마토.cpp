#include<iostream>
#include<vector>
#include<queue>
using namespace std;
/*
	�丶�䰡 ��� ���� �������� �ּ� ��¥�� ����ؾ� �Ѵ�. 
	����, ����� ������ ��� �丶�䰡 �;��ִ� �����̸� 0�� ����ؾ� �ϰ�, 
	�丶�䰡 ��� ������ ���ϴ� ��Ȳ�̸� -1�� ����ؾ� �Ѵ�.
*/
struct Point {
	int x;
	int y;
	int apple;
};
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
vector<Point>v(1001);
queue<Point>q;
void bfs() {
	
}

int main() {
	int M, N; 
	cin >> M >> N;
	int day = 0;
	int n;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> n;
			v[i].x= j;
			v[i].y = i;
			v[i].apple = n;
			if (n == 1) {
				q.push(v[i]); // ���� �丶���� ��ġ�� �������
			}
		}
	}
	bfs();
}