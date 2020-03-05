#include<iostream>
#include<vector>
#include<queue>
#include<string>
#define INF 987654321
#define MAX 1001
#define pii pair<int,int>
using namespace std;

bool visit[MAX];
vector<pair<int, int>>graph[MAX];


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);
	int N, M;
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({ b,c });
		graph[b].push_back({ a,c });
	}
	
}