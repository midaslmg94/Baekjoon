#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int L, C;
char alpha[16];

// cnt는 지금까지 선택한 알파뱃의 총 개수, mo는 모음, ja는 자음, s는 현재까지 만들어진 암호
void go(int index, int cnt, int mo, int ja, string s) {
	if (cnt == L) { // 선택한 알파벳의 개수가 고르려는 알파벳의 개수와 같을 때
		if (mo >= 1 && ja >= 2)
			cout << s << endl;
		return;
	}
	if (index == C) return; // 인덱스가 끝까지 간 경우
	if (alpha[index] == 'a' || alpha[index] == 'e' || alpha[index] == 'i' || alpha[index] == 'o' || alpha[index] == 'u')
		go(index + 1, cnt + 1, mo + 1, ja, s + alpha[index]); // 모음 추가
	else
		go(index + 1, cnt + 1, mo, ja + 1, s + alpha[index]); // 자음 추가
	go(index + 1, cnt, mo, ja, s); // 왜 이게 들어가지? --> 예를들어 'a'가 추가되었을 때 'a'를 선택하지 않고 재귀를 돌리는 경우에 대해서 탐색을 해주기 위함
}
int main() {
	cin >> L >> C;
	for (int i = 0; i < C; i++)
		cin >> alpha[i];
	sort(alpha, alpha + C);
	go(0, 0, 0, 0, "");
	return 0;
}