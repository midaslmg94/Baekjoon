#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<deque>
#include<string.h>
#define endl "\n"
#define INF 987564231
using namespace std;
int n;
int answer = 0;
int a, b, c;
int dp[61][61][61]; // dp[x][y][z] = 체력이 x , y ,z 인 SCV를 파괴하는데 필요한 최소 공격 횟수
vector<int>scv;
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a;
		scv.push_back(a);
	}

	return 0;
}