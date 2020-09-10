#include<bits/stdc++.h>
#define endl "\n"
#define MAX 10
using namespace std;
int n,l;
int num;
deque<pair<int, int>>dq; // 원소의 {위치, 값} 넣음 -> 왜 위치를 넣는거지?
int main() {	
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);
	cin>>n>>l;    
    for(int i=1; i<=n; i++){
        cin>>num;
        if(!dq.empty() && dq.front().first<=i-l){
            dq.pop_front();            
        }
        while (!dq.empty() && dq.back().second>num)
        {
            dq.pop_back();
        }                
        dq.push_back({i, num});                     
        cout<<dq.front().second<<' ';
    } 

	return 0;
}