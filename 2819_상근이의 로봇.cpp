#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
int n, m;
vector<pair<int, int>>v; // ������
queue<char>oper;
vector<int>ans; // ���
/*
�κ��� ���� (x,y)�� �ִٰ� ����. 
S(north)�� (x, y+1)��,
J(south)�� (x,y-1)��, 
I(east)�� (x+1,y)��, 
Z(west)�� (x-1,y)�� �̵��϶�� �ǹ��̴�.
*/

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);	cout.tie();
	freopen("input.txt", "r", stdin);
	cin >> n >> m;
	int x, y;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		v.push_back({ x,y });
	}
	char tmp;
	for (int i = 0; i < m; i++) {
		cin >> tmp;
		oper.push(tmp);
	}

}
