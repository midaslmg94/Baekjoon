#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	// 1부터 n까지 자연수 중에서 중복 없이 M개를 고른 수열
	vector<int>v(n);
	vector<int>choice(n);
	for (int i = 0; i < n; i++) {
		v[i]=i+1;
		choice[i]=0;
	}
	sort(v.begin(), v.end());
	// 4개중 2개면 choice = {0,0,1,1}
	for (int i = n-1; i >= n-m; i--) {
		choice[i] = 1;
	}
	// 이렇게 하면 한번 선택된 원소는 제외된다
	do {
		for (int i = 0; i < n; i++) {
			if (choice[i] == 1) {
				cout << v[i] << ' ';
			}
		}
		cout << endl;
	} while (next_permutation(choice.begin(), choice.end()));	
}