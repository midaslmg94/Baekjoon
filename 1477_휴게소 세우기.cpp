#include<iostream>
#include<algorithm>
#include<vector>
#include<string.h>
#define endl "\n"
using namespace std;
int n, m, l;

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);
	cin >> n >> m >> l;
	vector<int>store;
	int pos;
	store.push_back(0); // �Ÿ��� ��������
	for (int i = 0; i < n; i++) {
		cin >> pos;
		store.push_back(pos);
	}
	store.push_back(l); // �Ÿ��� ������
	sort(store.begin(), store.end());	

	int left = 1;
	int right = l - 1;	
	while (left <= right) {
		int mid = (left + right) / 2; // ���� ���������� ���Ӱ� ���� ������ ������ �Ÿ� 
		int new_store = 0;
		for (int i = 1; i < store.size(); i++) {
			int dist = store[i] - store[i - 1]; 
			new_store += (dist / mid); // �� ������ ���̿� ���� �� �ִ� �������� ����
			if (dist % mid == 0) { // ������ �������� ��� : �������� ���ļ� �������Ƿ� 1�� ��
				new_store--;
			}
		}
		
		if (new_store > m) { // �������� ������ ���� �� ���� ���� -> ������ �ø�
			left = mid + 1;
		}
		else { // �������� ������ ���� �� ���� ���� -> ������ ����
			right = mid - 1;
		}		
	}
	
	cout << left;
	return 0;
}