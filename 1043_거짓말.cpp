#include<bits/stdc++.h>
#define endl "\n"
#define MAX 51
using namespace std;
int n, m;
int truthcnt;
int parent[MAX]; // �θ� �迭
vector<int>truthPeople; // �ʱ���� ������ �˰��ִ� ���
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
			party[i + 1].push_back(tmp); // ���� ��Ƽ�� ������ ������� ����
		}
	}

	for (int i = 1; i <= m; i++) { // ��� ��Ƽ�� ���� �˰Ե� ������� ����
		for (int j = 0; j < party[i].size() - 1; j++) {
			Union(party[i][j], party[i][j + 1]);
		}
	}


	for (int i = 0; i < truthPeople.size(); i++) { // ������ �˰� �ִ� ����� ����Ǿ��ִ� ����鵵 ������ �ȴ�.
		for (int j = 1; j <= n; j++) {
			if (Find(truthPeople[i]) == Find(j)) { // ���� �θ�� ������ �˰� �ȴ�
				truth[j] = true;
			}
		}
	}

	int answer = 0;
	for (int i = 1; i <= m; i++) { // �ٽ���Ƽ�� ���� ������ �ƴ� ����� �Ѹ� ���� ��Ƽ���� ������ ���� 
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