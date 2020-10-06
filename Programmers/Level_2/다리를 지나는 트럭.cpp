#include <bits/stdc++.h>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    queue<int>q; // 다리에 올라간 트럭
    queue<int>truck; // 대기중인 트럭을 큐에 새롭게 저장
    for(int i=0; i<truck_weights.size(); i++){
        truck.push(truck_weights[i]);
    }
    int cur_weight = 0;
    while(true){  
        if(truck.empty()){ // 마지막 대기중인 트럭까지 다리에 올라옴  
            answer+=bridge_length; // 마지막 트럭이 지나감 
            break; 
        }      
        int next_truck = truck.front();        
        if(q.size()==bridge_length){ // 새롭게 트럭이 못 올라감.  
        /* 이 조건문 때문에 계속 틀림 !!!! */      
        //if(cur_weight + next_truck > weight){ // 새롭게 트럭이 못 올라감.   
            cur_weight -= q.front(); // 다리의 맨 앞 트럭 제거            
            q.pop();
        }
        if(cur_weight + next_truck <= weight){ // 다리의 맨 앞 트럭이 나가고, 다리에 새로운 트럭이 한 대 더 올라갈 수 있음
            q.push(next_truck);
            cur_weight += next_truck; // 새로운 트럭 추가
            truck.pop(); 
        }
        else{ // 그래도 다리에 트럭이 못 올라감
            q.push(0);   
        }            
        answer++;
    }      
    return answer;
}