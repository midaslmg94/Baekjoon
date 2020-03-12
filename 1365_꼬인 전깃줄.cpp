#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<deque>
#include<string.h>
#define endl "\n"
#define MAX 100000
using namespace std;
// LIS로 풀자
int n;
int answer;
vector<int>v;
vector<int>lis; // 인덱스마다 각 증가 수열의 길이

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int tmp; cin >> tmp;
		v.push_back(tmp);
	}
	lis.push_back(v[0]);
	for (int i = 1; i < n; i++) {				
		if (lis.back() < v[i]) { // lis의 맨 뒤의 원소보다 큰 값이 들어오면 삽입
			lis.push_back(v[i]);
		}
		else { // lis의 맨 뒤 원소보다 작은 값이면, 그 원소가 들어갈 위치에 삽입
			int idx = lower_bound(lis.begin(), lis.end(), v[i]) - lis.begin();
			lis[idx] = v[i];
		}
		
	}
	answer = v.size()- lis.size();
	cout << answer;
	return 0;
}