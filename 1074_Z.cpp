#include<iostream>
using namespace std;
int n, r, c;
int result;
/*
	Àç±Í¸¦ ÀÌ¿ëÇÑ 4ºÐÅ½»ö
*/
void recursion(int x, int y, int size) {
	if (size == 2) {
		if (x == r && y == c) { // 1»çºÐ¸é
			cout << result << endl;
			return;
		}
		result++;
		if (x == r && y + 1 == c) { //  2»çºÐ¸é
			cout << result << endl;
			return;
		}
		result++;
		if (x + 1 == r && y == c) { // 3»çºÐ¸é
			cout << result << endl;
			return;
		}
		result++;
		if (x + 1 == r && y + 1 == c) { // 4»çºÐ¸é
			cout << result << endl;
			return;
		}
		result++;
		return;
	}
	// 1»çºÐ¸é Å½»ö
	recursion(x, y, size / 2);
	// 2»çºÐ¸é Å½»ö
	recursion(x, y + size / 2, size/2);
	// 3»çºÐ¸é Å½»ö
	recursion(x + size / 2, y, size / 2);
	// 4»çºÐ¸é Å½»ö
	recursion(x + size / 2, y + size / 2, size / 2);
}


int main() {
	cin >> n >> r >> c;
	recursion(0, 0, 1 << n);
}