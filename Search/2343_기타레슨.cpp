#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#define MAX 100000
using namespace std;
int n, m;
int lesson[MAX];
int result = 0;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);
	
	cin >> n >> m;
	int sum = 0;
	int max_value = 0;
	for (int i = 0; i < n; i++) {
		cin >> lesson[i];
		sum += lesson[i];
		max_value = max(max_value, lesson[i]);
	}
	int left = max_value; // 왜지???
	int right = sum;
	int mid = 0;
	while (left <= right) {
		mid = (left + right) / 2; // 최대 녹화 길이
		int cur_disk = 0; // 현재 저장되는 블루레이의 길이
		int cnt = 0; // 녹화되는 블루레이의 개수
		for (int i = 0; i < n; i++) {
			if (cur_disk + lesson[i] > mid) {
				cur_disk = 0;
				cnt++;
			}
			cur_disk += lesson[i];
		}		
		if (cur_disk != 0)cnt++; // 마지막에 들어가는 cd를 한개 더 추가??
		
		if (cnt>m) { // 블루레이의 길이가 더 길어져도 된다
			left = mid + 1;
		}
		else { // 블루레이의 길이가 짧아져야 한다
			right = mid - 1;
		}		
	}
	cout << left << endl;
	return 0;
}