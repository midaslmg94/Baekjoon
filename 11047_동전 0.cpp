#include<iostream>
using namespace std;

int coin[10];
int main() {
	int n, k;
	cin >> n >> k;
	for (int i = n-1; i >=0; i--) {
		cin >> coin[i]; // 내림차순으로 입력받자
	}
	int cur_coin = 0; // 현재 사용할 동전
	int use_coin = 0; // 총 사용한 동전의 개수
	while (k) {
		for (int i = 0; i < n; i++) {
			cur_coin = coin[i];
			if (cur_coin > k) continue; // 사용가능한 동전이 더 크면 넘김
			use_coin += k / cur_coin;
			k = k % cur_coin;

		}
	}
	cout << use_coin;

}