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
	cin >> n;
	int tmp;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		card.push_back(tmp);
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> tmp;
		check.push_back(tmp);
	}

	sort(card.begin(), card.end());
	//sort(check.begin(), check.end());
	
	for (int i = 0; i < m; i++) {
		if (binary_search(card.begin(), card.end(), check[i])) {
			cout << 1 << ' ';
		}
		else {
			cout << 0 << ' ';
		}
	}
}