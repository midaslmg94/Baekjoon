#include<iostream>
using namespace std;

int main() {
	int n1;
	int cnt = 0;
	cin >> n1;
	int n = n1;
	while (true) {
		int first = n / 10;
		int sec = n % 10;
		int ans = first + sec;
		n = (sec * 10) + (ans % 10);
		cnt++;  
		if (n == n1) {
			cout << cnt;
			break;
		}
	}
}