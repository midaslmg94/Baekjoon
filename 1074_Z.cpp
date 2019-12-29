#include<iostream>
using namespace std;
int n, r, c;
int result;
/*
	��͸� �̿��� 4��Ž��
*/
void recursion(int x, int y, int size) {
	if (size == 2) {
		if (x == r && y == c) { // 1��и�
			cout << result << endl;
			return;
		}
		result++;
		if (x == r && y + 1 == c) { //  2��и�
			cout << result << endl;
			return;
		}
		result++;
		if (x + 1 == r && y == c) { // 3��и�
			cout << result << endl;
			return;
		}
		result++;
		if (x + 1 == r && y + 1 == c) { // 4��и�
			cout << result << endl;
			return;
		}
		result++;
		return;
	}
	// 1��и� Ž��
	recursion(x, y, size / 2);
	// 2��и� Ž��
	recursion(x, y + size / 2, size/2);
	// 3��и� Ž��
	recursion(x + size / 2, y, size / 2);
	// 4��и� Ž��
	recursion(x + size / 2, y + size / 2, size / 2);
}


int main() {
	cin >> n >> r >> c;
	recursion(0, 0, 1 << n);
}