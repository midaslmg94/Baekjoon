#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
/* 
	�̺� Ž�� - �Ķ��Ʈ�� ��ġ
*/
int n, c;
vector<int>home;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);

	cin >> n >> c; // ���ǰ���, �������� ����
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		home.push_back(tmp);
	}
	sort(home.begin(), home.end());





}