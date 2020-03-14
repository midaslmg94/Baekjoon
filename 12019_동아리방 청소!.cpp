#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<deque>
#include<string.h>
#define endl "\n"
#define MAX 100+1
#define INF 987654231
using namespace std;
int people[MAX];
bool clean[MAX];
int answer = INF;
vector<int>clean_day;
vector<int>day;
int n, m;

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> people[i];
	}
	

	

	return 0;
}