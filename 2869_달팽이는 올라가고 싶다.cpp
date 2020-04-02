#include<bits/stdc++.h>
#define endl "\n"
#define MAX 1000000000
using namespace std;
long long a, b, v;
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);
	cin >> a >> b >> v; // v��ŭ�� ������ ������ �ö󰡴µ� ���� a��ŭ �ö󰡰�, b��ŭ ������ 
	long long dist = a - b; // �����̰� �Ϸ翡 ������ �� �ִ� �Ÿ�
	long long left = 1;
	long long right = MAX;
	long long result = 0;
	while (left <= right) {
		long long mid = (left + right) / 2; // mid�� ���� �ö� �� �ִ���		
		long long len = 0; // mid�ϸ�ŭ ������ �� �ö󰡴� �Ÿ�
		len = dist * (mid - 1); // ���������� a��ŭ �ö󰡴� �͸� ������
		len += a;
		if (len < v) { // �� ���� ��¥�� �ʿ���
			left = mid + 1;
		}
		else {
			result = mid;
			right = mid - 1;
		}
	}
	cout << result;
}