#include<iostream>
#include<vector>
using namespace std;
vector<pair<int, int>>v;

void hanoi(int n, int from, int by, int to) {
	if (n == 1) { // base  case
		v.push_back({ from, to });
	}
	else {
		hanoi(n - 1, from, to, by); // �������� �ƴ� ������ �̵�
		v.push_back({ from, to });
		hanoi(n - 1, by, from, to); // �ٸ� ������ �Ű�� ������ �� ���� ����
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);  cout.tie(0);
	int n;
	cin >> n;
	/*
	int cnt = 1;
	while (--n) {
		cnt = cnt * 2 + 1;
	}
	cout << cnt; // �����̴� Ƚ���� ��ȭ������ ���� �� �ִ�. An = 2*An-1 +1
	*/
	hanoi(n, 1, 2, 3);
	cout << v.size()<<endl;
	for (int i = 0; i < v.size(); i++) {
		cout << v[i].first << ' ' << v[i].second << endl;
	}
}