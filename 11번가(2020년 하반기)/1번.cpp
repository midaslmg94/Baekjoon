#include<bits/stdc++.h>
#define endl "\n"
#define MAX 10
using namespace std;
int solution(string &S) {
    // write your code in C++14 (g++ 6.2.0)
    cout<<S<<endl;
    int answer=0; 
    string tmp = "aa";
    if(S[0]!='a'){
        answer+=2;
        S = tmp+S;
    }
    cout<<"앞 "<<S<<endl;
    if(S[S.size()-1]!='a'){
        answer+=2;
        strcat(S, "aa");
        S = S+tmp;
        
    }
    cout<<"뒤 "<<S<<endl;
    for(int i=1; i<S.size()-1; i++){
        string str = S.substr(i,3);
        if(str=="aaa"){
            return 0;
            break;
        }
        
    }
    return answer;
}

int main(){
    string s;
    s="babab";
    int a = solution(s);
}

