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
int p_size ,n_size;
void sum_pos() {
	p_size = pos.size();
	if (p_size%2) { // Ȧ����
		if (is_one) { // 1�� �ִ��� Ȯ��
			for (int i = 0; i < p_size; i += 2) {
				sum += (pos[i] * pos[i + 1]);
			}
		}
		else {

		}
	}
	else {// ¦����
		if (is_one) {// 0�� �ִ��� Ȯ�� 

		}
		else {

		}
	}

}

void sum_neg() {
	n_size = neg.size();
	if ( n_size % 2) { // Ȧ����

	}
	else {// ¦����

	}
}

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
			}
			pos.push_back(tmp);
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

	   

	sum_neg();
	sum_pos();
	cout << sum << endl;
}