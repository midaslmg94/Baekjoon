#include<bits/stdc++.h>
#define INF 1e9
using namespace std;

// 교차로 개수 N, 골목 개수 M, 시작 교차로 번호 A, 도착 교차로 번호 B, 가진 돈 C 

vector<pair<int, int>>Map[11]; // first : 다음에 갈 교차로의 번호, second : 해당 교차로로 가는데 드는 비용
pair<int, int> answer;
bool visited[11] = {false,};
int n,m,a,b,c;

void dfs(int start, int cost, int shame){
	if(start == b) { // 목적지에 도착

	}
	for(int i=0; i<Map[start].size(); i++){
		int next = Map[start][i].first;

	}
}

int main(){
	freopen("input.txt", "r", stdin);
	cin>>n>>m>>a>>b>>c;
	for(int i=0; i<m; i++){
		int s,e,cost;
		cin>>s>>e>>cost;
		Map[s].push_back({e, cost});
	}
	answer.first = INF;
	answer.second = INF;


}