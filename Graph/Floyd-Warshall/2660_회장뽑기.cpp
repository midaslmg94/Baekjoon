#include<bits/stdc++.h>
#define endl "\n"
#define MAX 51
#define INF 987564;
using namespace std;
struct INFO {
	int num; // 회원번호
	int rank; // 점수
};
int people[MAX][MAX];
INFO candi[MAX];
int n;

bool cmp(const INFO& a, const INFO& b) {
	if (a.rank < b.rank) {
		return true;
	}
	else if (a.rank == b.rank) {
		if (a.num < b.num) {
			return true;
		}
		else {
			return false;
		}
	}
	return false;
}
void floyd() {
	for (int k = 1; k <= n; k++) { // 거쳐가는 노드
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (people[i][j] > people[i][k] + people[k][j])
					people[i][j] = people[i][k] + people[k][j];
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);
	cin >> n;
	while (true) {
		int p1, p2;
		cin >> p1 >> p2;
		if (p1 == -1 && p2 == -1)break;
		people[p1][p2] = 1;
		people[p2][p1] = 1;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j)continue;
			if (people[i][j] == 0)
				people[i][j] = INF;
		}
	}
	floyd();

	// 정답 구하는게 넘 더러운데..
	int candi_num = 0;
	int min_rank = INF;
	vector<int>candi;
	for (int i = 1; i <= n; i++) {
		int rank = -INF;
		for (int j = 1; j <= n; j++) {
			if (i == j)continue;
			rank = max(rank, people[i][j]);
		}
		min_rank = min(min_rank, rank);
	}

	for (int i = 1; i <= n; i++) {
		int rank = -INF;
		for (int j = 1; j <= n; j++) {
			if (i == j)continue;
			rank = max(rank, people[i][j]);
		}
		if (min_rank == rank) {
			candi.push_back(i);
		}
	}
	cout << min_rank<<' '<< candi.size()<<endl;
	for (int i = 0; i < candi.size(); i++) {
		cout << candi[i] << ' ';
	}
	return 0;
}