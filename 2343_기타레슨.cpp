#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#define MAX 100000
using namespace std;
int n, m;
int lesson[MAX];
int result = 0;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);
	
	cin >> n >> m;
	int sum = 0;
	int max_value = 0;
	for (int i = 0; i < n; i++) {
		cin >> lesson[i];
		sum += lesson[i];
		max_value = max(max_value, lesson[i]);
	}
	int left = max_value; // ����???
	int right = sum;
	int mid = 0;
	while (left <= right) {
		mid = (left + right) / 2; // �ִ� ��ȭ ����
		int cur_disk = 0; // ���� ����Ǵ� ��緹���� ����
		int cnt = 0; // ��ȭ�Ǵ� ��緹���� ����
		for (int i = 0; i < n; i++) {
			if (cur_disk + lesson[i] > mid) {
				cur_disk = 0;
				cnt++;
			}
			cur_disk += lesson[i];
		}		
		if (cur_disk != 0)cnt++; // �������� ���� cd�� �Ѱ� �� �߰�??
		
		if (cnt>m) { // ��緹���� ���̰� �� ������� �ȴ�
			left = mid + 1;
		}
		else { // ��緹���� ���̰� ª������ �Ѵ�
			right = mid - 1;
		}		
	}
	cout << left << endl;
	return 0;
}