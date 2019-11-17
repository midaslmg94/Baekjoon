#include<iostream>

using namespace std;
long long memo[91];
/*Bottom-up방식 문제풀이*/
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> memo[0] >> memo[1] >> n;
	for (int i = 2; i < n; i++) {
		memo[i] = memo[i - 1] + memo[i - 2];
	}
	cout << memo[n - 1];
	return 0;
}  