#include<iostream>
#include<vector>
using namespace std;
vector<pair<int, int>>v;

void hanoi(int n, int from, int by, int to) {
	if (n == 1) { // base  case
		v.push_back({ from, to });
	}
	else {
		hanoi(n - 1, from, to, by); // 목적지가 아닌 곳으로 이동
		v.push_back({ from, to });
		hanoi(n - 1, by, from, to); // 다른 곳으로 옮겼던 원반을 그 위에 얹음
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);  cout.tie(0);
	int n;
	cin >> n;
	/*
	int cnt = 1;
	while (--n) {
		cnt = cnt * 2 + 1;
	}
	cout << cnt; // 움직이는 횟수는 점화식으로 구할 수 있다. An = 2*An-1 +1
	*/
	hanoi(n, 1, 2, 3);
	cout << v.size()<<endl;
	for (int i = 0; i < v.size(); i++) {
		cout << v[i].first << ' ' << v[i].second << endl;
	}
}