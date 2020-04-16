#include<iostream>
#include<queue>

using namespace std;
/*
	���� x�� �ڿ������ �迭�� x��� ���� �ִ�(�߰��ϴ�) �����̰�,
	x�� 0�̶�� �迭���� ���� ū ���� ����ϰ� �� ���� �迭���� �����ϴ� ����̴�. 
	�Է¿��� 0�� �־��� ȸ����ŭ ���� ����Ѵ�. 
	���� �迭�� ��� �ִ� ����ε� ���� ū ���� ����϶�� �� ��쿡�� 0�� ����ϸ� �ȴ�.
*/

/**/
priority_queue<long long>q;
long long arr[100000];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	long long n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	long long x = 0;
	for (int i = 0; i < n; i++) {
		x = arr[i];
		if (x == 0) {
			if (q.empty()) { 
				cout <<0<<"\n";
			}else { //�迭�� ����ִ� ���
				cout <<q.top()<< "\n";
				q.pop();
			}
		}else {
			q.emplace(x);
		}
	}
}