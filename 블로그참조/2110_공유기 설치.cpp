#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
/*
	이분 탐색 - 파라메트릭 서치
*/
int n, c;
vector<int>home;

bool possible(int dist) {
	int cnt = 1; //공유기의 개수
	int prev = home[0];
	for (int i = 1; i < n; i++) {
		if (home[i] - prev >= dist) {// 설치 가능
			cnt++;
			prev = home[i];
		}
	}
	if (cnt >= c) {// 공유기를 필요량 보다 더 많이 설치함
		return true;
	}
	return false;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);

	cin >> n >> c; // 집의개수, 공유기의 개수
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		home.push_back(tmp);
	}
	sort(home.begin(), home.end());

	// 최소 거리 , 최대 거리
	int left = 1, right = home[n - 1] - home[0]; 
	int result = 0;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (possible(mid)) {
			result = max(result, mid);
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}

	}
	cout << result;
}