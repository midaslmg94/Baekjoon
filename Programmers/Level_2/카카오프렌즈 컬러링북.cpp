#include <bits/stdc++.h>
using namespace std;
int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};
bool visited[102][102];
vector<pair<int, int>>area;// 해당 번호가 몇개 색칠되어 있는지
int copy_row, copy_col;
int bfs(int y, int x, int idx, int m, int n, vector<vector<int>> picture){
    queue<pair<int, int>>q;
    visited[y][x] = true;
    q.push({y,x});
    int res = 1;
    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        for(int d=0; d<4; d++){
            int ny = y+dy[d];
            int nx = x+dx[d];
            if(0>ny || ny>=m || 0>nx || nx>=n) continue;
            if(visited[ny][nx] || picture[ny][nx]!=idx)continue;
            visited[ny][nx] = true;
            q.push({ny,nx});
            res++;
        }
    }
   return res;
}
vector<int> solution(int m, int n, vector<vector<int>> picture) {
   
    vector<int> answer;
    for(int i = 0 ; i <m;i++)
    {
        for(int j = 0 ; j < n; j++)
        {
            visited[i][j] = false;
        }
    }
    int number_of_area = 0;
    int max_size_of_one_area = 0; 

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(visited[i][j] || picture[i][j]==0)continue;
            int cur = bfs(i,j,picture[i][j], m, n, picture);
            if(cur > max_size_of_one_area) max_size_of_one_area = cur;
            number_of_area++;
        }
    }
    // int ret = 0;
    // for(auto a:area){
    //     ret = max(ret, a.second);
    //     cout<<a.first<<' '<<a.second<<endl;
    // }
    answer.push_back(number_of_area);
    answer.push_back(max_size_of_one_area);
    return answer;
}