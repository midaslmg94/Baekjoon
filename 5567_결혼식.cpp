#include<iostream>
#include<queue>
#define MAX 500+1
using namespace std;
int n, m;
int friends[MAX][MAX];
bool friendsList[MAX]; // ������� ģ���� Ȯ��
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);	cout.tie();
	freopen("input.txt", "r", stdin);
	cin >> n >> m;
	int n1;
	int n2;
	for (int i = 0; i < m; i++) {
		cin >> n1 >> n2;
		friends[n1][n2] = 1;
		friends[n2][n1] = 1;
	}
	queue<int>q;
	int num = 0; 
	for (int i = 1; i <= n; i++) {
		if (friends[1][i] == 1) {// ������� �������� ģ����
			q.push(i);
			friendsList[i] = true;
			num++;
		}
	}
	while (!q.empty()) { // ������� �������� ģ����
		int y = q.front(); 
		q.pop();
		for (int x = 2; x <= n; x++) { // ����̴� ����, ����̿� �������� ģ���鵵 ����
			if (friends[y][x] == 1 && friendsList[x]!=1) {
				friendsList[x] = true;
				num++;
			}
		}
	}
	cout << num;
}