#include<iostream>
#include<vector>
#include<deque>
#include<string.h>
#include<algorithm>
#define endl "\n"
#define MAX 50
using namespace std;
int n;
int player[MAX][9]; // �� ������ �̴׿��� ��� ���. �ڽ��� ���� �����ϴ� ������ 1�� ������ 4�� Ÿ�ڷ� �̸� �����ߴ�. 
deque<int>order = { 2,3,4,5,6,7,8,9 }; // ġ�� ����
int max_score = -1;
int ground[3]; // 1��, 2��, 3�翡 ���ڰ� �����ϴ���
int score = 0;
void hit(int info) {
	if (info == 1) { // 1��Ÿ
		if (ground[2]) { // �ַ翡 ������ �����Ѵٸ� �� ��ġ�� Ÿ�ڸ� 1�� ���� ��Ű��, �ش� �÷���Ʈ�� ���
			score += 1;
			ground[2] = 0;
		}
		if (ground[1]) {
			ground[2] = 1;
			ground[1] = 0;
		}
		if (ground[0]) {
			ground[1] = 1;
			ground[0] = 0;
		}
	}
	else if (info == 2) { // 2��Ÿ
		if (ground[2]) { // �ַ翡 ������ �����Ѵٸ� �� ��ġ�� Ÿ�ڸ� 2�� ���� ��Ű��, �ش� �÷���Ʈ�� ���
			score += 1;
			ground[2] = 0;
		}
		if (ground[1]) {
			score += 1;
			ground[1] = 0;
		}
		if (ground[0]) {
			ground[2] = 1;
			ground[0] = 0;
		}
	}
	else if (info == 3) {// 3��Ÿ
		if (ground[2]) { // �ַ翡 ������ �����Ѵٸ� �� ��ġ�� Ÿ�ڸ� 3�� ���� ��Ű��, �ش� �÷���Ʈ�� ���
			score += 1;
			ground[2] = 0;
		}
		if (ground[1]) {
			score += 1;
			ground[1] = 0;
		}
		if (ground[0]) {
			score += 1;
			ground[0] = 0;
		}
	}
	else {// Ȩ��
		if (ground[2]) { // �ַ翡 ������ �����Ѵٸ� �� ��ġ�� Ÿ�ڸ� 4�� ���� ��Ű��, �ش� �÷���Ʈ�� ���
			score += 1;
			ground[2] = 0;
		}
		if (ground[1]) {
			score += 1;
			ground[1] = 0;
		}
		if (ground[0]) {
			score += 1;
			ground[0] = 0;
		}
	}
}
int game(deque<int>play) {// Ÿ�������� ����
	score = 0;
	int start = 0;
	for (int i = 0; i < n; i++) {		
		memset(ground,0,sizeof(ground)); // 1��, 2��, 3��, Ȩ�� ���� ����
		int out_count = 0;
		while (true) {
			int cur_player = play[start]; // ���� Ÿ���� �� Ÿ��.
			int hit_info = player[i][cur_player-1]; // Ÿ�ڰ� ġ�� �� Ÿ��
			if (hit_info == 0) {// �ƿ�
				out_count++;
				start++;
				start = start % 9; // ������ �������� ���� �� ������ �ٽ�
				if (out_count == 3) {
					break;
				}
				continue;
			}
			else if (hit_info == 1) {// 1��Ÿ
				hit(1);
				ground[0] = 1;
			}
			else if (hit_info == 2) {//2��Ÿ
				hit(2);
				ground[1] = 1;
			}
			else if (hit_info == 3) {//3��Ÿ
				hit(3);
				ground[2] = 1;
			}
			else {// Ȩ��
				hit(4);
				score+= 1;
			}			
			start++;
			start = start % 9; // ������ �������� ���� �� ������ �ٽ�
		}
	}
	return score;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> player[i][j];
		}
	}
	do {
		deque<int>tmp; // �������� ġ�� ��� ������ ���Ѵ�
		for (int i = 0; i < 8; i++) {
			tmp.push_back(order[i]);
		}
		deque<int>::iterator it = tmp.begin();
		tmp.insert(it + 3, 1); // 4��Ÿ�ڿ� 1�������� ����
		int cur_score = game(tmp); 
		max_score = max(max_score, cur_score);
	} while (next_permutation(order.begin(), order.end()));
	
	cout << max_score;	
	return 0;
}
