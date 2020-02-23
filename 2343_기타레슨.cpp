#include<iostream>
#include<algorithm>
#define MAX 100'000
using namespace std;
int n, m;
int blueray[MAX];
int result = 0;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);
	
	cin >> n >> m;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> blueray[i];
		sum += blueray[i];
	}
	int left = 0;
	int right = sum;

}