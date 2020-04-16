#include<iostream>
#include<algorithm>
#include<string.h>
#include<queue>
using namespace std;
int map[20][20];
int n, m, x, y, k;
/*
	dice[0] = �Ⱦ� (����)
	dice[1] = ����
	dice[2] = �޸�
	dice[3] = ���ʸ�
	dice[4] = �����ʸ�
	dice[5] = ����
	dice[6] = �Ʒ��� (�عٴ�)
*/
int dice[7] = { -99, 0, 0, 0, 0, 0, 0 };

void rollDice(int order, int nx, int ny) {
	if (order == 1) { // �������� �̵� : ����, �޸� ����
		swap(dice[3], dice[6]);
		swap(dice[4], dice[5]);
		swap(dice[5], dice[6]);
	}
	else if (order == 2) { //�������� �̵� : ����, �޸� ���� 
		swap(dice[3], dice[5]);
		swap(dice[4], dice[6]);
		swap(dice[5], dice[6]);
	}
	else if (order == 3) {//�������� �̵� : ���ʸ�, �����ʸ� ����
		swap(dice[1], dice[6]);
		swap(dice[2], dice[5]);
		swap(dice[5], dice[6]);
	}
	else if (order == 4) {//�������� �̵� : ���ʸ�, �����ʸ� ����
		swap(dice[1], dice[5]);
		swap(dice[2], dice[6]);
		swap(dice[5], dice[6]);
	}
}

bool canGo(int order, int nx, int ny) {	
	if (order == 1) { // �������� �̵�����? ny�� 1����	
		if (ny+1>=m ) {
			return false;
		}
	}
	else if (order == 2) { // �������� �̵�����? ny�� 1����		
		if (ny-1<0 ) {			
			return false;
		}
	}
	else if (order == 3) { // �������� �̵�����? nx�� 1����		
		if (nx-1<0 ) {			
			return false;
		}
	}
	else if (order == 4) {  // �������� �̵�����? nx�� 1����	
		if (nx+1>=n ) {
			return false;
		}
	}
	return true;
}

int main() {	
	ios::sync_with_stdio(false);
	cin.tie(NULL);	cout.tie(NULL);
	cin >> n >> m >> x >> y >> k; 
	for (int i = 0; i < n; i++) { // x�� ����
		for (int j = 0; j < m; j++) { // y�� ����
			cin >> map[i][j];
		}
	}
	queue<int>q; // ���
	for (int i = 0; i < k; i++) {
		int tmp; cin >> tmp;
		q.push(tmp);
	} 

	// ���� �ֻ����� ��ġ
	int nx = x; int ny = y;	
	while (!q.empty()) {
		int order = q.front();
		q.pop();
		if (!canGo(order, nx, ny)) { // �ٱ����� �̵��ϴ� ��� ��� ����.��� X
			continue;
		}		
		if (order == 1) { // �������� �̵�, ny�� 1����,
			++ny;			
		}
		else if (order == 2) { // �������� �̵�, ny�� 1����,
			--ny;
		}
		else if (order == 3) { // �������� �̵�, nx�� 1����,
			--nx;
		}
		else if (order == 4) {  // �������� �̵�, nx�� 1����,
			++nx;
		}
		int num = map[nx][ny]; // �̵��ϴ� ��ġ�� ������ ����
		rollDice(order, nx, ny);
		if (num == 0) { //�̵��� ĭ�� ���� �ִ� ���� 0�̸�, �ֻ����� �ٴڸ鿡 ���� �ִ� ���� ĭ�� ����ȴ�. �ٴڸ� : dice[6]
			map[nx][ny] = dice[6];  // ���⼭ num = dice[6] �̶�� �Ǽ���
		}
		else { //0�� �ƴ� ��쿡�� ĭ�� ���� �ִ� ���� �ֻ����� �ٴڸ����� ����Ǹ�, ĭ�� ���� �ִ� ���� 0�� �ȴ�.
			dice[6] = num;
			map[nx][ny] = 0;
		}
		cout << dice[5]<<endl; // �ֻ����� �� ���� ���
	}
}