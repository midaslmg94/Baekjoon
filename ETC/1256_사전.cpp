#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n, m, k; // n개의 'a', m개의 'z'

/*

nCr = n-1Cr + n-1Cr-1
*/

long long arr[101][101];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);	cout.tie();
	freopen("input.txt", "r", stdin);
	cin >> n >> m >> k;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			if (i == 0 || j == 0) {
				if (i == 0 && j == 0) {
					arr[i][j] = 0;
					continue;
				}
				arr[i][j] = 1; continue;
			}
			arr[i][j] = arr[i - 1][j] + arr[i][j - 1];
		}
	}

	if (k > arr[n][m]) {
		cout << -1;
		exit(0);
	}


	/*vector<char>v;
	for (int i = 0; i < n; i++) {
		v.push_back('a');
	}
	for (int i = 0; i < m; i++) {
		v.push_back('z');
	}
	int cnt = 1;
	do {
		for (int i = 0; i < v.size(); i++)
			cout << v[i];
		cout << "개수" << cnt<<endl;
		cnt++;
	} while (next_permutation(v.begin(), v.end()));*/

}