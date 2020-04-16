#include<iostream>
using namespace std;
/*
�ڿ��� N�� M�� �־����� ��, �Ʒ� ������ �����ϴ� ���̰� M�� ������ 
��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

1���� N���� �ڿ��� �߿��� �ߺ� ���� M���� �� ���� --> ����
������ ���� ������ �����ϴ� ������ ����ؾ� �Ѵ�. 

dfs�� ����� ��Ʈ��ŷ(���)�� Ǯ���
*/
int n, m;
bool visit[10];
int arr[10];
void dfs(int length) {
	if (length == m) {
		for (int i = 0; i < m; i++) {
			cout << arr[i]<<' ';			
		}
		cout << "\n";
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (visit[i])
			continue;
		visit[i] = true;
		arr[length] = i;
		dfs(length + 1);
		visit[i] = false;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);	cout.tie();
	freopen("input.txt", "r", stdin);
	cin >> n >> m; // n�� �� m���� �ߺ����� ��
	dfs(0);

}