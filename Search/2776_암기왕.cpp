#include<bits/stdc++.h>
#define endl "\n"

using namespace std;
vector<int>note; // 수첩1
vector<int>mynote; // 수첩2
int n, m;
int num; // 찾으려는 숫자
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);
	int tc;
	cin >> tc;
	while (tc--) {
		note.clear();
		mynote.clear();
		cin >> n;
		int tmp;
		for (int i = 0; i < n; i++) {
			cin >> tmp; note.push_back(tmp);
		}
		sort(note.begin(), note.end());
		cin >> m;
		for (int i = 0; i < m; i++) {
			cin >> tmp; mynote.push_back(tmp);
		}
		for (int i = 0; i < m; i++) {
			auto up_idx = upper_bound(note.begin(), note.end(), mynote[i]);
			auto low_idx = lower_bound(note.begin(), note.end(), mynote[i]);
			// upper_bound - lower_bound는 해당 원소가, 배열에 몇번 등장했는지를 나타내는 것이다.
			if (up_idx - low_idx >= 1) { // 오늘 본 숫자를 대답했다면
				cout << 1 << endl;
			}
			else {
				cout << 0 << endl;
			}
			//cout << up_idx - low_idx << endl;
		}
	}
	return 0;
}