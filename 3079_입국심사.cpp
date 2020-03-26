#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<deque>
#include<string.h>
#define endl "\n"
#define MAX 100000
using namespace std;
int n, m;
long long arr[MAX];
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];			
	}		
	long long low = 1;
	long long high = arr[n - 1] * m; // 최대로 걸리는 입국심사 시간
	long long totalPeople = 0; // 주어진 시간에 처리할 수 있는 사람의 수
	while (low <= high) {
		long long mid = (low + high) / 2;
		long long totalPeople = 0;
		for (int i = 0; i < n; i++) {
			totalPeople += (mid / arr[i]); // 시간이 mid만큼 주어졌을 때 모든 심사대에서 처리할 수 있는 사람 수
		}
		if (totalPeople < m) { // 처리해야 될 사람이 더 남았다 -> 처리 시간을 늘려야 함
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}
	cout << low;
	return 0;
}