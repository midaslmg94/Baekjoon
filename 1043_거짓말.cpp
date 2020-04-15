#include<bits/stdc++.h>
#define endl "\n"
#define MAX 51
using namespace std;
int n, m;
int truthcnt;
int parent[MAX]; // 부모 배열
vector<int>truthPeople; // 초기부터 진실을 알고있던 사람
bool truth[MAX];
vector<int>party[MAX];
int num;

int Find(int n) {
	if (n != parent[n])
		return parent[n] = Find(parent[n]);
	return n;
}
void Union(int n1, int n2) {
	n1 = Find(n1);
	n2 = Find(n2);
	if (n1 != n2) {
		parent[n2] = n1;
	}
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);
	cin >> n >> m;
	cin >> truthcnt;
	int tmp;
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}
	for (int i = 0; i < truthcnt; i++) {
		cin >> tmp;
		truth[tmp] = true;
		truthPeople.push_back(tmp);
	}
	for (int i = 0; i < m; i++) {
		cin >> num;
		for (int j = 0; j < num; j++) {
			cin >> tmp;
			party[i + 1].push_back(tmp); // 같은 파티에 참여한 사람끼리 연결
		}
	}

	for (int i = 1; i <= m; i++) { // 모든 파티를 통해 알게된 사람끼리 연결
		for (int j = 0; j < party[i].size() - 1; j++) {
			Union(party[i][j], party[i][j + 1]);
		}
	}


	for (int i = 0; i < truthPeople.size(); i++) { // 진실을 알고 있는 사람과 연결되어있는 사람들도 진실을 안다.
		for (int j = 1; j <= n; j++) {
			if (Find(truthPeople[i]) == Find(j)) { // 같은 부모면 진실을 알게 된다
				truth[j] = true;
			}
		}
	}

	int answer = 0;
	for (int i = 1; i <= m; i++) { // 다시파티를 보며 진실을 아는 사람이 한명도 없는 파티에만 거짓말 가능 
		bool flag = true;
		for (int j = 0; j < party[i].size(); j++) {			
			if (truth[party[i][j]] == true) {
				flag = false;
			}
		}
		if (flag) {
			answer++;
		}
	}
	cout << answer;

	return 0;
}