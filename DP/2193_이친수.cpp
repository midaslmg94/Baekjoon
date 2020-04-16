#include<iostream>
using namespace std;
/*
	피보나치 활용
*/

int n;
long long pinary[91]; // 90번째 피보나치는 int 범위를 넘어감
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);
	cin >> n;
	pinary[1] = 1;
	pinary[2] = 1;
	for (int i = 3; i <= n; i++) {
		pinary[i] = pinary[i - 1] + pinary[i - 2];
	}
	cout << pinary[n];

}