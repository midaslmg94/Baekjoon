#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<deque>
#include<string.h>
#define endl "\n"
#define MAX 20+1
using namespace std;
int n;
int map[MAX][MAX];
bool visit[MAX];
int answer = 987654321;
int teamsize = 0;
void dfs(int idx, int cnt) {
	if (cnt == teamsize) {
		vector<int>teamA;
		vector<int>teamB;
		for (int i = 1; i <= n; i++) {
			if (visit[i]) {
				teamA.push_back(i); 
			}
			else {
				teamB.push_back(i);
			}
		}
		int scoreA = 0;
		int scoreB = 0;
		for (int i = 0; i < teamA.size(); i++) {
			for (int j = 0; j < teamA.size(); j++) {
				if (i != j) {
					scoreA += map[teamA[i]][teamA[j]];
				}
			}
		}
		for (int i = 0; i < teamB.size(); i++) {
			for (int j = 0; j < teamB.size(); j++) {
				if (i != j) {
					scoreB += map[teamB[i]][teamB[j]];
				}
			}
		}
		answer = min(answer, abs(scoreA - scoreB));
		return;
	}
	for (int i = idx; i <= n; i++) {
		if (visit[i])continue;
		visit[i] = true;
		dfs(i, cnt + 1);
		visit[i] = false;
	}
	
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 1; i <= n/2; i++) { //n >=4
		teamsize = i;
		dfs(1, 0);
		memset(visit, false, sizeof(visit));
	}
	cout << answer;
	return 0;
}