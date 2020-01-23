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
	// 가진 카드의 개수
	cin >> n;
	int tmp;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		card.push_back(tmp);
	}
	sort(card.begin(), card.end());

	// 찾아야 할 숫자들
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> tmp;
		check.push_back(tmp);
	}
	// card = -10 -10 2 3 3 6 7 10 10 10
	// check = 10 9 -5 2 3 4 5 -10
	// lower bound는 찾고자 하는 값 이상이 처음 나타나는 위치
	// upper bound는 찾고자 하는 값 초과값이 처음으로 나타나는 위치

		int s_idx = 0;
		int e_idx = 0;
	for (int i = 0; i < m; i++) {
		s_idx = lower_bound(card.begin(), card.end(), check[i]) - card.begin();
		e_idx = upper_bound(card.begin(), card.end(), check[i]) - card.begin();
		cout << e_idx-s_idx << ' ';
	}
}