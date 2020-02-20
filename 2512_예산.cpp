#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string.h>
#define endl "\n"
#define MAX 10000
using namespace std;
int n;
int budget;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);
	cin >> n;

	vector<int>v;
	for (int i = 0; i < n; i++) {
		int tmp; cin >> tmp;
		v.push_back(tmp);
	}
	sort(v.begin(), v.end());
	cin >> budget;

	int left = 0; // �ּ� ��û����
	int right = v[n - 1];  // �ִ� ��û����
	int money = 0;
	while (left <= right) {
		money = 0; // ���Ѿ׿� �°� ������ ������ ����		
		int mid = (left + right) / 2; // ���Ѿ�

		// ���� ��û�� �°� �����ֱ�
		for (int i = 0; i < n; i++) {
			if (v[i] < mid) { // ��û ������ ���Ѿ� �̸� -> ��û���� ��ŭ ��
				money += v[i];
			}
			else { // ��û ������ ���Ѿ� �̻�-> ���Ѿ� ��ŭ ��
				money += mid;
			}
		}

		if (money > budget) { // ��������� ���� �� ���꺸�� �����Ƿ� ���Ѿ��� �������
			right = mid - 1;
		}
		else { // ���Ѿ��� ������ �ȴ�.
			left = mid + 1;
		}
	}
	cout << right;

}
