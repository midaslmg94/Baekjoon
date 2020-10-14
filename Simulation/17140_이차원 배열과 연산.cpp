#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
bool cmp(pair<int, int>a, pair<int,int>b){
    if(a.second==b.second)return a.first<b.first;
    return a.second<b.second;
}
int r,c,k;
int answer;
int board[100][100];

int main(){
    //freopen("input.txt", "r", stdin);
    cin>>r>>c>>k;
    r--; c--;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cin>>board[i][j];
        }
    }
    int time = 0;
    int max_r = 3;
    int max_c = 3;
    while(time<=100){
        if(board[r][c]==k){
            break;
        }
        map<int, int>m;
        int new_board[100][100] = {0,};
        if(max_r>=max_c){// R연산
            // 숫자의 종류별로 나온 개수 저장, 정렬
            for(int i=0; i<max_r; i++){
                m.clear();
                for(int j=0; j<max_c; j++){
                    if(board[i][j]==0)continue;
                    m[board[i][j]]++;
                }
                vector<pair<int, int>>v(m.begin(), m.end());
                sort(v.begin(),v.end(),cmp);
                int idx =0;
                int k = 0;
                for(k=0; k<v.size();k++){
                    new_board[i][idx] = v[k].first;
                    new_board[i][idx+1] = v[k].second;
                    idx+=2;
                }
                max_c = max(max_c, k*2);
            }
        }
        else{
            for(int j=0; j<max_c; j++){
                m.clear();
                for(int i=0; i<max_c; i++){
                    if(board[i][j]==0)continue;
                    m[board[i][j]]++;
                }
                vector<pair<int, int>>v(m.begin(), m.end());
                sort(v.begin(),v.end(),cmp);
                int idx =0;
                int k = 0;
                for(k=0; k<v.size();k++){
                    new_board[idx][j] = v[k].first;
                    new_board[idx+1][j] = v[k].second;
                    idx+=2;
                }
                max_r = max(max_r, k*2);
            }
        }
        time++;
        for(int i=0; i<max_r; i++){
            for(int j=0; j<max_c; j++){
                board[i][j]=new_board[i][j];
            }
        }
//        for(int i=0; i<max_r; i++){
//            for(int j=0; j<max_c; j++){
//                cout<<board[i][j]<<' ';
//            }
//            cout<<endl;
//        }
    }
    if(time<=100){
        cout<<time<<endl;
        return 0;
    }
    cout<<-1<<endl;
    return 0;
}
