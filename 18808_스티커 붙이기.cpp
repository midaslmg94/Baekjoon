#include<bits/stdc++.h>
#define endl "\n"
#define MAX 40
using namespace std;
int n, m, k;
int map[MAX][MAX];
bool visit[MAX][MAX];
int sticky[10][10];
int r, c; // ��ƼĿ�� ���� ���α���

void rotate() { // 90�� ȸ�� --> �� �κ��� ���İ����� ���� �� ������..
	// ���� ������ ���̰� ���� �ٲ��
	int sticky_rotate[10][10];
	memcpy(sticky_rotate, sticky, sizeof(sticky));
	for(int )

}
bool canAttach() { // ��ƼĿ�� ���� �� �ִ��� Ȯ��

}
void attach() {
	// �»�ܺ��� ��ƼĿ�� �� ��ġ Ȯ��

}
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);
	cin >> n >> m >> k;
	while(k--) {
		cin >> r >> c;
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				cin >> sticky[i][j];
			}
		}
		attach();
	}





	int answer = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 1)
				answer++;
		}
	}
	cout << answer;
	return 0;
}