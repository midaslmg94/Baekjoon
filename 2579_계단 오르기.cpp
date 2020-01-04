#include<iostream>
#include<algorithm>
using namespace std;
int dp[301][3];
int arr[301];
int main() {
	int n;
	cin >> n;
	// 지금 계단이 이전 계단에서  1칸 올라왔는지, 2칸 올라왔는지 확인
	for (int i = n-1; i >=0; i--) {//  마지막을 무조건 밟기 위해 마지막부터 시작
		cin >> arr[i];
	}
	dp[0][0] = arr[0];

}