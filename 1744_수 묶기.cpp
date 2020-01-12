#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n;
vector<int>pos; // ��� �迭
vector<int>neg; // ���� �迭 
long long sum; // ��
bool is_zero = false; // 0�� �ִ���
bool is_one = false; // 1�� �ִ���
int p_size, n_size;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("input.txt", "r", stdin);
	cin >> n;

	for (int i = 0; i < n; i++) {
		int tmp; cin >> tmp;
		if (tmp > 0) {
			if (tmp == 1) {
				is_one = true;
				sum += 1; 
			}
			else { pos.push_back(tmp); }
		}
		else {
			if (tmp == 0) {
				is_zero = true;
			}
			neg.push_back(tmp);
		}
	}
	/*
		- ���ڰ� 0�� �� :
			- 0 1 �� ���, 0+1>0*1
			- -1 0 �� ���. -1+0 <-1*0
		- ���ڰ� 1�� ��
			- 1 2 �� ���, 1+2>1*2

		- ������ Ȧ���� �϶�
			- ���� ū ������ ���� �ϰ� 2���� ����
		- ������ ¦���� �϶�
			- 2���� ���� ����
	*/
	sort(pos.begin(), pos.end(), greater<int>());
	sort(neg.begin(), neg.end());

	// 1ó��
	/*if(pos.size() >= 1 && pos[pos.size() - 1] == 1) { // 1�� ����
		if (pos.size() % 2 == 0) { // ¦������ 1�� ���ϱ⿬���� �ؾ���. 1 1 1 1 1 �� ���?
			sum += pos[pos.size() - 1];
			pos.pop_back();			
		}
	}*/
	// ��� ���ϱ�
	if (pos.size()) {
		for (int i = 0; i < pos.size() - 1; i+=2) {
			sum += (pos[i] * pos[i + 1]);
		}
		if (pos.size() % 2 != 0) { // Ȧ������ ������ 1���� ����
			sum += pos[pos.size() - 1];
		}
	}

	// 0 ó��
	if (neg.size() >= 1 && neg[neg.size() - 1] == 0) {
		if (neg.size() % 2 != 0) { // Ȧ������ 0�� ����������
			neg.pop_back();
		}
	}
	// ���� ���ϱ�
	if (neg.size()) {
		for (int i = 0; i < neg.size() - 1; i+=2) {
			sum += (neg[i] * neg[i + 1]);
		}
		if (neg.size() % 2 != 0) { // Ȧ������ ������ 1���� ����
			sum += neg[neg.size() - 1];
		}
	}
	cout << sum;
}