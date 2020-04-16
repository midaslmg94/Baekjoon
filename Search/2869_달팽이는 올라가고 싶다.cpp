#include<bits/stdc++.h>
#define endl "\n"
#define MAX 1000000000
using namespace std;
long long a, b, v;
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);
	cin >> a >> b >> v; // v만큼의 길이의 나무를 올라가는데 매일 a만큼 올라가고, b만큼 떨어짐 
	long long dist = a - b; // 달팽이가 하루에 움직일 수 있는 거리
	long long left = 1;
	long long right = MAX;
	long long result = 0;
	while (left <= right) {
		long long mid = (left + right) / 2; // mid일 만에 올라갈 수 있는지		
		long long len = 0; // mid일만큼 지났을 때 올라가는 거리
		len = dist * (mid - 1); // 마지막날은 a만큼 올라가는 것만 더해줌
		len += a;
		if (len < v) { // 더 많은 날짜가 필요함
			left = mid + 1;
		}
		else {
			result = mid;
			right = mid - 1;
		}
	}
	cout << result;
}