#include<iostream>
#include<vector>
#define MAX 20001
using namespace std;
bool visited[MAX];
int color[MAX] = { 0, }; // 정점을 2가지 색으로 표현(1과 2)  
vector<int>graph[MAX];
vector<string>ans; // YES or NO를 저장하는 벡터
bool flag;


void dfs(int idx) {
	visited[idx] = true;
	if (color[idx] == 0) { // 정말 처음 방문한 정점
		color[idx] = 1;
	}
	for (int i = 0; i < graph[idx].size(); i++) {
		int next = graph[idx][i];
		if (color[idx] == color[next]) { // 같은 색으로 칠하게 되면 더이상 이분 그래프가 아님
			flag = false;
			return;
		}
		else if (color[idx] == 1 && color[next]==0) {
			color[next] = 2;
		}
		else if (color[idx] == 2 && color[next]==0) {
			color[next] = 1;
		}
		if (!visited[next]) {
			dfs(next);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n; // 테스트 케이스의 개수, 테스트 케이스가 이렇게 되어있으니 초기화가 중요했던 문제

	for(int i=0; i<n; i++){		
		int v, e=0; // v:정점의 개수, e:간선의 개수
		cin >> v >> e;		
		flag = true;		
		for (int j = 0; j < MAX; j++) { // 초기화를 잘해주자.. visited를 초기화 안했어서 틀림 
				graph[j].clear();
				visited[j] = 0;
				color[j]=0;
		}	
		for (int j = 0; j < e; j++) { // 간선 연결
			int node1, node2;
			cin >> node1 >> node2;
			graph[node1].push_back(node2);
			graph[node2].push_back(node1);
		}
		for (int j = 1; j <= v; j++) {
			if (!visited[j]) {
				if (!flag) { 
					break; 
				}
				dfs(j);
			}
		}
		if (flag) {
			ans.push_back("YES");
		}
		else {
			ans.push_back("NO");
		}
	}
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i]<<endl;
	}
}   