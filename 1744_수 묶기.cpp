#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n;
vector<int>pos; // 양수 배열
vector<int>neg; // 음수 배열 
long long sum; // 합
bool is_zero = false; // 0이 있는지 확인
bool is_odd = false;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int tmp; cin >> tmp;
		if (tmp > 0) {
			pos.push_back(tmp);
		}
		else if (tmp == 0) {
			is_zero = true;
		}
		else {
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
}