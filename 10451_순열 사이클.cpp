#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<int>graph[1001];
bool visited[1001];
int arr[1001];
int cnt = 0;	
int ans = 0;
int dfs(int idx) {
	if (graph[idx][0] == idx) { // ������ ���
		visited[idx] = true;
		cnt++;
		return cnt;
	}
	int next = graph[idx][0];
	if (!visited[next]) {	
		visited[next] = true;
		cnt++;
		dfs(next);
		cnt = cnt / cnt;
		return cnt;
	}
	return 0;
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		int size;
		cin >> size;
		int n;
		for (int i = 1; i <= size; i++) {
			cin >> n;
			graph[i].push_back(n);
		}
		for (int i = 1; i <= size; i++) {
			int tmp = dfs(i);
			ans += tmp;
			cnt = 0;
		}
		cout << ans <<endl;

		// �ʱ�ȭ 
		for (int i = 1; i <= size; i++) {
			visited[i] = false;
			graph[i].clear();
			
		}
		cnt = 0;
		ans = 0;
	}
}