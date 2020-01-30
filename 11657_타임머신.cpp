#include<iostream>
#include<vector>
#define MAX 501
typedef pair<int, int> pii;
using namespace std;
vector<pii>v[MAX];
int n, m;
int from, to, cost;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);

	cin >> n >> m;
	/*
	 C는 버스를 타고 이동하는데 걸리는 시간이다. 
	 시간 C가 양수가 아닌 경우가 있다. 
	 C = 0인 경우는 순간 이동을 하는 경우
	 C < 0인 경우는 타임머신으로 시간을 되돌아가는 경우이다.
	*/
	for (int i = 0; i < m; i++) {
		cin >> from >> to >> cost;
	}
}
