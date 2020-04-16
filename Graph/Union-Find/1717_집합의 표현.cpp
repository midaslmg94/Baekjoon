#include<iostream>
#include<algorithm>
using namespace std;
int n, m;
int parent[1000001];

int Find(int n1) { // n1이 어떤 집합에 포함되어 있는지 찾는 연산
	if (n1 == parent[n1]) {
		return n1;
	}
	else {
		return parent[n1] = Find(parent[n1]);
	}
}
 // n1과 n2가 포함되어 있는 집합을 찾는 연산
void Union(int n1, int n2) {// 부모를 합칠 때는 일반적으로 더 작은 값 쪽으로 합친다
	n1 = Find(n1); 
	n2 = Find(n2);
	// n1<n2 로 가정
	if (n1 != n2) {
		if (n1 < n2)
			parent[n2] = n1;
		else
			parent[n1] = n2;
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);	cout.tie();
	freopen("input.txt", "r", stdin);
	cin >> n >> m;
	// 배열 초기화
	for (int i = 0; i <= n; i++) {
		parent[i] = i; 
	}
	int oper = 0;
	int n1, n2;
	for (int i = 0; i < m; i++) {
		cin >> oper >> n1 >> n2;		
		if (oper == 0) {// 합집합
			Union(n1, n2);
		}
		else { // 같은 집합에 속해있는지 확인 --> 부모노드가 같으면 된다.
			if (Find(n1)==Find(n2))
				cout << "YES" << "\n";
			else
				cout << "NO" << "\n";
		}
	}
}