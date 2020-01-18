#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int t;
int n;
long long score;

vector < pair<int, int>>check_up = { {0,-1},{-1,0},{0,1} }; // 왼쪽, 위쪽, 오른쪽 확인
vector < pair<int, int>>check_down = { {0,-1},{1,0},{0,1} }; // 왼쪽, 아래쪽, 오른쪽 확인


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

		/*3개씩 묶어서 확인해보자*/
		int sum = 0;
		int start = 0; // 0 또는 1의 값을 갖는다.--> 2n 배열에서 위, 아래 표시
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