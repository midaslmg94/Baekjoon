#include<iostream>
#include<algorithm>
#include<string.h>
#define endl "\n"
#define MAX 100000
using namespace std;
int n, m;
int arr[MAX];
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);
	cin >> n >> m;
	int left = 0;
	int right = 0; // �ִ� �ݾ�
	int cur_money = 0;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		right = max(arr[i], right);
	}
	/* ��Ȯ�� M���� ���߱� ���ؼ� ���� �ݾ��� �׳� ����� �ݾ׺��� ������
	���� �ݾ��� ���忡 ����ְ� �ٽ� K���� ������ �� �ִ�. */
	while (left <= right) {
		int mid = (left + right) / 2;
		int cnt = 0;
		cur_money = 0;
		for (int i = 0; i < n; i++) {
			if (cur_money < arr[i]) {
				cur_money = mid;
				cnt++;
			}
			else {
				cur_money -= arr[i];
			}
		}
		if (cnt < m) { // ���� Ƚ���� �� ������ --> ���� �ݾ��� ����
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
	cout << left;
	return 0;
}