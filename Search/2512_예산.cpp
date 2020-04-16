#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string.h>
#define endl "\n"
#define MAX 10000
using namespace std;
int n;
int budget;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);
	cin >> n;

	vector<int>v;
	for (int i = 0; i < n; i++) {
		int tmp; cin >> tmp;
		v.push_back(tmp);
	}
	sort(v.begin(), v.end());
	cin >> budget;

	int left = 0; // 최소 요청예산
	int right = v[n - 1];  // 최대 요청예산
	int money = 0;
	while (left <= right) {
		money = 0; // 상한액에 맞게 나눠줄 예산의 총합		
		int mid = (left + right) / 2; // 상한액

		// 예산 요청에 맞게 나눠주기
		for (int i = 0; i < n; i++) {
			if (v[i] < mid) { // 요청 예산이 상한액 미만 -> 요청예산 만큼 줌
				money += v[i];
			}
			else { // 요청 예산이 상한액 이상-> 상한액 만큼 줌
				money += mid;
			}
		}

		if (money > budget) { // 나눠줘야할 돈이 총 예산보다 많으므로 상한액을 낮춰야함
			right = mid - 1;
		}
		else { // 상한액을 높여도 된다.
			left = mid + 1;
		}
	}
	cout << right;

}
