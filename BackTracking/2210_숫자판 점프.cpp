#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<string.h>
#define endl "\n"
using namespace std;
char num[5][5];
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
vector<int>dir;
int moving[4] = { 0,1,2,3 };
map<string, int>answer;
string str = "";
string jump(int y, int x) {
	str = num[y][x]; // 첫 숫자는 선택된 위치 
	for (int i = 0; i < dir.size(); i++) { // 동,서,남,북 중 5번 이동
		y = y + dy[dir[i]];
		x = x + dx[dir[i]];
		if (0 > y || y > 4 || 0 > x || x > 4) return ""; // 범위 초과되면 의미없음( y>=4, x>=4 로했었어서 틀렸었음)
		str += num[y][x];
	}
	return str;
}


// 중복순열 구하기
void dfs(int cnt) {
	if (cnt == 5) { // 5번 이동
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				string tmp = jump(i, j);
				answer.insert({ tmp, 1 }); // key:만들어진 수, value:의미없는 수
			}
		}
		return;
	}
	for (int i = 0; i < 4; i++) {
		dir.push_back(i);
		dfs(cnt + 1);
		dir.pop_back();
	}

}
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> num[i][j];
		}
	}
	dfs(0);
	/*for (auto i = answer.begin(); i != answer.end(); i++) {
		cout << i->first << endl;
	}*/
	cout << answer.size() - 1; // 빈 문자열로 들어간 것 빼줌
	return 0;

}