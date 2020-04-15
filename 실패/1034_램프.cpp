#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<deque>
#include<string.h>
#define endl "\n"
#define MAX 50
using namespace std;
int n, m;
int k;
int lamp[MAX][MAX];
int backup[MAX][MAX];
int dp[MAX];
bool visited[MAX];
vector<int>candi;
int answer = -1;
void prt() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << backup[i][j] << ' ';
		}
		cout << endl;
	}
	cout << endl << endl;
}
void changeLamp() { // ����ġ�� ������ ������ on/off ���¸� �ٲ�
	memcpy(backup, lamp, sizeof(backup));
	for (int i = 0; i < candi.size(); i++) {
		int row = candi[i];
		for (int j = 0; j < n; j++) {
			if (backup[j][row] == 0) {
				backup[j][row] = 1;
			}
			else {
				backup[j][row] = 0;
			}
		}
	}
}
int calc() { // ���� �ִ� ���� ������ ����
	int result = 0;
	for (int i = 0; i < n; i++) {
		bool flag=true;
		for (int j = 0; j < m; j++) {
			if (backup[i][j]==0) { // �ϳ��� �����ִٸ� �ش� ���� �������� ���� ��
				flag = false;
				break;
			}
		}
		if(flag==true)
			result++;
	}
	return result;
}

void func() { // ����ġ�� ���� ���� ��

}
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < m; j++) {
			if (str[j] == '0') {
				lamp[i][j] = 0;
			}
			else {
				lamp[i][j] = 1;
			}
		}		
	}
	cin >> k; // 0<= k <=1000
	if (k > 50) k = 50;	
	func();
	cout << answer;
	return 0;
}