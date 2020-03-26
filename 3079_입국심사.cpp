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
	long long high = arr[n - 1] * m; // �ִ�� �ɸ��� �Ա��ɻ� �ð�
	long long totalPeople = 0; // �־��� �ð��� ó���� �� �ִ� ����� ��
	while (low <= high) {
		long long mid = (low + high) / 2;
		long long totalPeople = 0;
		for (int i = 0; i < n; i++) {
			totalPeople += (mid / arr[i]); // �ð��� mid��ŭ �־����� �� ��� �ɻ�뿡�� ó���� �� �ִ� ��� ��
		}
		if (totalPeople < m) { // ó���ؾ� �� ����� �� ���Ҵ� -> ó�� �ð��� �÷��� ��
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}
	cout << low;
	return 0;
}