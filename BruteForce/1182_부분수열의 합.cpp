#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>
using namespace std;
int N, S;
int main() {
	cin >> N >> S;
	vector<int>v(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end()); // 정렬은 선택사항
	int cnt = 0;
	vector<int>choice(N);
	for (int i = N-1; i >=0; i--) {// 이 부분이 중요. 0, 0 앞에 들어감
		choice[i] = 1;
		do{
			int sum = 0;
			for (int j = 0; j < N; j++) {
				if (choice[j] == 1) {// N개 중 1개 뽑는 경우, 2개 뽑는 경우 ... N개 뽑는 경우의 순서
					sum += v[j];
				}
			}
			if (sum == S) {
				cnt++;
			}
		} while (next_permutation(choice.begin(), choice.end()));
	}
	cout << cnt;
}