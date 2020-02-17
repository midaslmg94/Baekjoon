#include<iostream>
#include<vector>
#include<deque>
#include<string.h>
#include<algorithm>
#define endl "\n"
#define MAX 50
using namespace std;
int n;
int player[MAX][MAX]; // 각 선수가 이닝에서 얻는 결과. 자신이 가장 좋아하는 선수인 1번 선수를 4번 타자로 미리 결정했다. 
deque<int>order = { 2,3,4,5,6,7,8,9 }; // 치는 순서
int max_score = -1;
int ground[4];
void hit(int info) {
	if (info == 1) { // 1루타
		if (ground[2]) { // 주루에 선수가 존재한다면
			ground[3] += 1;
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
	else if (info == 2) { // 2루타
		if (ground[2]) { // 주루에 선수가 존재한다면 그 위치의 타자를 2루 진루 시키고, 해당 플레이트는 비움
			ground[3] += 1;
			ground[2] = 0;
		}
		if (ground[1]) {
			ground[3] += 1;
			ground[1] = 0;
		}
		if (ground[0]) {
			ground[2] = 1;
			ground[0] = 0;
		}
	}
	else if (info == 3) {// 3루타
		if (ground[2]) { // 주루에 선수가 존재한다면
			ground[3] += 1;
			ground[2] = 0;
		}
		if (ground[1]) {
			ground[3] += 1;
			ground[1] = 0;
		}
		if (ground[0]) {
			ground[3] += 1;
			ground[0] = 0;
		}
	}
	else {// 홈런
		if (ground[2]) { // 주루에 선수가 존재한다면
			ground[3] += 1;
			ground[2] = 0;
		}
		if (ground[1]) {
			ground[3] += 1;
			ground[1] = 0;
		}
		if (ground[0]) {
			ground[3] += 1;
			ground[0] = 0;
		}
	}
}
int game(deque<int>play) {// 타석에서는 순서
	int score = 0;
	int start = 0;
	memset(ground,0,sizeof(ground)); // 1루, 2루, 3루, 홈에 들어온 주자
	for (int i = 0; i < n; i++) {		
		int out_count = 0;
		while (out_count<3) {
			int cur_player = play[start]; // 현재 타석에 들어간 타자.
			int hit_info = player[i][cur_player-1];
			if (hit_info == 0) {// 아웃
				out_count++;
			}
			else if (hit_info == 1) {// 1루타
				hit(1);
				ground[0] = 1;
			}
			else if (hit_info == 2) {//2루타
				hit(2);
				ground[1] = 1;
			}
			else if (hit_info == 3) {//3루타
				hit(3);
				ground[2] = 1;
			}
			else {// 홈런
				hit(4);
				ground[3] += 1;
			}
			score += ground[3]; // 홈에 들어온 주자 추가
			ground[3] = 0;
			start++;
			start = start % 9; // 마지막 선수까지 오면 맨 앞으로 다시
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
		for (int j = 0; j < n; j++) {
			cin >> player[i][j];
		}
	}
	do {
		deque<int>tmp; // 선수들이 치는 모든 순서를 구한다
		for (int i = 0; i < 8; i++) {
			tmp.push_back(order[i]);
		}
		deque<int>::iterator it = tmp.begin();
		tmp.insert(it + 3, 1); // 4번타자에 1번선수를 넣음
		int cur_score = game(tmp); 
		max_score = max(max_score, cur_score);
		//cout << "cur_score " << cur_score << "max_score " << max_score << endl;
	} while (next_permutation(order.begin(), order.end()));
	
	cout << max_score;
}
