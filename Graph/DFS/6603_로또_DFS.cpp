#include<iostream>
#define MAX_SIZE 13
using namespace std;
int lotto[MAX_SIZE];
int combi[MAX_SIZE];
int k;

void dfs(int start, int depth) {
	if (depth == 6) {                    //Ż������
		for (int i = 0; i < 6; i++) {
			cout << combi[i] << ' ';    //�����ϳ��� ����� �� Ż��
		}
		cout << '\n';
		return;
	}
	for (int i = start; i < k; i++) {    //lotto�迭 0���� k-1���� Ž����     
		combi[depth] = lotto[i];    //depth�� ���� -> 0~5��° ���̱��� ��͸����� ���� Ž���� ���ڸ� ����.    
		dfs(i + 1, depth + 1);            //��� ���� �κ� , �ϳ��� ���̸� Ž�� �� ���������� ���� �Լ�ȣ���Ҷ��� ����+1�� �������.
	}
}

int main() {
	while (cin >> k && k) {            //0�� �Է� ���� �� ���� ���ѷ���
		for (int i = 0; i < k; i++) {
			cin >> lotto[i];
		}
		dfs(0, 0);
		cout << '\n';
	}
	return 0;
}

