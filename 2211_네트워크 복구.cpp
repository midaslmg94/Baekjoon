#include<iostream>
#include<vector>
#include<queue>
#include<string>
/*  dijkstra 적용해서 풀어보자*/
const int MAX =1001;
const int INF = 987654321;
using namespace std;
vector<pair<int, int>> graph[MAX];

class PQ { // priority queue의 사용자 자료형을 정의
public:
	int n; 
	int cost; 
	PQ(int n, int cost) {
		this->n = n;
		this->cost = cost;
	}
	bool operator>(const PQ& a) {
		return this->cost > a.cost;
	}
};
priority_queue<PQ, vector<PQ>, greater<>> pq;  // priority queue의 자료형은 PQ, push할때 PQ를 써주자
int dist[MAX];
int connect[MAX];
int connectCnt = 0;
void dijkstra() { // 다익스트라 구현.. 이전에 했던것과 같은데 까먹음
	pq.push(PQ(1,0)); // priority queue의 자료형이 PQ이므로 PQ로 맞춰주자
	dist[1] = 0;
	while (!pq.empty()) {
		int n = pq.top().n;
		int cost = pq.top().cost;
		pq.pop();
		if (dist[n] < cost) {
			continue;
		}
		for (int i = 0; i < graph[n].size(); i++) {
			int next = graph[n][i].first; // graph[i][n]이 아니라, graph[n][i]
			int next_cost = graph[n][i].second+cost; // 지금까지의 비용과 더하는걸 잊지말자
			if (dist[next] > next_cost) { // 비용 갱신
				dist[next] = next_cost;
				connect[next] = n;
				connectCnt++;
				pq.push({ next, next_cost });
			}
		}

	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N, M;
	cin >> N >> M;
	for (int i = 0; i <= N; i++) {
		dist[i] = INF;
	}
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({ b,c }); // first : node, second : cost
		graph[b].push_back({ a,c });
	}
	dijkstra();
	cout << N - 1 << "\n";
	for (int i= 2; i <=N; i++) { // 1번을 제외하고 다른 연결된 선분 출력?.. 이 부분을 잘 모르겠다
		cout << i << " " << connect[i] << "\n";
	}
}