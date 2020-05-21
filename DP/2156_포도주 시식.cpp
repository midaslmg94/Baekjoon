// #include<iostream>
// #include<vector>
// #include<algorithm>
// using namespace std;
// int n;
// vector<int>podo;
// int dp[3][10000];
// int main() {
// 	ios::sync_with_stdio(false);
// 	cout.tie(0); cin.tie(0);
// 	freopen("input.txt", "r", stdin);
// 	cin >> n;
// 	int tmp;
// 	for (int i = 0; i < n; i++) {
// 		cin >> tmp;
// 		podo.push_back(tmp);
// 	}
// 	dp[0][0] = 0; 
// 	dp[1][0] = podo[0];
// 	dp[2][0] = 0;

// 	for (int i = 1; i < n; i++) {
// 		dp[0][i] = max(dp[0][i-1],max(dp[1][i-1],dp[2][i-1])); // ÀÌ¹ø¿¡ ¾È¸ÔÀ½ 
// 		dp[1][i] = podo[i] + dp[0][i-1]; // Ã¹¹øÂ°·Î ¸ÔÀ½
// 		dp[2][i] = podo[i] + dp[1][i-1]; // µÎ¹øÂ°·Î ¸ÔÀ½
// 	}
// 	cout << max(dp[0][n - 1],max(dp[1][n - 1], dp[2][n - 1]));
// }


#include<bits/stdc++.h>
#define MAX 10000
using namespace std;
int dp[MAX][3];
int main(){
    int n;
    cin>>n;
    vector<int>v;
    for(int i=0; i<n; i++){
        int t; cin>>t;
        v.push_back(t);
    }
    dp[0][0] = 0; 
    dp[0][1] = v[0];
    dp[0][2] = 0; 
    
    dp[1][0] = dp[0][1];
    dp[1][1] = v[1]; 
    dp[1][2] = v[0]+v[1];
    for(int i=2; i<n; i++){
        dp[i][0] = max(max(dp[i-1][0], dp[i-1][1]),dp[i-1][2]);
        dp[i][1] = max(max(dp[i-2][0],dp[i-2][1]),dp[i-2][2])+v[i];
        dp[i][2] = max(dp[i-1][0],dp[i-1][1])+v[i];
    }
    int ans = max(max(dp[n-1][0], dp[n-1][1]),dp[n-1][2]);
    cout<<ans;
}
