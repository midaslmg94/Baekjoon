#include<iostream>
#include<algorithm>
using namespace std;
int dp[301][3];
int arr[301];
int main() {
	int n;
	cin >> n;
	// ���� ����� ���� ��ܿ���  1ĭ �ö�Դ���, 2ĭ �ö�Դ��� Ȯ��
	for (int i = n-1; i >=0; i--) {//  �������� ������ ��� ���� ���������� ����
		cin >> arr[i];
	}
	dp[0][0] = arr[0];

}