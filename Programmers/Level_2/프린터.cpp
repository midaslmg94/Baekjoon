#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 1;
    
    deque<pair<int, int>>dq;
    for(int i=0; i<priorities.size(); i++){
        dq.push_back({i,priorities[i]}); // idx, 우선순위
    }    
    
    while(true){
        int cur = dq[0].first;
        int cur_priority = dq[0].second;
        bool flag = false;
        for(int i=1; i<dq.size(); i++){
            if(cur_priority<dq[i].second){
                flag = true;
                break;
            }
        }
        if(flag){ // 출력 불가능
            dq.pop_front();
            dq.push_back({cur,cur_priority});
        }
        else{ // 출력 가능
            if(cur==location){
                return answer;
            }
            dq.pop_front();
            answer++;
        }
    }   
    
}