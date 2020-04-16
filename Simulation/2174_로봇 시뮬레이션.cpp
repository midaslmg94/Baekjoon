#include<bits/stdc++.h>
#define endl "\n"
#define MAX 100+1
using namespace std;
int a, b;
int n, m;
bool flag = true;
struct ROBOT {
	int y;
	int x;
	int dir;
};
int arr[MAX][MAX];
vector<ROBOT>robot;
int dy[4] = { 0,-1,0,1 }; // ��, ��, ��, ��
int dx[4] = { 1,0,-1,0 };
int changeDir(char d) {
	if (d == 'E')return 0; // ��
	if (d == 'N')return 1; // ��
	if (d == 'W')return 2; // ��
	if (d == 'S')return 3; // ��
}
void prt() {
	for (int i = 1; i <= b; i++) {
		for (int j = 1; j <= a; j++) {
			cout << arr[i][j] << ' ';
		}
		cout << endl;
	}
}
void go(int robot_num, char oper, int cnt) {
	for (int i = 0; i < cnt; i++) {
		int y = robot[robot_num].y;
		int x = robot[robot_num].x;
		int dir = robot[robot_num].dir;
		//cout << dir << endl;
		//prt(); cout << endl;
		if (oper == 'L') { // ���� 90�� ȸ��
			dir = (dir + 1) % 4;
			robot[robot_num].dir = dir;
		}
		else if (oper == 'R') { // ������ 90�� ȸ��
			dir = (dir + 3) % 4;
			robot[robot_num].dir = dir;
		}
		else { // �� ĭ ����
			int ny = y + dy[dir];
			int nx = x + dx[dir];
			if (1 > ny || ny > b || 1 > nx || nx > a) { // ���� �ʰ�
				cout << "Robot " << robot_num  << " crashes into the wall";
				flag = false;
				break;
			}
			if (arr[ny][nx] != 0) { // �ٸ� �κ��� �ε���
				cout << "Robot " << robot_num  << " crashes into robot " << arr[ny][nx];
				flag = false;
				break;
			}
			arr[ny][nx] = robot_num;
			arr[y][x] = 0;
			robot[robot_num].y = ny;
			robot[robot_num].x = nx;
			robot[robot_num].dir = dir;
			//cout << ny << ' ' << nx << endl;
		}
	}

}
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);
	cin >> a >> b; // 5 4
	cin >> n >> m;
	robot.push_back({ 999999,99999,99999 }); // i��° �����ֱ� ���� 0��°�� �� �־���
	for (int i = 1; i <= n; i++) { // i��° �κ��� ����
		int y, x; char dir;
		cin >> x >> y >> dir; // arr[y][x]�� �ϱ� ���� ��ǥ�� �Ųٷ� �Է¹���
		y = abs(b + 1 - y); // y�� �� ����
		dir = changeDir(dir);
		arr[y][x] = i;
		robot.push_back({ y,x,dir });
	}

	for (int i = 0; i < m; i++) { // ��� ����
		int robot_num; char oper; int cnt;
		cin >> robot_num >> oper >> cnt;
		go(robot_num, oper, cnt);
		if (flag == false) return 0;
	}
	cout << "OK";
	return 0;
}