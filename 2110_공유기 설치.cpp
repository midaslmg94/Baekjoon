#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
/*
	�̺� Ž�� - �Ķ��Ʈ�� ��ġ
*/
int n, c;
vector<int>home;

bool possible(int dist) {
	int cnt = 1; //�������� ����
	int prev = home[0];
	for (int i = 1; i < n; i++) {
		if (home[i] - prev >= dist) {// ��ġ ����
			cnt++;
			prev = home[i];
		}
	}
	if (cnt >= c) {// �����⸦ �ʿ䷮ ���� �� ���� ��ġ��
		return true;
	}
	return false;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);

	cin >> n >> c; // ���ǰ���, �������� ����
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		home.push_back(tmp);
	}
	sort(home.begin(), home.end());

	// �ּ� �Ÿ� , �ִ� �Ÿ�
	int left = 1, right = home[n - 1] - home[0]; 
	int result = 0;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (possible(mid)) {
			result = max(result, mid);
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}

	}
	cout << result;
}