#include <bits/stdc++.h>
using namespace std;
/*
1단계 new_id의 모든 대문자를 대응되는 소문자로 치환합니다.
2단계 new_id에서 알파벳 소문자, 숫자, 빼기(-), 밑줄(_), 마침표(.)를 제외한 모든 문자를 제거합니다.
3단계 new_id에서 마침표(.)가 2번 이상 연속된 부분을 하나의 마침표(.)로 치환합니다.
4단계 new_id에서 마침표(.)가 처음이나 끝에 위치한다면 제거합니다.
5단계 new_id가 빈 문자열이라면, new_id에 "a"를 대입합니다.
6단계 new_id의 길이가 16자 이상이면, new_id의 첫 15개의 문자를 제외한 나머지 문자들을 모두 제거합니다.
     만약 제거 후 마침표(.)가 new_id의 끝에 위치한다면 끝에 위치한 마침표(.) 문자를 제거합니다.
7단계 new_id의 길이가 2자 이하라면, new_id의 마지막 문자를 new_id의 길이가 3이 될 때까지 반복해서 끝에 붙입니다.
*/
string solution(string new_id) {
    string answer = "";
    string id=new_id;
    // 1단계 new_id의 모든 대문자를 대응되는 소문자로 치환합니다.
    transform(id.begin(), id.end(),id.begin(), ::tolower);
    // 2단계 new_id에서 알파벳 소문자, 숫자, 빼기(-), 밑줄(_), 마침표(.)를 제외한 모든 문자를 제거합니다.
    for(int i=0; i<id.size(); i++){
        if(id[i]=='-' || id[i]=='_'||id[i]=='.')continue;
        if(0<=id[i]-'a' && id[i]-'z'<=0) continue;
        if(0<=id[i]-'0' && id[i]-'9'<=0)continue;
        id[i]=' ';        
    }
    id.erase(remove(id.begin(), id.end(), ' '),id.end()); // 공백제거
    // 3단계 new_id에서 마침표(.)가 2번 이상 연속된 부분을 하나의 마침표(.)로 치환합니다.
    for(int i=0; i<id.size()-1; i++){
        if(id[i]=='.' && id[i+1]=='.') id[i]=' ';
    }
    id.erase(remove(id.begin(), id.end(), ' '),id.end()); // 공백제거
    // 4단계 new_id에서 마침표(.)가 처음이나 끝에 위치한다면 제거합니다.
    while (true)
    {
        if(id[0]=='.') id[0]=' ';
        if(id[id.size()-1]=='.') id[id.size()-1]=' ';
        else break;
        id.erase(remove(id.begin(), id.end(), ' '),id.end()); // 공백제거        
    }
    id.erase(remove(id.begin(), id.end(), ' '),id.end()); // 공백제거        
    // 5단계 new_id가 빈 문자열이라면, new_id에 "a"를 대입합니다.
    if(id.size()==0){
        id="a";    
    }
    // 6단계 new_id의 길이가 16자 이상이면, new_id의 첫 15개의 문자를 제외한 나머지 문자들을 모두 제거합니다.
    if(id.size()>=16){
        id = id.substr(0, 16);
    }
    //      만약 제거 후 마침표(.)가 new_id의 끝에 위치한다면 끝에 위치한 마침표(.) 문자를 제거합니다.
    if(id[id.size()-1] =='.'){
        id[id.size()-1]=' ';
        id.erase(remove(id.begin(), id.end(), ' '),id.end()); // 공백제거
    }

    // 7단계 new_id의 길이가 2자 이하라면, new_id의 마지막 문자를 new_id의 길이가 3이 될 때까지 반복해서 끝에 붙입니다.
    while(id.size()<=2){
        char c = id[id.size()-1];        
        id.push_back(c);        
    }
    cout<<id;      
    
    return id;
}

int main() {
    ios::sync_with_stdio(false);
    string id = "=.=";
    string ans = solution(id);
    //cout << ans;
    return 0;
}

/*
테스트 1 〉	통과 (0.02ms, 3.77MB)
테스트 2 〉	통과 (0.02ms, 3.95MB)
테스트 3 〉	통과 (0.02ms, 3.96MB)
테스트 4 〉	통과 (0.02ms, 3.96MB)
테스트 5 〉	통과 (0.02ms, 3.96MB)
테스트 6 〉	통과 (0.02ms, 3.94MB)
테스트 7 〉	통과 (0.02ms, 3.96MB)
테스트 8 〉	통과 (0.02ms, 3.96MB)
테스트 9 〉	통과 (0.02ms, 3.89MB)
테스트 10 〉	통과 (0.01ms, 3.96MB)
테스트 11 〉	통과 (0.02ms, 3.96MB)
테스트 12 〉	통과 (0.02ms, 3.94MB)
테스트 13 〉	통과 (0.02ms, 3.95MB)
테스트 14 〉	
테스트 15 〉	통과 (0.02ms, 3.96MB)
테스트 16 〉	통과 (0.02ms, 3.96MB)
테스트 17 〉	통과 (0.03ms, 3.95MB)
테스트 18 〉	통과 (0.03ms, 3.96MB)
테스트 19 〉	통과 (0.04ms, 3.97MB)
테스트 20 〉	통과 (0.03ms, 3.96MB)
테스트 21 〉	통과 (0.04ms, 3.72MB)
테스트 22 〉	통과 (0.03ms, 3.96MB)
테스트 23 〉	통과 (0.02ms, 3.96MB)
테스트 24 〉	통과 (0.03ms, 3.96MB)
테스트 25 〉	통과 (0.03ms, 3.95MB)
테스트 26 〉	통과 (0.02ms, 3.64MB)
*/
