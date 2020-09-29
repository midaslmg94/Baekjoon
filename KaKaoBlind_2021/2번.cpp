#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;
// 정답은 각 코스요리 메뉴의 구성을 문자열 형식으로 배열에 담아 사전 순으로 오름차순 정렬해서 return 해주세요
// 만약 가장 많이 함께 주문된 메뉴 구성이 여러 개라면, 모두 배열에 담아 return 하면 됩니다.

vector<string> answer;
vector<char>v;
bool visited[21];
void go(int idx, int length, int cnt){ // 해당 개수의 요리로 만들 수 있는 코스요리
    if(length==cnt){
        return;
    }
    
}
vector<string> solution(vector<string> orders, vector<int> course) {
    for(int i=0; i<course.size(); i++){
        go(0,0,course[i]);
        v.clear();
    }


    sort(answer.begin(), answer.end());
    return answer;
}

int main() {
    ios::sync_with_stdio(false);
    vector<string>orders;
    orders={"ABCFG","AC","CDE","ACDE","BCFG","ACDEH"};
    vector<int>course;    
    course={2,3,4}; // 코스요리 개수

    vector<string> ans = solution(orders, course);    
    for(auto a:ans){
        cout<<a<<' ';
    }
    // ["AC", "ACDE", "BCFG", "CDE"] : 사전 순 정렬
    return 0;
}