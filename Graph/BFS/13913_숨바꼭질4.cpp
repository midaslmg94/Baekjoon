#include<bits/stdc++.h>
#define endl "\n"
#define MAX 100000+1
using namespace std;

int arr[MAX];
bool visited[MAX];
int move_time[3] = {1,1,1}; // x*2, x-1, x+1,  로 이동하는데 걸리는 시간
int answer = 0;
int n,k;
void bfs(int start)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;    
    pq.push({0,start});// 걸린 시간, 현재 위치
    arr[start] = 0;
    visited[start] = true;
    while (!pq.empty())
    {
        int t = pq.top().first;
        int pos = pq.top().second;
        pq.pop();
        if(pos==k){
            answer = t;
            return;
        }
        for(int i=0; i<3; i++){
            int next_time = t + move_time[i];
            int next_pos=0;
            if(i==0) next_pos = pos*2;
            if(i==1) next_pos = pos-1;
            if(i==2) next_pos = pos+1;
            if(next_pos<0 || next_pos >MAX || arr[next_pos]!=-1)continue; // 범위 초과 및 재방문 확인
            if(next_pos==k){
                answer = next_time;
                return;
            }
            pq.push({next_time,next_pos});
            arr[next_pos] = next_time;
            cout<<"pos:"<<next_pos<<" time:"<<next_time<<endl;
        }
    }
    
}
int main() {	
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);
	cin>>n>>k;
    for(int i=0; i<MAX; i++){
        arr[i]=-1;
    }
    bfs(n);
    cout<<answer;
	return 0;
}