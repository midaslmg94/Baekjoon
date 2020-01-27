#include<iostream>
using namespace std;
/*
자연수 N과 M이 주어졌을 때, 아래 조건을 만족하는 길이가 M인 수열을 
모두 구하는 프로그램을 작성하시오.

1부터 N까지 자연수 중에서 중복 없이 M개를 고른 수열 --> 순열
수열은 사전 순으로 증가하는 순서로 출력해야 한다. 

dfs를 사용한 백트래킹(재귀)로 풀어보자
*/
int n, m;
bool visit[10];
int arr[10];
void dfs(int length) {
	if (length == m) {
		for (int i = 0; i < m; i++) {
			cout << arr[i]<<' ';			
		}
		cout << "\n";
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (visit[i])
			continue;
		visit[i] = true;
		arr[length] = i;
		dfs(length + 1);
		visit[i] = false;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);	cout.tie();
	freopen("input.txt", "r", stdin);
	cin >> n >> m; // n개 중 m개를 중복없이 고름
	dfs(0);

}