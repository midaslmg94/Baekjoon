#include<bits/stdc++.h>
#define endl "\n"
#define MAX 10
using namespace std;
int solution(vector<int> &A) {
    int res = 0;
    vector<int>v; 
    for(int i=0; i<A.size(); i++){
        v.push_back(i+1);
    }
    sort(A.begin(), A.end());
    for(int i=0; i<A.size(); i++){
        res += abs(A[i]-v[i]);
    }
    return res;
}

int main(){
    vector<int> v = {6,2,3,5,6,3};
    int ans = solution(v);
    cout<<ans;
}