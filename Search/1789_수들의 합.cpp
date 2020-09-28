#include<bits/stdc++.h>
#define endl "\n"
#define MAX 10
using namespace std;
long long s, n;
long long ans = 1;
int main() {	
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);
	cin>>s;
    long long start = 0;
    long long end = s;
    for(int i=0; i<s/2; i++){
        start++; 
        end-=start;
        if(start>=end) break;
        ans++;
    }
    cout<<ans;
	return 0;
}