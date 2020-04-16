#include<iostream>
#include<vector>
const int MAX = 1000001;
using namespace std;
vector<pair<int, int>>v(MAX);
  
// i의 부분합을 구하는 함수
int func(int i) {
	int res = i;
	while (i > 0)
	{
		res = res + i % 10;
		i = i / 10;
	}
	return res;
}

int main() {
	bool flag = false; // 부분합의 유무 판단
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		v[i].first = i; // 자연수 i
		v[i].second = func(i); // 자연수 i의 부분합
	}
	for (int i = 1; i < n; i++) {
		if (v[i].second == n) {
			cout << v[i].first;
			flag = true;
			return 0;
		}
	}
	// 부분합이 없는 경우 0을 출력
	if (flag == false) {
		cout << 0;
	}
}