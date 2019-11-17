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
	long long left = 0; // ���� ���� ������ ����
	long long right = maxTree; // ���� ū ������ ����
	int answer = 0;
	long long myTree = 0; // ���� �ڸ� �������� ����
	while (left <= right) {
		long long mid = (left + right) / 2;
		myTree = 0;
		for (int i = 0; i < N; i++) {
			if (tree[i] > mid) {
				myTree += tree[i] - mid;
			}
		}
		if (M > myTree) { // ������ �� �ʿ��ϴٸ�
			right = mid - 1;
		}
		else { // ������ �ʹ� ���� �ڸ�
			left = mid + 1;
			answer = mid;
		}
	}
	cout << answer;
}