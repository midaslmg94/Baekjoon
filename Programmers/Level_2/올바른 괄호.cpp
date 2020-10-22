#include <bits/stdc++.h>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    stack<char>st;
    for(int i=0; i<s.size(); i++){
        char cur = s[i];
        //cout<<cur<<endl;
        if(cur == '('){
            st.push(cur);
        }
        else{            
            if(!st.empty() && st.top() == '('){ // 이 부분에서 empty 확인을 꼭 해줘야 한다.
                st.pop();
            }
            else{
                return false;
            }
        }            
    }
    if(!st.empty()) return false;
    return true;
    
}