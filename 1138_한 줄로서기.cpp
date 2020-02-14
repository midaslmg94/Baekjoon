#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n;
vector<int>order; // 자기보다 키가 큰 사람이 왼쪽에 몇 명이 있었는 지
int arr[10];
vector<int>v;

void sol(vector<int>candi) {
	int tmp[10];
	for (int i = 0; i < n; i++) {
		int count = 0;
		int j = 0;
		for (j = 0; j <= i; j++) {
			if (candi[i] < candi[j]) {
				count++;
			}
		}
		tmp[candi[i]-1] = count;
	}
	for (int i = 0; i < v.size(); i++) {
		if (arr[i] != tmp[i]) { // 일치하지 않음
			return;
		}		
	}
	for (int i = 0; i < candi.size(); i++) {
		cout << candi[i] << ' ';
	}
	exit(0);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);	cout.tie();
	freopen("input.txt", "r", stdin);
	cin >> n;
	int tmp;	
	for (int i = 0; i < n; i++) {
		cin >>arr[i];
		v.push_back(i+1);
	}
	do {
		vector<int>candi;
		for (int i = 0; i < n; i++) {
			candi.push_back(v[i]);
		}
		sol(candi);
	} while (next_permutation(v.begin(), v.end()));
}