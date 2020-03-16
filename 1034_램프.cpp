#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<deque>
#include<string.h>
#define endl "\n"
#define MAX 50
using namespace std;
int n, m;
int k;
int lamp[MAX][MAX];
int dp[MAX];
int answer = -1;
void changeLamp() {

}
int calc() { // 켜져 있는 행의 개수를 구함
	int result = 0;
	for (int i = 0; i < n; i++) {
		bool flag=true;
		for (int j = 0; j < m; j++) {
			if (lamp[i][j]==0) { // 꺼져있다면 
				flag = false;
				break;
			}
		}
		if(flag==true)
			result++;
	}
	return result;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < m; j++) {
			if (str[j] == '0') {
				lamp[i][j] = 0;
			}
			else {
				lamp[i][j] = 1;
			}
		}		
	}
	cin >> k; // 0<= k <=1000
	if (k > 50)k = 50;
	int change = 0;
	for (int i = 0; i < k; i++) {
		 

		answer = max(answer, calc());
	}

	cout << answer;
	return 0;
}