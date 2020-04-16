#include<iostream>
using namespace std;

// 플라스틱 세트 6과 9는 혼용가능이므로 6이 2개
// 0부터 9까지 (9는 0)
int set[10] = {1,1,1,1,1,1,2,1,1,0};
void addset(){
	for (int i = 1; i < 9; i++) {
		if (i == 6) {
			set[i] += 1;
		}
		set[i] += 1;
		
	}
}

int main() {
	int n;
	cin >> n;  // 9156853
	int res = 1;
	while (n) {
		int tmp = n % 10;
		if (tmp == 9) {
			tmp = 6; // 9는 6으로 치환
		}
		if (set[tmp] == 0) { // 플라스틱 숫자가 없으면
			addset();
			res++;
		}
		set[tmp]--; // 숫자 사용했으므로 하나 제거
		n = n / 10;
	}
	cout << res;
}