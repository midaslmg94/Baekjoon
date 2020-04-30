#include<bits/stdc++.h>
#include <string>
#include <vector>

using namespace std;
string order;
string id;
string name;

map<string,string>user; // id, 닉네임
vector<pair<string, pair<string, string>>>order_list; // 명령어, {id, 닉네임}
vector<string> solution(vector<string> record) {
    vector<string> answer;    
    for(int i=0; i<record.size();i++){        
        stringstream ss;
        ss.str(record[i]);  
        ss>>order; ss>>id;  
        if(order!="Leave")
            ss>>name;    
        if(order=="Enter"){
            user[id] = name;
            
        }
        else if(order =="Change"){           
            user.erase(id);
            user[id]=name;
        }
        order_list.push_back({order,{id, name}});
        ss.clear();
    }
    for(auto a:user){
        //cout<<a.first<<' '<<a.second<<' '<<endl;
    }   
    
    // 명령에 따라 메시지 출력
    for(int i=0; i<order_list.size(); i++){
        if(order_list[i].first=="Change")continue;
        string str = user[order_list[i].second.first];        
        if(order_list[i].first=="Enter"){
            answer.push_back(str+"님이 들어왔습니다.");
            //cout<<str<<"님이 들어왔습니다."<<endl;
        }
        else{
             answer.push_back(str+"님이 나갔습니다.");
            //cout<<str<<"님이 나갔습니다."<<endl;
        }
    }
    return answer;
}