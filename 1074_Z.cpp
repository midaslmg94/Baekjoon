#include<iostream>
using namespace std;
int n, r, c;
int result;
/*
	재귀를 이용한 4분탐색
*/
void recursion(int x, int y, int size) {
	if (size == 2) {
		if (x == r && y == c) { // 1사분면
			cout << result << endl;
			return;
		}
		result++;
		if (x == r && y + 1 == c) { //  2사분면
			cout << result << endl;
			return;
		}
		result++;
		if (x + 1 == r && y == c) { // 3사분면
			cout << result << endl;
			return;
		}
		result++;
		if (x + 1 == r && y + 1 == c) { // 4사분면
			cout << result << endl;
			return;
		}
		result++;
		return;
	}
	// 1사분면 탐색
	recursion(x, y, size / 2);
	// 2사분면 탐색
	recursion(x, y + size / 2, size/2);
	// 3사분면 탐색
	recursion(x + size / 2, y, size / 2);
	// 4사분면 탐색
	recursion(x + size / 2, y + size / 2, size / 2);
}


int main() {
	cin >> n >> r >> c;
	recursion(0, 0, 1 << n);
}