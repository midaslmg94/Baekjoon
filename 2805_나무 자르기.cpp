#include<bits/stdc++.h>
#define endl "\n"
#define MAX 1000000
#define ll long long 
using namespace std;
int n, m;
int tree[MAX];
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);
	cin >> n >> m;
	int left = 0;
	int right = 0;
	for (int i = 0; i < n; i++) {
		cin >> tree[i];
		right = max(right, tree[i]);
	}
	ll answer = 0;
	while (left <= right) {
		int mid = (left + right) / 2; // ���ܱ��� ����
		ll res = 0;
		for (int i = 0; i < n; i++) {
			if (tree[i] > mid) {
				res += tree[i] - mid;
			}
		}
		if (res>= m) { // ��� M������ �������� �� ���� �ڸ� -> ���ܱ��� ���̸� �ø�
			answer = mid;
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}

	}
	cout << answer;
	return 0;
}