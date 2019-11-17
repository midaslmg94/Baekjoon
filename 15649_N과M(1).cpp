#include<iostream>
bool check[10];
int ans[10];
using namespace std;
void sol(int n, int m, int index) {
	if (index == m) {//수열을 출력
		for (int i = 0; i < m; i++) {
			cout << ans[i] << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (check[i]) {
			continue;
		}
		check[i] = true;
		ans[index] = i;
		sol(n, m, index + 1);
		check[i] = false;
	}
}
  
int main() {
	//1부터 n까지 자연수 중 중복없이 m개를 고른 수열	
	int n, m;
	cin >> n >> m;
	sol(n, m, 0);
	return 0;
}