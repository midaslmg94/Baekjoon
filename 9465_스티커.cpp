#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int t;
int n;
long long score;

vector < pair<int, int>>check_up = { {0,-1},{-1,0},{0,1} }; // ����, ����, ������ Ȯ��
vector < pair<int, int>>check_down = { {0,-1},{1,0},{0,1} }; // ����, �Ʒ���, ������ Ȯ��


vector<vector<int>>v;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < 2; i++) {
			vector<int>tmp(n);
			for (int j = 0; j < n; j++) {
				cin >> tmp[j];
			}
			v.push_back(tmp);
		}

		/*3���� ��� Ȯ���غ���*/
		int sum = 0;
		int start = 0; // 0 �Ǵ� 1�� ���� ���´�.--> 2n �迭���� ��, �Ʒ� ǥ��
		for (int i = 0; i < n; i += 3) {
			int one = max(v[start][i] + v[!start][i + 1] + v[start][i + 2], v[!start][i] + v[start][i + 1] + v[!start][i + 2]);
			int two = max(v[start][i] + v[start][i + 2], v[start][i] + v[!start][i+2]);
			int three = max(v[!start][i] + v[start][i + 2], v[!start][i] + v[!start][i + 2]);
			sum += max(one, max(two, three));
		}
		cout << sum << "\n";
		v.clear();
	}
}