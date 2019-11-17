#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
string map[50];
int n;
  
int eat() {
	int right = 0;
	int right_max = 0;
	int down = 0;
	int down_max = 0;

	// ���� Ȯ��
	for (int i = 0; i < n; i++) {
		right = 1; // ���η� ����
		for (int j = 0; j < n - 1; j++) {
			if (map[i][j] == map[i][j + 1]) {
				right++;

			}
			else {
				right = 1;
			}
			right_max = max(right, right_max);
		}
	}

	// ���� Ȯ��
	for (int j = 0; j < n; j++) {
		down = 1; // ���η� ����
		for (int i = 0; i < n - 1; i++) {
			if (map[i][j] == map[i + 1][j]) {
				down++;
			}
			else {
				down = 1;
			}
			down_max = max(down, down_max);
		}
	}
	int res = max(right_max, down_max);
	return res;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> map[i];
	}
	int max_num = 0;
	for (int i = 0; i < n; i++) {
		int cur = 0; // ���� ��ġ���� ���� �� �ִ� ������ ����
		int change_down = 0; // �Ʒ� ĭ�� ��ȯ
		int change_right = 0; // ������ ĭ�� ��ȯ
		for (int j = 0; j < n; j++) {
			cur = eat();
			// �ٸ���, �Ʒ� ��ȯ, ���󺹱�
			if (i != n - 1) {
				if (map[i][j] != map[i + 1][j]) {
					swap(map[i][j], map[i + 1][j]);
					change_down = eat();
					swap(map[i][j], map[i + 1][j]);
				}
			}
			// �ٸ���, ������ ��ȯ, ���󺹱�
			if (j != n - 1) {
				if (map[i][j] != map[i][j + 1]) {
					swap(map[i][j], map[i][j + 1]);
					change_right = eat();
					swap(map[i][j], map[i][j + 1]);
				}
			}
			// cur, down, right �� ���� ū ��
			int tmp = max(max(cur, change_down), change_right);
			max_num = max_num > tmp ? max_num : tmp;
		}
	}
	cout << max_num;

}