#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
	int k; //���� ������ ����
	int n; // �ʿ��� ������ ����
	cin >> k >> n;
	vector<int>v;
	int t;
	for (int i = 0; i < k; i++) {
		cin >> t;
		v.push_back(t);
	}
	sort(v.begin(), v.end());
	long long left = 1;
	long long right = v[k - 1]; //�ڸ� �� �ִ� �ִ� ����
	long long ans = 0;

	while (left <= right) { 
		long long mid = (left + right) / 2; // ���� �ڸ��� ������ ����
		long long cur = 0; // ������� �ڸ� ������ ����
		for (int i = 0; i < k; i++) {
			cur += v[i] / mid;
		}
		if (cur < n) { // ������ ������ �� �ʿ��ϴٸ� 
			right = mid - 1;
		}
		else {
			left = mid + 1;
			ans = mid;
		}

	}
	cout << ans;
}