#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;
struct INFO{
    int y;
    int x;
    int cnt;
    int card;
};
int solution(vector<vector<int>> board, int r, int c) {
    int answer = 0;
    queue<INFO>q;
    q.push({r,c,0,board[r][c]});
    


    return answer;
}

int main() {
    ios::sync_with_stdio(false);
    vector<int> numbers;
    vector<vector<int>>board = {{3,0,0,2},{0,0,1,0},{0,1,0,0},{2,0,0,3}};
    cout<<solution(board,0,1);    
    return 0;
}