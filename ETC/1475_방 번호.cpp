#include<iostream>
using namespace std;

// �ö�ƽ ��Ʈ 6�� 9�� ȥ�밡���̹Ƿ� 6�� 2��
// 0���� 9���� (9�� 0)
int set[10] = {1,1,1,1,1,1,2,1,1,0};
void addset(){
	for (int i = 1; i < 9; i++) {
		if (i == 6) {
			set[i] += 1;
		}
		set[i] += 1;
		
	}
}

int main() {
	int n;
	cin >> n;  // 9156853
	int res = 1;
	while (n) {
		int tmp = n % 10;
		if (tmp == 9) {
			tmp = 6; // 9�� 6���� ġȯ
		}
		if (set[tmp] == 0) { // �ö�ƽ ���ڰ� ������
			addset();
			res++;
		}
		set[tmp]--; // ���� ��������Ƿ� �ϳ� ����
		n = n / 10;
	}
	cout << res;
}