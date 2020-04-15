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
	// 1사분면 탐색 : 재귀를 돌때마다 4개의 사분면으로 나누니까 크기가 2^-1로 줄어든다. 
	recursion(x, y, size>>1);
	// 2사분면 탐색
	recursion(x, y + (size>>1), size>>1); // 연산자 우선순위 때문에 (size>>1)
	// 3사분면 탐색
	recursion(x + (size>>1), y, size>>1);
	// 4사분면 탐색
	recursion(x + (size>>1), y + (size>>1), size>>1);
}


int main() {
	cin >> n >> r >> c;
	recursion(0, 0, 1 << n); // 1<<n 은 2의 n제곱을 의미
}