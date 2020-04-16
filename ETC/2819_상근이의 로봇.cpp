#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
int n, m;
vector<pair<int, int>>v; // 조사점
queue<char>oper;
vector<int>ans; // 결과
/*
로봇이 현재 (x,y)에 있다고 하자. 
S(north)는 (x, y+1)로,
J(south)는 (x,y-1)로, 
I(east)는 (x+1,y)로, 
Z(west)는 (x-1,y)로 이동하라는 의미이다.
*/

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);	cout.tie();
	freopen("input.txt", "r", stdin);
	cin >> n >> m;
	int x, y;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		v.push_back({ x,y });
	}
	char tmp;
	for (int i = 0; i < m; i++) {
		cin >> tmp;
		oper.push(tmp);
	}

}
