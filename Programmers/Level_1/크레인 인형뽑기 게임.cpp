#include <bits/stdc++.h>
// 2019 카카오 개발자 겨울 인턴십
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int>s;
    for(int m=0; m<moves.size(); m++){
        int crane = moves[m]-1; // index의 시작을 0 으로 맞추기 위함
        for(int i=0; i<board[crane].size(); i++){            
            if(board[i][crane]!=0){
                if(!s.empty() && s.top()==board[i][crane]){
                    s.pop();   
                    answer+=2; // 인형은 2개씩 터짐
                }
                else{                        
                    s.push(board[i][crane]);    
                }     
                board[i][crane]=0;
                break;
            }            
        }        
    }
    return answer;      
}