#include <bits/stdc++.h>
#define endl "\n"
#define MAX 1001
using namespace std;
int n, s, m;
int vol_diff[MAX];
bool dp[101][MAX];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt", "r", stdin);
    cin >> n >> s >> m;
    for (int i = 1; i <= n; i++) cin >> vol_diff[i];
    memset(dp,false,sizeof(dp));
	dp[0][s] = true;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (dp[i - 1][j]) {                   // 이전에 연주한 볼륨
                int upper_vol = j + vol_diff[i];  // 볼륨  up
                int lower_vol = j - vol_diff[i];  // 볼륨 down
				//cout<<" up:"<<upper_vol<<" low: "<<lower_vol<<endl;
                if (upper_vol <= m) dp[i][upper_vol] = true;
                if (lower_vol >= 0) dp[i][lower_vol] = true;
            }
        }
    }

	// for(int i=1; i<=n; i++){
	// 	for(int j=1; j<=m; j++){
	// 		cout<<dp[i][j]<<' ';
	// 	}
	// 	cout<<endl;
	// }
    for (int i = m; i >= 0; i--) {
        if (dp[n][i]) {
            cout << i;
            return 0;
        }
    }
    cout << -1;
    return 0;
}
