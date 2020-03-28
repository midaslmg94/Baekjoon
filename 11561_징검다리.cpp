#include <bits/stdc++.h>
#define ll unsigned long long
using namespace std;
int t;
ll n; // 1번, 2번 ... n번 징검다리
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);	cout.tie();
	freopen("input.txt", "r", stdin);
	cin >> t;
	while (t--) {
		cin >> n;		
		ll left = 0;
		ll right = n;
		ll answer = 0;
		while (left <= right) {
			ll mid = (left + right) / 2; // 개수 
			ll cnt = (mid + 1) * mid / 2; // // 등차수열의 합 공식
			if (cnt<=n) {
				left = mid + 1;
				answer = mid;
			}
			else {

				right = mid - 1;
			}
		}
		cout << answer << endl;
	}
}