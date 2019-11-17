#include<iostream>
#include<vector>
const int MAX = 1000001;
using namespace std;
vector<pair<int, int>>v(MAX);
  
// i�� �κ����� ���ϴ� �Լ�
int func(int i) {
	int res = i;
	while (i > 0)
	{
		res = res + i % 10;
		i = i / 10;
	}
	return res;
}

int main() {
	bool flag = false; // �κ����� ���� �Ǵ�
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		v[i].first = i; // �ڿ��� i
		v[i].second = func(i); // �ڿ��� i�� �κ���
	}
	for (int i = 1; i < n; i++) {
		if (v[i].second == n) {
			cout << v[i].first;
			flag = true;
			return 0;
		}
	}
	// �κ����� ���� ��� 0�� ���
	if (flag == false) {
		cout << 0;
	}
}