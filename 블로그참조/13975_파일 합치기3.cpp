#include<bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
int tc;
int k;
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);
	cin >> tc;
	while (tc--) {
		priority_queue<ll,vector<ll>,greater<ll>>pq;
		ll answer = 0;
		ll n;
		cin >> k;
		// 가장 작은거 2개씩만 합치면 된다
		for (int i = 0; i < k; i++) {
			cin >> n; 
			pq.push(n);
		}
		while (pq.size() > 1) {
			ll a = pq.top(); pq.pop();
			ll b = pq.top(); pq.pop();
			ll sum = a + b;
			answer += sum;
			pq.push(sum);
		}
		cout << answer << endl;
	}
	return 0;
}