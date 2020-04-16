#include<iostream>
#include<string.h>
using namespace std;
long long arr[31][31];
int n;
long long recur(int one, int half) {
	if (one == 0 && half == 0)
		return 1;

	if (arr[one][half] > 0) {
		return arr[one][half]; // ¿Ö?
	}

	if (one > 0) {
		arr[one][half] += recur(one - 1, half + 1);
	}
	if (half > 0) {
		arr[one][half] += recur(one, half - 1);
	}

	return arr[one][half];
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);

	while (true) {
		cin >> n;
		if (n == 0) { break; }		
		cout << recur(n, 0)<<endl;
	}
	return 0;
}