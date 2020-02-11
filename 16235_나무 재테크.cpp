#include<iostream>
#include<vector>
#include<queue>
#include<string.h>
#include<algorithm>
#define MAX 10
using namespace std;
int dy[8] = { -1,-1,-1,0,0,1,1,1 };
int dx[8] = { -1,0,1,-1,1,-1,0,1 };
int N, M, K; // 땅 크기, 나무의 개수, K년

vector<vector<int>>v;
int robot[MAX][MAX];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);	cout.tie();
	freopen("input.txt", "r", stdin);

	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> robot[i][j];
		}
	}
	for (int i = 0; i < M; i++) {

	}
	while (K--) {

	}
}