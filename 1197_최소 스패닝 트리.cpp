#include<iostream>
#include<vector>
#include<algorithm>
const int MAX = 10001;
using namespace std;
int parent[MAX];

/*크루스칼 알고리즘 : 가중치가 가장 작은 간선부터 시작하여 낮은 가중치 순으로 사이클이 생기지 않도록 하며 간선을 추가시킴
	ElogE의 시간복잡도를 갖는다. E의 수가 작다면 크루스칼 알고리즘을 쓰는 것이 좋음
*/
struct edge {
	int u, v, w;
	bool operator<(edge const& e) { // 정렬을 위한 오버로딩 가중치 기준으로 정렬
		return w < e.w;
	}
};

// 부모 노드(루트)를 찾는 함수 
int findParent(int node) {
	if (parent[node] == node) {
		return node;
	}
	else{
		return parent[node] = findParent(parent[node]);
	}
}

// 두 부모 노드를 합치는 함수 : 더 작은값으로 부모를 합침
void unionParent(int node1, int node2) {
	node1 = findParent(node1);
	node2 = findParent(node2); 

	if (node1 < node2) {
		parent[node2] = node1; // node2의 부모가 node1이 된다.
	}
	else {
		parent[node1] = node2;
	}
}

// 같은 부모를 가지는지 확인 : 사이클인지 확인
int sameParent(int node1, int node2) {
	node1 = findParent(node1);
	node2 = findParent(node2);
	if (node1 == node2) return 1;
	else return 0;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	vector<edge>v;
	int V, E;
	cin >> V >> E;
	int a, b, c;
	for (int i = 0; i < E; i++) {
		cin >> a >> b >> c;
		v.push_back({ a,b,c });
	}
	// 간선의 가중치를 기준으로 정렬
	sort(v.begin(), v.end());

	// 부모 노드 초기화
	for (int i = 1; i <= V; i++) {
		parent[i] = i;
	}
	long long result = 0;
	for (int i = 0; i < v.size(); i++) {
		// 서로 부모노드가 다른 경우에 추가
		if (findParent(v[i].u) != findParent(v[i].v)) { // if(!sameParent(v[i].u, v[i].v)) 도 가능 
			result += v[i].w;
			unionParent(v[i].u, v[i].v);
		}
	}
	cout << result;
}