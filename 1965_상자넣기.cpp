#include<iostream>
#include<vector>
#include<algorithm>
#define MAX 1000
using namespace std;
int arr[MAX];
int dp[MAX];
vector<int>v_dp;
int ans = 0;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	v_dp.push_back(arr[0]);
	for (int i = 1; i < n; i++) {
		if (v_dp.back() < arr[i]) {//더 큰 값이 들어옴
			v_dp.push_back(arr[i]);
		}
		else { // 더 작은 값이 들어옴 
			auto pos = lower_bound(v_dp.begin(), v_dp.end(),arr[i]);
			*pos = arr[i];
		}
	}
	cout << v_dp.size();
}