#include<iostream>
#include<algorithm>
#include<string.h>
#include<queue>
#include<vector>
using namespace std;
typedef pair<int, int>pii;
int n, m;
int sol(vector<pii>home, queue<pii>choice_store) {
	vector<int>dist(home.size()); // 각 집과 치킨집들 중의 최소 거리 저장
	for (int i = 0; i < dist.size(); i++) {
		dist[i] = 1001;
	}
	int result = 0;
	while (!choice_store.empty()) { // 치킨집은 m개를 살림
		int store_y = choice_store.front().first;
		int store_x = choice_store.front().second;
		choice_store.pop();
		for (int i = 0; i < home.size(); i++) {
			int diff = abs(store_y - home[i].first) + abs(store_x - home[i].second);
			dist[i] = min(dist[i], diff);
		}
	}
	for (int i = 0; i < dist.size(); i++) {
		result += dist[i];
	}
	return result;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);	cout.tie();
	freopen("input.txt", "r", stdin);
	vector<pii>store;
	vector<pii>home;
	cin >> n >> m;
	int store_cnt = 0; //  전체 치킨집의 개수
	int input;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> input;
			if (input == 1)
				home.push_back({ i,j });
			else if (input == 2) {
				store.push_back({ i,j });
				store_cnt++;
			}
		}
	}

	// 살아남을 치킨집의 개수를 구하기 
	vector<int>choose;
	for (int i = 0; i < store_cnt; i++) {
		if (i < m) {
			choose.push_back(1);
		}
		else {
			choose.push_back(0);
		}
	}

	// 전체 치킨집 중 m개의 치킨집을 고르고, 집과의 거리를 구함
	int min_dist = 987'654'321;
	int cur = 0;
	do {
		queue<pii>choice_store;
		for (int i = 0; i < choose.size(); i++) {
			if (choose[i] == 1) {
				int store_y = store[i].first;
				int store_x = store[i].second;
				choice_store.push({ store_y, store_x }); // 선택한 m개의 치킨집의 위치
			}
		}
		cur = sol(home, choice_store);
		min_dist = min(cur, min_dist);
		/*cout << "몇개의 치킨집?" << choice_store.size() << endl;
		while (!choice_store.empty()) {
			cout << choice_store.front().first<<' '<<choice_store.front().second<<endl;
			choice_store.pop();
		}*/
	} while (prev_permutation(choose.begin(), choose.end()));
	cout << min_dist;
}