#include<iostream>
#include<algorithm>
#include<queue>
#define MAX 100
using namespace std;
int map[MAX][MAX];
int rand[MAX][MAX]; // ���ΰ� �������� Ȯ��
int N;
int L;//����
int ans;
void make_land(int x, int y, int slide) {
	// ���θ� �ڷ� ��ġ�Ҳ��� ������ ��ġ�Ҳ��� Ȯ��
	int dist = 1;
	queue<pair<int, int>>q;
	if (slide) { // ��������

	}
	else { // ��������
		q.push({ x, y+1});
		for (int j = y + 1; j < N - 1; j++) {
			if (map[x][j] == map[x][j + 1]) {
				dist++;
				q.push({ x,j+1});
				if (dist == L) { // ���� ��ġ����

				}
			}
			else {
				break;
			}
		}
	}

}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);
	cin >> N >> L;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	//���� Ȯ��
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N - 1; j++) {
			if (map[i][j] > map[i][j + 1]) { // ������
				make_land(i, j, 0);
				break;
			}
			if (map[i][j] < map[i][j + 1]) { // ������
				make_land(i, j, 1);
				break;
			}
		}
		ans++; // ���� ���� ���̷� �� �̾��� �ִٴ� ��
	}




	//���� Ȯ��
	for (int j = 0; j < N; j++) {
		for (int i = 0; i < N - 1; i++) {

		}
	}

	cout << ans;
}