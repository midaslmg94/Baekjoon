#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
int r, c, k;
int arr[101][101];
pair<int, int>info[101];
int r_len=3; // 행의 길이
int c_len=3; // 열의 길이
bool cmp(pair<int, int>a, pair<int,int>b) {
	if (a.second < b.second)return true; // 숫자의 등장횟수를 먼저 오름차순으로 정렬
	else if (a.second > b.second) return false;
	else { // 숫자의 등장횟수가 같으면, 숫자 크기를 오름차순으로 정렬
		if (a.first < b.first)return true;
		else return false;
	}
}
void r_action(int r) { // R연산
	memset(info, 0, sizeof(info));
	for (int i = 0; i < c_len; i++) {
		info[arr[r][i]].first = arr[r][i]; // 해당 숫자
		info[arr[r][i]].second++;  // 해당 숫자가 몇번 나왔는지
	}
	for (int i = 0; i < c_len; i++) {
		arr[r][i] = 0;
	}
	sort(info+1, info + 101, cmp);

	// 숫자별 등장 횟수로 배열을 정렬
	int idx = 0;
	for (int i = 1; i <= 100; i++) {
		if (info[i].first) {// 해당 숫자가 있으면
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
		info[arr[i][c]].first = arr[i][c]; // 해당 숫자
		info[arr[i][c]].second++;  // 해당 숫자가 몇번 나왔는지
	}
	for (int i = 0; i < r_len; i++) {
		arr[i][c] = 0;
	}
	sort(info+1, info + 101, cmp);

	// 숫자별 등장 횟수로 배열을 정렬
	int idx = 0;
	for (int i = 1; i <= 100; i++) {
		if (info[i].first) {// 해당 숫자가 있으면
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
		if (r_len >= c_len) { // R연산
			int len = r_len;
			for (int i = 0; i < len; i++) {
				r_action(i);
			}
		}
		else { //C연산
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