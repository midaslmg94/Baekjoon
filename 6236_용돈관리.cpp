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
	int right = 0; // 최대 금액
	int cur_money = 0;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		right = max(arr[i], right);
	}
	/* 정확히 M번을 맞추기 위해서 남은 금액이 그날 사용할 금액보다 많더라도
	남은 금액은 통장에 집어넣고 다시 K원을 인출할 수 있다. */
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
		if (cnt < m) { // 꺼낸 횟수가 더 적으면 --> 꺼낼 금액을 줄임
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
	cout << left;
	return 0;
}