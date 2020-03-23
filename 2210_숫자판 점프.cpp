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
	str = num[y][x]; // ù ���ڴ� ���õ� ��ġ 
	for (int i = 0; i < dir.size(); i++) { // ��,��,��,�� �� 5�� �̵�
		y = y + dy[dir[i]];
		x = x + dx[dir[i]];
		if (0 > y || y > 4 || 0 > x || x > 4) return ""; // ���� �ʰ��Ǹ� �ǹ̾���( y>=4, x>=4 ���߾�� Ʋ�Ⱦ���)
		str += num[y][x];
	}
	return str;
}


// �ߺ����� ���ϱ�
void dfs(int cnt) {
	if (cnt == 5) { // 5�� �̵�
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				string tmp = jump(i, j);
				answer.insert({ tmp, 1 }); // key:������� ��, value:�ǹ̾��� ��
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
	cout << answer.size() - 1; // �� ���ڿ��� �� �� ����
	return 0;

}