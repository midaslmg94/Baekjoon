#include<iostream>
#include<vector>
#include<algorithm>
const int MAX = 10001;
using namespace std;
int parent[MAX];

/*ũ�罺Į �˰��� : ����ġ�� ���� ���� �������� �����Ͽ� ���� ����ġ ������ ����Ŭ�� ������ �ʵ��� �ϸ� ������ �߰���Ŵ
	ElogE�� �ð����⵵�� ���´�. E�� ���� �۴ٸ� ũ�罺Į �˰����� ���� ���� ����
*/
struct edge {
	int u, v, w;
	bool operator<(edge const& e) { // ������ ���� �����ε� ����ġ �������� ����
		return w < e.w;
	}
};

// �θ� ���(��Ʈ)�� ã�� �Լ� 
int findParent(int node) {
	if (parent[node] == node) {
		return node;
	}
	else{
		return parent[node] = findParent(parent[node]);
	}
}

// �� �θ� ��带 ��ġ�� �Լ� : �� ���������� �θ� ��ħ
void unionParent(int node1, int node2) {
	node1 = findParent(node1);
	node2 = findParent(node2); 

	if (node1 < node2) {
		parent[node2] = node1; // node2�� �θ� node1�� �ȴ�.
	}
	else {
		parent[node1] = node2;
	}
}

// ���� �θ� �������� Ȯ�� : ����Ŭ���� Ȯ��
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
	// ������ ����ġ�� �������� ����
	sort(v.begin(), v.end());

	// �θ� ��� �ʱ�ȭ
	for (int i = 1; i <= V; i++) {
		parent[i] = i;
	}
	long long result = 0;
	for (int i = 0; i < v.size(); i++) {
		// ���� �θ��尡 �ٸ� ��쿡 �߰�
		if (findParent(v[i].u) != findParent(v[i].v)) { // if(!sameParent(v[i].u, v[i].v)) �� ���� 
			result += v[i].w;
			unionParent(v[i].u, v[i].v);
		}
	}
	cout << result;
}