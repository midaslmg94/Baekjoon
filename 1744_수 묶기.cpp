#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n;
vector<int>pos; // ��� �迭
vector<int>neg; // ���� �迭 
long long sum; // ��
bool is_zero = false; // 0�� �ִ��� Ȯ��
bool is_odd = false;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int tmp; cin >> tmp;
		if (tmp > 0) {
			pos.push_back(tmp);
		}
		else if (tmp == 0) {
			is_zero = true;
		}
		else {
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
}