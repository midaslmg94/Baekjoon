#include<bits/stdc++.h>
#define endl "\n"

using namespace std;
vector<int>note; // ��ø1
vector<int>mynote; // ��ø2
int n, m;
int num; // ã������ ����
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
			// upper_bound - lower_bound�� �ش� ���Ұ�, �迭�� ��� �����ߴ����� ��Ÿ���� ���̴�.
			if (up_idx - low_idx >= 1) { // ���� �� ���ڸ� ����ߴٸ�
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