#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;
int Map[201][201];
int A_fare[201];
int B_fare[201]; 
bool checked[201][201];

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 1e9;
    for(int i=0; i<fares.size(); i++){
        Map[fares[i][0]][fares[i][1]]=fares[i][2];
        Map[fares[i][1]][fares[i][0]]=fares[i][2];        
    }
    for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j)continue;
			if (Map[i][j] == 0)
				Map[i][j] = 1e9; // 갈 수 없는 곳은 무한대
		}
	}

    for (int k = 1; k <= n; k++) {// k : 거쳐가는 노드
		for (int i = 1; i <= n; i++) { // i : from
			for (int j = 1; j <= n; j++) { // j : to
				if (Map[i][k] + Map[k][j] < Map[i][j]) { // k를 거쳐가는게 더 작으면
					Map[i][j] = Map[i][k] + Map[k][j]; // 값 갱신
				}
			}
		}
	}
    for(int i=1;i<=n;i++)
        answer = min(answer, Map[s][i] + Map[i][a] + Map[i][b]);    

    return answer;
}

int main() {
    ios::sync_with_stdio(false);
    vector<vector<int>> fares;
    fares = {{4, 1, 10}, {3, 5, 24}, {5, 6, 2}, {3, 1, 41}, {5, 1, 24}, {4, 6, 50}, {2, 4, 66}, {2, 3, 22}, {1, 6, 25}};
    int n = 6;
    int s=4;
    int a=6;
    int b=2;
    int ans = solution(n,s,a,b,fares);
    cout << ans;
    return 0;
}