#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	// 1���� n���� �ڿ��� �߿��� �ߺ� ���� M���� �� ����
	vector<int>v(n);
	vector<int>choice(n);
	for (int i = 0; i < n; i++) {
		v[i]=i+1;
		choice[i]=0;
	}
	sort(v.begin(), v.end());
	// 4���� 2���� choice = {0,0,1,1}
	for (int i = n-1; i >= n-m; i--) {
		choice[i] = 1;
	}
	// �̷��� �ϸ� �ѹ� ���õ� ���Ҵ� ���ܵȴ�
	do {
		for (int i = 0; i < n; i++) {
			if (choice[i] == 1) {
				cout << v[i] << ' ';
			}
		}
		cout << endl;
	} while (next_permutation(choice.begin(), choice.end()));	
}