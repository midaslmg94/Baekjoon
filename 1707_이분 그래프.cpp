#include<iostream>
#include<vector>
#define MAX 10001
using namespace std;

int main() {
	int n;
	cin >> n; // �׽�Ʈ ���̽��� ����	
	vector<string>ans(n); // YES or NO�� �����ϴ� ����

	for(int i=0; i<n; i++){
		
		int v, e=0; // v:������ ����, e:������ ����
		cin >> v >> e;
		vector<int>graph[MAX];
		graph->clear();
		for (int i = 0; i < e; i++) { // ���� ����
			int node1, node2;
			cin >> node1 >> node2;
			graph[node1].push_back(node2);
			graph[node2].push_back(node1);
		}
		 


	}	       
}   