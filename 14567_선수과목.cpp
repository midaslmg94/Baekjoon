#include<iostream>
#include<algorithm>
#include<vector>
#define MAX 1000+1
#define endl "\n"
using namespace std;
int n, m;
int course[MAX][MAX];
int indegree[MAX];
int semester[MAX];

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);
	cin >> n >> m;	
	int prev= 0;
	int next = 0;
	
	for (int i = 0; i < m; i++) {
		cin >> prev >> next;
		course[next][prev] = 1;
		indegree[next]++;
	}
	for (int i = 1; i <= n; i++) {
		if (indegree[i] == 0) { // 진입차수가 없음 : 1학기만에 수강 가능
			semester[i] = 1;
			continue;
		}
		for (int j = 1; j <= n; j++) {
			if (course[i][j]==1) { // i번 과목을 듣기 위해 j번 과목을 수강해야 함
				int preSemester = semester[j]; // j번 과목을 수강하는데 필요한 학기 수
				semester[i] = max(semester[i], preSemester+1);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		cout << semester[i] << ' ';
	}

	return 0;
}