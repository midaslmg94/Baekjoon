#include <bits/stdc++.h>
#define endl "\n"
#define MAX 10
using namespace std;
int n;
vector<int>num;
//int oper[4] = {0,1,2,3}; // 순서대로 + - * /
vector<int>oper;
int calc(int x, int y, int oper){
    if(oper==0)return x+y;
    if(oper==1)return x-y;
    if(oper==2)return x*y;
    if(oper==3)return x/y;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt", "r", stdin);
    cin>>n;
    for(int i=0; i<n; i++){
        int tmp; cin>>tmp;
        num.push_back(tmp);
    }
    for(int i=0; i<4; i++){
        int tmp; cin>>tmp;
        for(int j=0; j<tmp; j++){
            oper.push_back(i); // 연산자의 개수 만큼 
        }
    }
    // 연산의 순서 구하기
    do
    {
        for(int i=0; i<oper.size(); i++){
            cout<<oper[i]<<' ';
        }
        cout<<endl;
    } while (next_permutation(oper.begin(), oper.end()));
    
    
    return 0;
}