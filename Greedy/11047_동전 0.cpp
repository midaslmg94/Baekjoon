#include<iostream>
using namespace std;

int coin[10];
int main() {
	int n, k;
	cin >> n >> k;
	for (int i = n-1; i >=0; i--) {
		cin >> coin[i]; // ������������ �Է¹���
	}
	int cur_coin = 0; // ���� ����� ����
	int use_coin = 0; // �� ����� ������ ����
	while (k) {
		for (int i = 0; i < n; i++) {
			cur_coin = coin[i];
			if (cur_coin > k) continue; // ��밡���� ������ �� ũ�� �ѱ�
			use_coin += k / cur_coin;
			k = k % cur_coin;

		}
	}
	cout << use_coin;

}