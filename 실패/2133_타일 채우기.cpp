#include<iostream>

using namespace std;
int arr[31] = {};
int main() {
	int n; 
	cin >> n;
	for (int i = 0; i <= n; i++) {
		arr[i] = 0;
	}
	arr[0] = 1;
	arr[1] = 0;
	arr[2] = 3;
	if(n%2==0){

	}

	cout << arr[n];
}