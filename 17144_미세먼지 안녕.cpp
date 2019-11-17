#include<iostream>
#include<string.h>
#include<vector>
#include<queue>
using namespace std;
int r, c, t;
int map[50][50];
int tmp[50][50];
int dx[4] = { 0,-1,0,1 };
int dy[4] = { -1,0,1,0 };
queue<pair<int, int>>q;
int cango(int x, int y) {// Ȯ�� ������ ������ �����
	int cnt = 0;
	for (int k = 0; k < 4; k++) {
		int nx = x + dx[k];
		int ny = y + dy[k];
		if (0 <= nx && nx < r && 0 <= ny && ny < c && map[nx][ny] != -1) {
			cnt++;
		}
	}
	return cnt;
} 

void spread() { //�̼����� Ȯ��	
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (map[i][j] != -1) {
				int cnt = cango(i, j);
				int dust = map[i][j] / 5; //Ȯ��Ǵ� ������
				int rest = map[i][j] - (dust * cnt); //Ȯ���� ���� ������
				for (int k = 0; k < 4; k++) {
					int nx = i + dx[k];
					int ny = j + dy[k];
					if (0 <= nx && nx < r && 0 <= ny && ny < c && map[nx][ny] != -1) {
						tmp[nx][ny] += dust;
					}
				}
				map[i][j] = rest;
			}
		}
	}
	/*cout << endl<<"����������" << endl;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << map[i][j] << ' ';
		}
		cout << endl;
	}
	cout << endl <<"Ȯ��� ������"<< endl;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << tmp[i][j] << ' ';
		}
		cout << endl;
	}


	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			map[i][j] += tmp[i][j];
		}
	}
	cout  <<endl <<"������ ������"<< endl;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << map[i][j] << ' ';
		}
		cout << endl;
	}*/
}
void move(queue<pair<int, int>>q) {//����û���� ���� �� �̼����� �̵�
	int x1 = q.front().first;
	int y1 = q.front().second;
	q.pop();
	int x2 = q.front().first;
	int y2 = q.front().second;
	// ���κ�
	for (int i = x1; i < r; i++) {

	}
	// �Ʒ��κ� 
}

int main() {
	int n = 0;
	cin >> r >> c >> t;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> n;
			map[i][j] = n;
			if (n == -1) {
				q.push(make_pair(i, j));
			}
		}
	}
	spread();
	move(q);

	for (int i = 0; i < t; i++) {
		memset(tmp, 0, sizeof(tmp));
		spread();
		memset(tmp, 0, sizeof(tmp));	//  fill(&tmp[0][0],&tmp[49][50],5); �̰� 0�� �ƴ� ������ �ʱ�ȭ �Ҷ� ��
		move(q);
	}
	int ans = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (map[i][j] != -1)
				ans += map[i][j];
		}
	}
	cout << "\n" << ans;
}