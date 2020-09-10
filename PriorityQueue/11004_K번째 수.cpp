#include<bits/stdc++.h>
#define endl "\n"
#define MAX 10
using namespace std;
int n,k;
priority_queue<int>pq;
int main() {	
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);
	cin>>n>>k;
    int num;
    for(int i=0; i<n; i++){
        cin>>num;
        pq.push(-num);
    }
    for(int i=0; i<k-1; i++){
        pq.pop();
    }
    cout<<-pq.top();
	return 0;
}