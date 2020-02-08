#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
int r, c, k;
int arr[101][101];
pair<int, int>info[101];
int r_len=3; // ���� ����
int c_len=3; // ���� ����
bool cmp(pair<int, int>a, pair<int,int>b) {
	if (a.second < b.second)return true; // ������ ����Ƚ���� ���� ������������ ����
	else if (a.second > b.second) return false;
	else { // ������ ����Ƚ���� ������, ���� ũ�⸦ ������������ ����
		if (a.first < b.first)return true;
		else return false;
	}
}
void r_action(int r) { // R����
	memset(info, 0, sizeof(info));
	for (int i = 0; i < c_len; i++) {
		info[arr[r][i]].first = arr[r][i]; // �ش� ����
		info[arr[r][i]].second++;  // �ش� ���ڰ� ��� ���Դ���
	}
	for (int i = 0; i < c_len; i++) {
		arr[r][i] = 0;
	}
	sort(info+1, info + 101, cmp);

	// ���ں� ���� Ƚ���� �迭�� ����
	int idx = 0;
	for (int i = 1; i <= 100; i++) {
		if (info[i].first) {// �ش� ���ڰ� ������
			arr[r][idx] = info[i].first;
			idx++;
			arr[r][idx] = info[i].second;
			idx++;
		}
	}
	c_len = max(idx, c_len);
}
void c_action(int c) {
	memset(info, 0, sizeof(info));
	for (int i = 0; i < r_len; i++) {
		info[arr[i][c]].first = arr[i][c]; // �ش� ����
		info[arr[i][c]].second++;  // �ش� ���ڰ� ��� ���Դ���
	}
	for (int i = 0; i < r_len; i++) {
		arr[i][c] = 0;
	}
	sort(info+1, info + 101, cmp);

	// ���ں� ���� Ƚ���� �迭�� ����
	int idx = 0;
	for (int i = 1; i <= 100; i++) {
		if (info[i].first) {// �ش� ���ڰ� ������
			arr[idx][c] = info[i].first;
			idx++;
			arr[idx][c] = info[i].second;
			idx++;
		}
	}
	r_len = max(idx, r_len);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);	cout.tie();
	freopen("input.txt", "r", stdin);
	cin >> r >> c >> k;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> arr[i][j];
		}
	}
	int time = 0;
	char oper = 'R';
	while (arr[r-1][k-1]!=k) {
		if (r_len >= c_len) { // R����
			int len = r_len;
			for (int i = 0; i < len; i++) {
				r_action(i);
			}
		}
		else { //C����
			int len = c_len;
			for (int i = 0; i < len; i++) {
				c_action(i);
			}
		}
		time++;
		if (time > 100)
		{
			cout << -1;
			exit(0);
		}
	}
	cout << time;
}