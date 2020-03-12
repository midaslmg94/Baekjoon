#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<deque>
#include<string.h>
#define endl "\n"
#define MAX 100000
using namespace std;
// LIS�� Ǯ��
int n;
int answer;
vector<int>v;
vector<int>lis; // �ε������� �� ���� ������ ����

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int tmp; cin >> tmp;
		v.push_back(tmp);
	}
	lis.push_back(v[0]);
	for (int i = 1; i < n; i++) {				
		if (lis.back() < v[i]) { // lis�� �� ���� ���Һ��� ū ���� ������ ����
			lis.push_back(v[i]);
		}
		else { // lis�� �� �� ���Һ��� ���� ���̸�, �� ���Ұ� �� ��ġ�� ����
			int idx = lower_bound(lis.begin(), lis.end(), v[i]) - lis.begin();
			lis[idx] = v[i];
		}
		
	}
	answer = v.size()- lis.size();
	cout << answer;
	return 0;
}