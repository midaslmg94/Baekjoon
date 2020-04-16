#include<iostream>
#include<map>
#define endl "\n"
#define MAX 200000
using namespace std;
int parent[MAX]; // ���Ͽ� ���ε��
int group_count[MAX]; // ���տ� �ִ� ��� �� 

int findParent(int n1){
	if (n1 == parent[n1]) {
		return n1;
	}
	else {
		int n2 = findParent(parent[n1]);
		parent[n1] = n2;
		return n2;
	}
}
void unionParent(int n1, int n2) {
	n1 = findParent(n1);
	n2 = findParent(n2);
	if (n1 != n2) {
		parent[n2] = n1;
	}
}

int main() {
	ios::sync_with_stdio(false);
	freopen("input.txt", "r", stdin);
	int t;
	cin >> t;
	while (t--) {
		map<string, int>m; // {Fred:1} , {Barney:2} ..
		int n; 
		string f1, f2;
		cin >> n;
		for (int i = 0; i < n; i++) {
			parent[i] = i;
		}
		int idx = 0;
		for (int i = 0; i < n; i++) {
			cin >> f1 >> f2;
			int is_f1 = m.count(f1); 
			int is_f2 = m.count(f2);
			int idx_f1 = idx;
			int idx_f2 = idx;
			// f1, f2 �� �� �ʿ� ����
			if (is_f1 == 0 && is_f2 == 0) {
				m.insert({ f1,idx_f1 });
				m.insert({ f2,idx_f2 });
				group_count[idx] += 2;
				cout << group_count[idx++] << endl;
			}

			// f1�� �ʿ� ����
			else if (is_f1 == 1 && is_f2 == 0) {
				idx_f1 = findParent(m[f1]);
				m[]

				idx_f2 = idx_f1;
				m.insert({ f2,idx_f2 });
			}

			// f2�� �ʿ� ����
			else if (is_f1 == 0 && is_f2 == 1) {
				idx_f2 = findParent(m[f2]);
				idx_f1 = idx_f2;
				m.insert({ f1,idx_f2 });
			}
			// f1, f2 �� �� �ʿ� ���� --> ���Ͽ�
			else {

			}
		}
	}
}