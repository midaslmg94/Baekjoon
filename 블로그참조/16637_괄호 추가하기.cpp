#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n;
string str;
int result = -987654321;

int calc(int n1, char oper, int n2) {
	if (oper == '+') return n1 + n2;
	else if (oper == '-')return n1 - n2;
	else return n1 * n2;
}
void dfs(int cur, int idx) {
	if (idx > n - 1) {
		result = max(result, cur);
		return;
	}
	char oper;
	if (idx == 0)oper = '+'; // ����?..
	else oper = str[idx - 1];

	// ��ȣ�� ĥ �� �ִٸ� 
	if (idx + 2 <= n - 1) {
		int res = calc(str[idx] - '0', str[idx + 1], str[idx + 2] - '0');// ��ȣ���� �� ���
		int next = calc(cur, oper, res); // ���� ���ڿ�, ��ȣ���� ���� ���
		dfs(next, idx + 4); // (2+3)+1 �̶��, ������ +
	}

	// ��ȣ�� ġ�� ����
	int next = calc(cur, oper, str[idx] - '0');
	dfs(next, idx + 2);

}
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);
	cin >> n >> str;
	dfs(0, 0);
	cout << result;
	return 0;
}