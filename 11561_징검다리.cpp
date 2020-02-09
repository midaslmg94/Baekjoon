#include<iostream>
using namespace std;
int t;
long long n; // 1��, 2�� ... n�� ¡�˴ٸ�
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);	cout.tie();
	freopen("input.txt", "r", stdin);
	cin >> t;
	/*
	ù ¡�˴ٸ��� �����ؼ� �ƹ� ���̳� ���� �� �ִ�. �� ������ ù �����̴�.
	�� ��° �������ʹ� ������ ������ �Ÿ����� 1 �̻� �� �� �Ÿ��� �پ�߸� �Ѵ�.
	N�� ¡�˴ٸ��� �ݵ�� ��ƾ� �Ѵ�.
	N�� ¡�˴ٸ��� ���� �� �� �ǳʷ� �̵��� �� ������ ���� �����Ƿ� ���� ��Ģ�� ������� �ʴ´�.
	*/

	while (t--) {
		long long jump = 1; // ���������� 1�� �����Ƿ� �ʱⰪ:1
		cin >> n;
		long long cur = 1; // 1������ �پ�� ��
		long long dist = 1;
		while (cur!=n) {
			dist++;
			cur = cur + dist;
			if (cur > n) {
				break;
			}
			jump++;
		}
		cout << jump<<"\n";
	}
}