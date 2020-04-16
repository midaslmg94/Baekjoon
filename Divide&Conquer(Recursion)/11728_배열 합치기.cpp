#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, m;
vector<int>v;
vector<int>w;
vector<int>ans;
void recur() {

}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);

	cin >> n >> m;
	for (int i = 0; i < n+m; i++) {
		int tmp; cin >> tmp;
		v.push_back(tmp);
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < n + m; i++) {
		cout << v[i] << ' ';
	}
	/*


	for (int i = 0; i < n; i++) {
		int tmp; cin >> tmp;
		v.push_back(tmp);
	}
	for (int i = 0; i < m; i++) {
		int tmp; cin >> tmp;
		w.push_back(tmp);
	}
	sort(v.begin(), v.end());
	sort(w.begin(), w.end());
	recur();*/
}