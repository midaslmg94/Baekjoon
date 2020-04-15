#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>
using namespace std;
int N, S;
int main() {
	cin >> N >> S;
	vector<int>v(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end()); // ������ ���û���
	int cnt = 0;
	vector<int>choice(N);
	for (int i = N-1; i >=0; i--) {// �� �κ��� �߿�. 0, 0 �տ� ��
		choice[i] = 1;
		do{
			int sum = 0;
			for (int j = 0; j < N; j++) {
				if (choice[j] == 1) {// N�� �� 1�� �̴� ���, 2�� �̴� ��� ... N�� �̴� ����� ����
					sum += v[j];
				}
			}
			if (sum == S) {
				cnt++;
			}
		} while (next_permutation(choice.begin(), choice.end()));
	}
	cout << cnt;
}