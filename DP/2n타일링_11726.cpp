#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
long long ans = 0;
void combi(int n, int r) {
	//배열 동적할당, 0으로 초기화
	int* arr = new int[n]();

	//vector<int>v(n);
	for (int i = n - 1; i >= n - r; i--) {
		arr[i] = 1;
	}
	for (int i = 0; i < n; i++) {
		printf("v[%d]=%d \n", i, arr[i]);
	}
	do {
		for (int i = 0; i < n; i++) {
			if (arr[i] == 0) {
				cout << i + 1 << ' ';
			}
			cout << endl;
		}
	} while (next_permutation(arr, arr + n));
	delete[]arr;
}

long long combination(int n, int r) {
	long long res = 0;
	long long n_f = 1;
	long long n_r_f = 1;
	long long r_f = 1;
	for (int i = 1; i <= n; i++) {
		n_f = n_f * i;
	}
	for (int i = 1; i <= r; i++) {
		r_f = r_f * i;
	}
	for (int i = 1; i <= n - r; i++) {
		n_r_f = n_r_f * i;
	}
	res = n_f / (n_r_f * r_f);
	return res;

}

int main() {

	int N;
	cin >> N;
	if (N == 1 || N == 2) {
		cout << N; return 0;
	}
	else {
		int n = N;
		int r = N;
		if (N % 2 == 0) {// n이 짝수일 땐, nC0까지
			while (r >= 0) {
				ans += combination(n, r);
				n = n - 1;
				r = r - 2;
			}
		}// n이 홀수일 땐, nC1까지
		else {
			while (r > 0) {
				ans += combination(n, r);
				n = n - 1;
				r = r - 2;
			}
		}
	}
	ans = ans % 10007;
	cout << ans;
}