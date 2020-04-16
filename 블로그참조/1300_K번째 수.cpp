#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
#include<string.h>

#define endl "\n"
#define MAX 100000
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	freopen("input.txt", "r", stdin);
	int k; int n;
	cin >> n>>k;
	int left = 1;
	int right = k; 
	
	while (left <= right) {
		int mid = (left + right) / 2;
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			cnt += min(mid / i, n); // 이해가 잘 안감
		}
		if (cnt < k) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	cout << left;

}
