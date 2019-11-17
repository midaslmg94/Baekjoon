#include<iostream>
#include<algorithm>
using namespace std;
int tree[1000000];
int main() {
	int N, M;
	cin >> N >> M;
	int maxTree = 0;
	for (int i = 0; i < N; i++) {
		cin >> tree[i];
		maxTree = max(maxTree, tree[i]);
	}
	long long left = 0; // 가장 작은 나무의 길이
	long long right = maxTree; // 가장 큰 나무의 길이
	int answer = 0;
	long long myTree = 0; // 현재 자른 나무들의 길이
	while (left <= right) {
		long long mid = (left + right) / 2;
		myTree = 0;
		for (int i = 0; i < N; i++) {
			if (tree[i] > mid) {
				myTree += tree[i] - mid;
			}
		}
		if (M > myTree) { // 나무가 더 필요하다면
			right = mid - 1;
		}
		else { // 나무를 너무 많이 자름
			left = mid + 1;
			answer = mid;
		}
	}
	cout << answer;
}