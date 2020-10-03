#include<bits/stdc++.h>
#define endl "\n"
#define MAX 10
using namespace std;
int n, tmp, idx_left, idx_right;
int sum = 2000000000;
vector<int>v;
bool cmp(int a, int b){
    return abs(a) < abs(b);
}
int main() {	
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>tmp;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end(), cmp); // 절댓값을 기준으로 정렬
    
    for(int i=0; i<n-1; i++){
        int res = v[i]+v[i+1];
        if(abs(res)<abs(sum)){
            sum = res;
            idx_left=v[i];
            idx_right=v[i+1];
        }
    } 
    if(idx_left>idx_right){
        swap(idx_left, idx_right);
    }
    cout<<idx_left<<' '<<idx_right;

	return 0;
}