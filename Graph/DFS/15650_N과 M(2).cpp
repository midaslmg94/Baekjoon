#include<iostream>
using namespace std;
/*
�ڿ��� N�� M�� �־����� ��, �Ʒ� ������ �����ϴ� ���̰� M�� ������ 
��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

1���� N���� �ڿ��� �߿��� �ߺ� ���� M���� �� ���� --> ����
�� ������ ���������̾�� �Ѵ�.
*/
int n, m;
bool visit[9];
int arr[9];
void combination(int length, int idx) { // ������, ��� �̴���
	if (length == m) { // ���ϴ� ��ŭ �̾���
		for (int i = 0; i < m; i++) {
				cout << arr[i] << ' ';
		}
		cout << "\n";
		return;
	}
	for (int i = idx; i <= n; i++) { // 1���� n���� ����
		if (visit[i]==true)
			continue;
		visit[i] = true;
		arr[length] = i;
		combination(length + 1, i+1);
		visit[i] = false;
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);	cout.tie();
	freopen("input.txt", "r", stdin);
	cin >> n >> m;
	combination(0,1);	
}