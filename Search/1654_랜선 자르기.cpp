#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
	int k; //가진 랜선의 개수
	int n; // 필요한 랜선의 개수
	cin >> k >> n;
	vector<int>v;
	int t;
	for (int i = 0; i < k; i++) {
		cin >> t;
		v.push_back(t);
	}
	sort(v.begin(), v.end());
	long long left = 1;
	long long right = v[k - 1]; //자를 수 있는 최대 길이
	long long ans = 0;

	while (left <= right) { 
		long long mid = (left + right) / 2; // 현재 자르는 랜선의 길이
		long long cur = 0; // 현재까지 자른 랜선의 개수
		for (int i = 0; i < k; i++) {
			cur += v[i] / mid;
		}
		if (cur < n) { // 랜선의 개수가 더 필요하다면 
			right = mid - 1;
		}
		else {
			left = mid + 1;
			ans = mid;
		}

	}
	cout << ans;
}