#include<iostream>
#include<algorithm>
using namespace std;
int n, m;
int parent[1000001];

int Find(int n1) { // n1�� � ���տ� ���ԵǾ� �ִ��� ã�� ����
	if (n1 == parent[n1]) {
		return n1;
	}
	else {
		return parent[n1] = Find(parent[n1]);
	}
}
 // n1�� n2�� ���ԵǾ� �ִ� ������ ã�� ����
void Union(int n1, int n2) {// �θ� ��ĥ ���� �Ϲ������� �� ���� �� ������ ��ģ��
	n1 = Find(n1); 
	n2 = Find(n2);
	// n1<n2 �� ����
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
	// �迭 �ʱ�ȭ
	for (int i = 0; i <= n; i++) {
		parent[i] = i; 
	}
	int oper = 0;
	int n1, n2;
	for (int i = 0; i < m; i++) {
		cin >> oper >> n1 >> n2;		
		if (oper == 0) {// ������
			Union(n1, n2);
		}
		else { // ���� ���տ� �����ִ��� Ȯ�� --> �θ��尡 ������ �ȴ�.
			if (Find(n1)==Find(n2))
				cout << "YES" << "\n";
			else
				cout << "NO" << "\n";
		}
	}
}