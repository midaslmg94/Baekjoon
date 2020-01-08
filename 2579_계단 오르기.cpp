#include<iostream>
#include<algorithm>
using namespace std;
int dp[301];
int arr[301];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	/*
		1. ���� �ִ� ��� ������ ����� ���� ���
		2. ���� �ִ� ��� ������ ����� ���� ���� ���
	*/
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	dp[1] = arr[1];
	dp[2] = arr[1] + arr[2];
	// dp[3] = max(1�� + 3�� or 2�� + 3��)
	dp[3] = max(arr[1]+arr[3], arr[2]+arr[3]);

	/*
		1. dp[i-2] �� ���ϴ� ��� : ������ ���� 3ĭ�� ���ü� �����Ƿ� ���� ��ġ�� ���ϸ� �ȴ�.
		2. dp[i-3]+arr[i-1]�� ���ϴ� ��� : dp[i-1]+arr[i]�� �ϸ� ���� 3ĭ�̴�.  ����ĭ(arr[i-1])�� ��� ������ ���� 3ĭ�̸� �ȵǱ� ������ dp[i-3]�� ���ش�
		
	*/
	for (int i = 4; i <= n; i++){
		dp[i] = max(arr[i]+dp[i-2], arr[i]+dp[i-3]+arr[i-1]);
	}
	cout << dp[n];
}