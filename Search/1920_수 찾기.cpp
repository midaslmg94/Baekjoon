#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n, m;
vector<int>v;
void sol(int n) {
	int left = 0;
	int right =v.size() - 1;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (n >= v[mid]) {// 찾으려는 값이 더 큼
			if(n== v[mid]){
				cout << 1 << "\n";
				return;
			}
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	cout << 0 << "\n";
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);	cout.tie();
	freopen("input.txt", "r", stdin);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int tmp; cin >> tmp;
		v.push_back(tmp);
	}
	cin >> m;
	vector<int>w;
	for (int i = 0; i < m; i++) {
		int tmp; cin >> tmp;
		w.push_back(tmp);
	}
	sort(v.begin(), v.end()); // 1 2 3 4 5
	for (int i = 0; i < w.size(); i++) {
		sol(w[i]);
	}
}