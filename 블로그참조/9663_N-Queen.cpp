#include<bits/stdc++.h>
#define endl "\n"
#define MAX 40
using namespace std;
int n;
int cnt;
bool checked[MAX]; // 세로 확인
bool checked_left[MAX]; // 왼쪽 방향 대각선
bool checked_right[MAX]; // 오른쪽 방향 대각선

void dfs(int cur){ // cur번째 줄에 퀸을 놓는다
	if(cur==n){ // 마지막 줄에 가면 끝
		cnt++;
		return;
	}
	for(int i=0; i<n; i++){ // 가로로 가면서 확인 (cur, i) 에 말을 놓을 예정
		if(checked[i]||checked_left[cur+i] || checked_right[cur-i+n-1])continue;		
		checked[i]= true;
		checked_left[cur+i]=true;
		checked_right[cur-i+n-1]=true;
		dfs(cur+1);
		checked[i]=false;
		checked_left[cur+i]=false;
		checked_right[cur-i+n-1]=false;
	}
}



int main() {	
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);
	cin>>n;
	dfs(0);
	cout<<cnt;
	return 0;

}