#include<iostream>
#include<vector>
#define MAX 10001
using namespace std;

int main() {
	int n;
	cin >> n; // 테스트 케이스의 개수	
	vector<string>ans(n); // YES or NO를 저장하는 벡터

	for(int i=0; i<n; i++){
		
		int v, e=0; // v:정점의 개수, e:간선의 개수
		cin >> v >> e;
		vector<int>graph[MAX];
		graph->clear();
		for (int i = 0; i < e; i++) { // 정점 연결
			int node1, node2;
			cin >> node1 >> node2;
			graph[node1].push_back(node2);
			graph[node2].push_back(node1);
		}
		 


	}	       
}   