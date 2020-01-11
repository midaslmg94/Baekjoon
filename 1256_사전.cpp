#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

/*
	사전에 수록되어 있는 모든 문자열은 N개의 "a"와 M개의 "z"로 이루어져 있다. 
	그리고 다른 문자는 없다. 사전에는 알파벳 순서대로 수록되어 있다.
	규완이는 사전을 완성했지만, 동호는 사전을 완성하지 못했다. 동호는 자신의 과제를 끝내기 위해서 규완이의 사전을 몰래 참조하기로 했다. 동호는 규완이가 자리를 비운 사이에 몰래 사전을 보려고 하기 때문에, 문자열 하나만 찾을 여유밖에 없다.

N과 M이 주어졌을 때, 규완이의 사전에서 K번째 문자열이 무엇인지 구하는 프로그램을 작성하시오.
첫째 줄에 N, M, K가 순서대로 주어진다. N과 M은 100보다 작거나 같은 자연수이고, K는 1,000,000,000보다 작거나 같은 자연수이다.
첫째 줄에 규완이의 사전에서 K번째 문자열을 출력한다. 만약 규완이의 사전에 수록되어 있는 문자열의 개수가 K보다 작으면 -1을 출력한다.


*/


int n, m;
long long k;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);
	cin >> n >> m >> k;
	string str = "";
	for (int i = 0; i < n; i++) {
		str += 'a';
	}
	for (int i = 0; i < m; i++) {
		str += 'z';
	}
	int cnt = 0;
	// 모든 경우의 수를 다 세는 중 -> 시간 초과
	if (cnt < k) {
		cout << -1;
	}
	do {
		cnt++;
		//if (cnt == k) {
			cout << str << endl;
			//exit(0);
		//}
	} while(next_permutation(str.begin(), str.end()));
	cout << cnt;
}