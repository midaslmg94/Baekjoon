#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;
/*
info 배열의 크기는 1 이상 50,000 이하입니다.
query 배열의 크기는 1 이상 100,000 이하입니다.

개발언어는 cpp, java, python 중 하나입니다.
직군은 backend, frontend 중 하나입니다.
경력은 junior, senior 중 하나입니다.
소울푸드는 chicken, pizza 중 하나입니다.

 
*/

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;

    for(int i=0; i<query.size(); i++){
        int cnt = 0; // 해당 조건을 만족하는 사람
        vector<string>new_query;
        stringstream ss;
        string str = query[i];
        ss.str(query[i]);
        int idx = -1;
        /*
        {"java backend junior pizza 150",
        "python frontend senior chicken 210",
        "python frontend senior chicken 150",
        "cpp backend senior pizza 260",
        "java backend junior chicken 80",
        "python backend senior chicken 50"};
*/
        while(ss>>str){            
            if(str=="-" || str=="and")continue;
            idx++;            
            if(str=="java" || str=="python" || str=="cpp"){

            }
            if(str=="backend" || str=="frontend"){

            }
            if(str=="junior" || str =="senior"){

            }
            if(str=="pizza" || str=="chicken"){

            }
            
        }

        cout<<endl;
        answer.push_back(cnt);
    }

    return answer;
}

int main() {
    ios::sync_with_stdio(false);
    
    vector<string> info = {"java backend junior pizza 150",
                           "python frontend senior chicken 210",
                           "python frontend senior chicken 150",
                           "cpp backend senior pizza 260",
                           "java backend junior chicken 80",
                           "python backend senior chicken 50"};

    vector<string> query = {"java and backend and junior and pizza 100",
                            "python and frontend and senior and chicken 200",
                            "cpp and - and senior and pizza 250",
                            "- and backend and senior and - 150",
                            "- and - and - and chicken 100",
                            "- and - and - and - 150"};
    vector<int> ans = solution(info, query);
    for(auto a:ans){
        cout<<a<<' ';
    }
    // 1 1 1 1 2 4
    return 0;
}
