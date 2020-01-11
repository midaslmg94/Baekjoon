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
int p_size ,n_size;
void sum_pos() {
	p_size = pos.size();
	if (p_size%2) { // 홀수개
		if (is_one) { // 1이 있는지 확인
			for (int i = 0; i < p_size; i += 2) {
				sum += (pos[i] * pos[i + 1]);
			}
		}
		else {

		}
	}
	else {// 짝수개
		if (is_one) {// 0이 있는지 확인 

		}
		else {

		}
	}

}

void sum_neg() {
	n_size = neg.size();
	if ( n_size % 2) { // 홀수개

	}
	else {// 짝수개

	}
}

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
			}
			pos.push_back(tmp);
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

	   

	sum_neg();
	sum_pos();
	cout << sum << endl;
}