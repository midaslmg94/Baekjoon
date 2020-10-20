#include<bits/stdc++.h>
#define endl "\n"
#define MAX 10
using namespace std;
int n;
vector<int>v;
int main() {	
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);
    cin>>n;
    for(int i=0; i<n; i++){
        int t; cin>>t;
        v.push_back(t);
    }

    int p1 = 0;
    int p2 = n-1;
    int answer = 200000001; // 0에 가깝다 : 절댓값이 가장 작다
    int ans_p1 = 0;
    int ans_p2 = 0;
    while(p1<p2){
        int res = v[p1] + v[p2];
        if(answer > abs(res)){
            ans_p1 = p1;
            ans_p2 = p2;            
            answer = min(answer, abs(res));
        }
        if(res<0){
            p1++; 
        }
        else if(res>0){
            p2--; 
        }
        else{
            cout<<min(v[ans_p1], v[ans_p2])<< ' '<<max(v[ans_p1], v[ans_p2]);
            return 0;
        }
    }
    cout<<min(v[ans_p1], v[ans_p2])<< ' '<<max(v[ans_p1], v[ans_p2]);
	return 0;
}

