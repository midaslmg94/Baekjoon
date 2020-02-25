#include<iostream>
#include<string.h>
#include<vector>
#define MAX 5
using namespace std;
vector<int>arr;
vector<int>result;
int visit[MAX];

/* 순열 구하기 */
void prt_permu() {
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << ' ';
	}
	cout << endl;
}
void dfs_permu(int cnt){ // cnt : 몇개를 뽑을지
	if (cnt == 3) {
		prt_permu();
		return;
	}
	for (int i = 0; i < MAX; i++) {
		if (visit[i] == true) continue;
		visit[i] = true;
		result.push_back(arr[i]);
		dfs_permu(cnt + 1);
		result.pop_back();
		visit[i] = false;
		
	}
}

/* 조합 구하기 */
void prt_combi() {
	for (int i = 0; i < MAX; i++) {
		if (visit[i] == true) {
			cout << arr[i] << ' ';
		}
	}
	cout << endl;
}
void dfs_combi(int idx, int cnt) { // idx : 시작점을 결정해주는 변수, cnt : 몇개를 뽑을지
	if (cnt == 3) {
		prt_combi();
		return;
	}
	for (int i = idx; i < MAX; i++) {
		if (visit[i] == true) continue;
		visit[i] = true;
		dfs_combi(i, cnt + 1);
		visit[i] = false;
	}
}


int main() {
	for (int i = 0; i <MAX; i++) {
		arr.push_back(i+1);
	}
	dfs_permu(0);
	/*
	1 2 3
	1 2 4
	1 2 5
	1 3 2
	1 3 4
	1 3 5
	1 4 2
	1 4 3
	1 4 5
	1 5 2
	1 5 3
	1 5 4
	2 1 3
	2 1 4
	2 1 5
	2 3 1
	2 3 4
	2 3 5
	.
	.
	.
	*/
	memset(visit, false, sizeof(visit));
	cout << "==================" << endl;
	dfs_combi(0, 0);
	/*
	1 2 3
	1 2 4
	1 2 5
	1 3 4
	1 3 5
	1 4 5
	2 3 4
	2 3 5
	2 4 5
	3 4 5
	*/
}