#include<iostream>
bool check[10];
int ans[10];
using namespace std;
void sol(int n, int m, int index) {
	if (index == m) {//������ ���
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
	//1���� n���� �ڿ��� �� �ߺ����� m���� �� ����	
	int n, m;
	cin >> n >> m;
	sol(n, m, 0);
	return 0;
}