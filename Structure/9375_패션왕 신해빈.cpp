#include<bits/stdc++.h>
#define endl "\n"
#define MAX 10
using namespace std;
int tc, n;
int answer;
map<string, int> m;
string wearing, catagory;

int main() {	
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);
    cin>>tc;
    while (tc--)
    {
        answer = 1;
        m.clear();
        cin>>n;
        for(int i=0; i<n; i++){
            cin>>wearing>>catagory;
            m[catagory]++;        
        }
        for(auto res : m){
            answer *= (res.second+1); // 해당 카테고리에 있는 의상의 개수를 전부 곱함. 단, 해당 카테고리를 착용하지 않는 경우도 있으므로 1을 더해줌
        }
        cout<<answer-1<<endl; // 모두 안입는 경우를 제외
    }
	return 0;
}