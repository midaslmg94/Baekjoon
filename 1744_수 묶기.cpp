#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n;
vector<int>pos; // 양수 배열
vector<int>neg; // 음수 배열 
long long sum; // 합
bool is_zero = false; // 0이 있는지
bool is_one = false; // 1이 있는지
int p_size, n_size;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("input.txt", "r", stdin);
	cin >> n;

	for (int i = 0; i < n; i++) {
		int tmp; cin >> tmp;
		if (tmp > 0) {
			if (tmp == 1) {
				is_one = true;
				sum += 1; 
			}
			else { pos.push_back(tmp); }
		}
		else {
			if (tmp == 0) {
				is_zero = true;
			}
			neg.push_back(tmp);
		}
	}
	/*
		- 숫자가 0일 때 :
			- 0 1 의 경우, 0+1>0*1
			- -1 0 의 경우. -1+0 <-1*0
		- 숫자가 1일 때
			- 1 2 의 경우, 1+2>1*2

		- 음수가 홀수개 일때
			- 가장 큰 음수를 제외 하고 2개씩 묶기
		- 음수가 짝수개 일때
			- 2개씩 묶기 가능
	*/
	sort(pos.begin(), pos.end(), greater<int>());
	sort(neg.begin(), neg.end());

	// 1처리
	/*if(pos.size() >= 1 && pos[pos.size() - 1] == 1) { // 1이 있음
		if (pos.size() % 2 == 0) { // 짝수개면 1은 더하기연산을 해야함. 1 1 1 1 1 의 경우?
			sum += pos[pos.size() - 1];
			pos.pop_back();			
		}
	}*/
	// 양수 더하기
	if (pos.size()) {
		for (int i = 0; i < pos.size() - 1; i+=2) {
			sum += (pos[i] * pos[i + 1]);
		}
		if (pos.size() % 2 != 0) { // 홀수개면 마지막 1개가 남음
			sum += pos[pos.size() - 1];
		}
	}

	// 0 처리
	if (neg.size() >= 1 && neg[neg.size() - 1] == 0) {
		if (neg.size() % 2 != 0) { // 홀수개면 0은 없어져야함
			neg.pop_back();
		}
	}
	// 음수 더하기
	if (neg.size()) {
		for (int i = 0; i < neg.size() - 1; i+=2) {
			sum += (neg[i] * neg[i + 1]);
		}
		if (neg.size() % 2 != 0) { // 홀수개면 마지막 1개가 남음
			sum += neg[neg.size() - 1];
		}
	}
	cout << sum;
}