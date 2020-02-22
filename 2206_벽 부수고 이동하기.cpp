#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define MAX 1000
using namespace std;
int n;
int m;
int map[MAX][MAX];
struct INFO {
	int dist;
	int y;
	int x;
	int block;
};
struct cmp {
	bool operator()(INFO a, INFO b) {
		return a.dist > b.dist; 
	}
};
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin); 
	
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < m; j++) {
			map[i][j] = str[j] - '0';
		}
	}

	return 0;
}