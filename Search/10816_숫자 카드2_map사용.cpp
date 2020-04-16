#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;
int N, M, x;
int main() {
	ios::sync_with_stdio(false), cin.tie(NULL);
	unordered_map<int, int> m;
	freopen("input.txt", "r", stdin);
	cin >> N;
	for(int i=0; i<N; i++){
		cin >> x;
		if (m.count(x) == 0) // x가 있는지 없는지 확인
			m[x] = 1;
		else ++m[x];
	}
	cin >> M;
	while (M--) {
		cin >> x;
		if (m.count(x) == 0)
			cout << 0 << ' ';
		else 
			cout << m[x] << ' ';
	}
}