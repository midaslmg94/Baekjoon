#include <bits/stdc++.h>
#define endl "\n"
#define MAX 50
#define pii pair<int,int>
using namespace std;
struct GROUND {//���� ����
	int state; // 0:ȣ��, 1:������ �Ѹ��� ����, 2:������ �Ѹ� �� ����
	int red; // ������ ������ �ѷ��� ����
	int green; // �ʷϻ� ������ �ѷ��� ����
	bool flower; // ���� �Ǿ���� Ȯ��
};
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
int n, m, g, r;
GROUND ground[MAX][MAX];
vector<pii>candi_space; // ���� ���� �� �ִ� ��(�ִ� 10��)
int answer = -1;


int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);
	
	cin >> n >> m >> g >> r;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> ground[i][j].state;
			ground[i][j].red = -1;
			ground[i][j].green = -1;
			ground[i][j].flower = false;
			if (ground[i][j].state == 2) {
				candi_space.push_back({ i,j });
			}
		}
	}
	

	cout << answer;
	return 0;
}