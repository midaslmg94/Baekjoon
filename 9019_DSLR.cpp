#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#define endl "\n"
using namespace std;
int number[10001];
bool visit[10001];
int a, target;

int regi(int oper, int num) {
	int tmp = num;
	if (oper == 0) {//D명령
		tmp = (2 * num) % 10000;
	}
	else if (oper == 1) {//S명령
		tmp = num - 1;
		if (tmp <= 0) {
			tmp = 9999;
		}
	}
	else if (oper == 2) {//L명령
		string str = to_string(tmp);
	}
	else {//R명령
		string str = to_string(tmp);

	}
	return tmp;
}
void bfs(int n) {
	queue<int>q;
	q.push(n);
	visit[n] = true;
	while (!q.empty()) {
		n = q.front();
		q.pop();
		for (int k = 0; k < 4; k++) {
			int change = regi(k,n);
			if (change == target);
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);
	int t;
	cin >> t;
	for (int i = 1; i <= 10000; i++) {
		number[i] = i;
	}
	while (t--) {
		memset(visit, false, sizeof(visit));
		cin >> a >> target;
		bfs(a);
	}
}
