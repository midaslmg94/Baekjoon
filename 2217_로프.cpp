#include<iostream>
#include<algorithm>
using namespace std;

int rope[100000];
int n;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> rope[i];
	}
	sort(rope, rope + n);
	int max_weight = 0;
	for (int i = 0; i < n; i++) {
		int weight = rope[i] * (n - i);
		max_weight = max(max_weight, weight);
	}
	cout << max_weight;
}