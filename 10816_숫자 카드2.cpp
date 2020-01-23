#include<iostream>
#include<algorithm> 
#include<vector>
using namespace std;
int n, m;
vector<int>card;
vector<int>check;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);
	// ���� ī���� ����
	cin >> n;
	int tmp;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		card.push_back(tmp);
	}
	sort(card.begin(), card.end());

	// ã�ƾ� �� ���ڵ�
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> tmp;
		check.push_back(tmp);
	}
	// card = -10 -10 2 3 3 6 7 10 10 10
	// check = 10 9 -5 2 3 4 5 -10
	// lower bound�� ã���� �ϴ� �� �̻��� ó�� ��Ÿ���� ��ġ
	// upper bound�� ã���� �ϴ� �� �ʰ����� ó������ ��Ÿ���� ��ġ

		int s_idx = 0;
		int e_idx = 0;
	for (int i = 0; i < m; i++) {
		s_idx = lower_bound(card.begin(), card.end(), check[i]) - card.begin();
		e_idx = upper_bound(card.begin(), card.end(), check[i]) - card.begin();
		cout << e_idx-s_idx << ' ';
	}
}