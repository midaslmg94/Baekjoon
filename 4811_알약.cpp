#include<iostream>
#include<string.h>
using namespace std;
long long recur(int one, int half) {
	if (one == 1 && half == 0) {
		return 1;
	}
	long long result = recur(one - 1, half) + recur(one, half - 1);

	return result; 
}
int n;
int main() {
	freopen("input.txt", "r", stdin);
	cin >> n;
	int arr[6];
	for (int i = 0; i < 6; i++) {
		int k;
		cin >> arr[i];
	}
	for (int i = 0; i < 6; i++) {
		cout << arr[i] << endl;
	}
	
}