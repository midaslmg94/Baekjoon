#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int L, C;
char alpha[16];

// cnt�� ���ݱ��� ������ ���Ĺ��� �� ����, mo�� ����, ja�� ����, s�� ������� ������� ��ȣ
void go(int index, int cnt, int mo, int ja, string s) {
	if (cnt == L) { // ������ ���ĺ��� ������ ������ ���ĺ��� ������ ���� ��
		if (mo >= 1 && ja >= 2)
			cout << s << endl;
		return;
	}
	if (index == C) return; // �ε����� ������ �� ���
	if (alpha[index] == 'a' || alpha[index] == 'e' || alpha[index] == 'i' || alpha[index] == 'o' || alpha[index] == 'u')
		go(index + 1, cnt + 1, mo + 1, ja, s + alpha[index]); // ���� �߰�
	else
		go(index + 1, cnt + 1, mo, ja + 1, s + alpha[index]); // ���� �߰�
	go(index + 1, cnt, mo, ja, s); // �� �̰� ����?
}
int main() {
	cin >> L >> C;
	for (int i = 0; i < C; i++)
		cin >> alpha[i];
	sort(alpha, alpha + C);
	go(0, 0, 0, 0, "");
	return 0;
}