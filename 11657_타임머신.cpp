#include<iostream>
#include<vector>
#define MAX 501
typedef pair<int, int> pii;
using namespace std;
vector<pii>v[MAX];
int n, m;
int from, to, cost;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);

	cin >> n >> m;
	/*
	 C�� ������ Ÿ�� �̵��ϴµ� �ɸ��� �ð��̴�. 
	 �ð� C�� ����� �ƴ� ��찡 �ִ�. 
	 C = 0�� ���� ���� �̵��� �ϴ� ���
	 C < 0�� ���� Ÿ�Ӹӽ����� �ð��� �ǵ��ư��� ����̴�.
	*/
	for (int i = 0; i < m; i++) {
		cin >> from >> to >> cost;
	}
}
