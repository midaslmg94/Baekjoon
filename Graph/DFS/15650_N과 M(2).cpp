#include<iostream>
using namespace std;
/*
자연수 N과 M이 주어졌을 때, 아래 조건을 만족하는 길이가 M인 수열을 
모두 구하는 프로그램을 작성하시오.

1부터 N까지 자연수 중에서 중복 없이 M개를 고른 수열 --> 조합
고른 수열은 오름차순이어야 한다.
*/
int n, m;
bool visit[9];
int arr[9];
void combination(int length, int idx) { // 시작점, 몇개를 뽑는지
	if (length == m) { // 원하는 만큼 뽑았음
		for (int i = 0; i < m; i++) {
				cout << arr[i] << ' ';
		}
		cout << "\n";
		return;
	}
	for (int i = idx; i <= n; i++) { // 1부터 n까지 뽑음
		if (visit[i]==true)
			continue;
		visit[i] = true;
		arr[length] = i;
		combination(length + 1, i+1);
		visit[i] = false;
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);	cout.tie();
	freopen("input.txt", "r", stdin);
	cin >> n >> m;
	combination(0,1);	
}