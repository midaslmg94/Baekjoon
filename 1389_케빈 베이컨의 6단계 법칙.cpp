#include<iostream>
#include<queue>
#include<vector>
#include<string.h>
#include<algorithm>
#define pii pair<int,int> 
#define MAX 100+1
using namespace std;
int n, m;
int map[MAX][MAX];
bool visit[MAX];
int num[MAX];
priority_queue<pii, vector<pii>, greater<pii>> pq;

void bfs(int start){ // start에서 시작하는 케빈 베이컨 수 찾기
	queue<int>q;
	q.push(start);
	visit[start]= true;
	while (!q.empty()) {
		int cur = q.front();		
		q.pop();
		for (int i = 1; i <= n; i++) { // 바로 이어져있는 친구찾기
			if (map[cur][i] == 1 && !visit[i]) {
				num[i] = num[cur] + 1; //??
				visit[i] = true;				
				q.push(i);           
			}
		}		
	}
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		sum += num[i];
	}
	pq.push({ sum,start});

}
int main() { 
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);
	cin >> n >> m;	
	int f1; int f2;
	for (int i = 0; i < m; i++) {
		cin >> f1 >> f2;
		map[f1][f2] = 1;
		map[f2][f1] = 1;
	}
	for(int i=1; i<=n;i++){
		memset(visit, false, sizeof(visit));		
		memset(num, 0, sizeof(num));
		bfs(i);
	}
	for (int i = 1; i <= n; i++) {
		cout << pq.top().first<< ' '<< pq.top().second << ' ';
		pq.pop();
		cout << endl;		
	}
	
}