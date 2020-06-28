#include <bits/stdc++.h>
#define endl "\n"
#define MAX 10
using namespace std;

int solution(string s) {
    int answer = s.size();
    for (int len = 1; len <= s.size() / 2; len++) {
        int cur = 1;
        int tmp = len;
        for (int j = 0; j < s.size()-len; j += len) { // j개씩 압축
            string s1 = s.substr(j,len); // len개의 문자 추출
            string s2 = s.substr(j+len, len); // 그 다음부터 문자 추출
            if(s1.size()!=s2.size()){ // 반복 문자열 추출 불가능 -> 남은 문자 더하기
                tmp += s2.size(); 
                break; 
            }
            if(s1==s2){
                cur++; // 반복되는 문자열의 수
            }
            else{
               if(cur==1){ 
                   tmp += s1.size();
               }
               else if(cur<10){
                   tmp += s1.size()+1;
               }
               else if(cur<100){
                   tmp += s1.size()+2;
               }
               else{
                   tmp += s1.size()+3;
               }
               cur = 1;
            }
            cout<<"s1="<<s1<<" s2="<<s2<<" cur="<<cur<<" tmp="<<tmp<<endl;
        }
        cout<<endl;
        answer = min(answer,tmp);
    }
    return answer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt", "r", stdin);
    string s;
    cin >> s;
    int ans = solution(s);
    cout << ans;
    return 0;
}