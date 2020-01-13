#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int>lotte; // �� �� 6���� ��

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);

	while (true) {
		int k;
		cin >> k;
		if (k == 0) { exit(0); }
		lotte.clear();
		for (int i = 0; i < k; i++) {
			int num; cin >> num;
			lotte.push_back(num);
		}
		sort(lotte.begin(), lotte.end());
		vector<int>select;
		for (int i = 0; i < k - 6; i++) {
			select.push_back(0);
		}
		for (int i = 0; i < 6; i++) {
			select.push_back(1);
		}
		vector<vector<int>>ans(1800); // �ִ� ���� �� �ִ� ����� �� : 13C7 = 1756��
		int n = 0;
		do {
			for (int i = 0; i < select.size(); i++) {
				if (select[i] == 1) {
					ans[n].push_back(lotte[i]);
				}
			}
			n++;
		} while (next_permutation(select.begin(), select.end()));
		sort(ans.begin(), ans.end()); 
		bool p = false; // ���๮�� ����� ���� 
		for (int i = 0; i < ans.size(); i++) {
			for (int j = 0; j < ans[i].size(); j++) {
				cout << ans[i][j] << ' ';
				p = true;
			}
			if(p)cout << "\n";
		}
		if(p)cout << "\n";
	}
}