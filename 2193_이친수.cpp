#include<iostream>
using namespace std;
/*
	�Ǻ���ġ Ȱ��
*/

int n;
long long pinary[91]; // 90��° �Ǻ���ġ�� int ������ �Ѿ
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);
	cin >> n;
	pinary[1] = 1;
	pinary[2] = 1;
	for (int i = 3; i <= n; i++) {
		pinary[i] = pinary[i - 1] + pinary[i - 2];
	}
	cout << pinary[n];

}