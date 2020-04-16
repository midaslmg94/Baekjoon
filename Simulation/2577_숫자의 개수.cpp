#include<iostream>
#include<string.h> // memset 헤더
using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	int ans[10];
	int res = a * b * c;  // 최대 10억
	
	memset(ans, 0, sizeof(ans));
	while (res) {
		int tmp = res % 10;
		ans[tmp]+=1;
		res = res/10;
	}
	for (int i = 0; i < 10; i++) {
		cout << ans[i] << endl;
	}
}