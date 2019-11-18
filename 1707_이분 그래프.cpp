#include<iostream>
#include<vector>
#define MAX 20001
using namespace std;
bool visited[MAX];
int color[MAX] = { 0, }; // ������ 2���� ������ ǥ��(1�� 2)  
vector<int>graph[MAX];
vector<string>ans; // YES or NO�� �����ϴ� ����
bool flag;


void dfs(int idx) {
	visited[idx] = true;
	if (color[idx] == 0) { // ���� ó�� �湮�� ����
		color[idx] = 1;
	}
	for (int i = 0; i < graph[idx].size(); i++) {
		int next = graph[idx][i];
		if (color[idx] == color[next]) { // ���� ������ ĥ�ϰ� �Ǹ� ���̻� �̺� �׷����� �ƴ�
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
	cin >> n; // �׽�Ʈ ���̽��� ����, �׽�Ʈ ���̽��� �̷��� �Ǿ������� �ʱ�ȭ�� �߿��ߴ� ����

	for(int i=0; i<n; i++){		
		int v, e=0; // v:������ ����, e:������ ����
		cin >> v >> e;		
		flag = true;		
		for (int j = 0; j < MAX; j++) { // �ʱ�ȭ�� ��������.. visited�� �ʱ�ȭ ���߾ Ʋ�� 
				graph[j].clear();
				visited[j] = 0;
				color[j]=0;
		}	
		for (int j = 0; j < e; j++) { // ���� ����
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