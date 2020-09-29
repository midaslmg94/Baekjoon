#include<bits/stdc++.h>
#define endl "\n"
#define MAX 10
using namespace std;
bool cmp(vector<pair<int, pair<int, int>>>v1, vector<pair<int, pair<int, int>>>v2){
    return v1.front().first
}
vector<pair<int, pair<int, int>>>v;
vector<int> solution(vector<string> &S) {
    // write your code in C++14 (g++ 6.2.0)
  vector<int>answer;
  for(int i=0; i<S.size(); i++){
    string str = S[i];
    for(int j=0; j<str.size(); j++){
        int alpha_num = str[j]-'a';
        v.push_back({j, {i,alpha_num}}); // i번째 문자열의 j번째 인덱스가 가진 문자
    }
  }
  for(int i=0; i<v.size(); i++){

      cout<<v[i].first<<' ' << v[i].second.first<<' '<<v[i].second.second<<endl;
  }
  
}

int main(){
    vector<string> v;
    v = {"zzzz", "ferz", "zdsr", "fgtd"};
    solution(v);
}


