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
int dy[4] = { 0,-1,0,1 }; // 동, 북, 서, 남
int dx[4] = { 1,0,-1,0 };
int changeDir(char d) {
	if (d == 'E')return 0; // 동
	if (d == 'N')return 1; // 북
	if (d == 'W')return 2; // 서
	if (d == 'S')return 3; // 남
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
		if (oper == 'L') { // 왼쪽 90도 회전
			dir = (dir + 1) % 4;
			robot[robot_num].dir = dir;
		}
		else if (oper == 'R') { // 오른쪽 90도 회전
			dir = (dir + 3) % 4;
			robot[robot_num].dir = dir;
		}
		else { // 한 칸 전진
			int ny = y + dy[dir];
			int nx = x + dx[dir];
			if (1 > ny || ny > b || 1 > nx || nx > a) { // 범위 초과
				cout << "Robot " << robot_num  << " crashes into the wall";
				flag = false;
				break;
			}
			if (arr[ny][nx] != 0) { // 다른 로봇과 부딪힘
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
	robot.push_back({ 999999,99999,99999 }); // i번째 맞춰주기 위해 0번째에 값 넣어줌
	for (int i = 1; i <= n; i++) { // i번째 로봇의 상태
		int y, x; char dir;
		cin >> x >> y >> dir; // arr[y][x]로 하기 위해 좌표를 거꾸로 입력받음
		y = abs(b + 1 - y); // y의 값 변경
		dir = changeDir(dir);
		arr[y][x] = i;
		robot.push_back({ y,x,dir });
	}

	for (int i = 0; i < m; i++) { // 명령 순서
		int robot_num; char oper; int cnt;
		cin >> robot_num >> oper >> cnt;
		go(robot_num, oper, cnt);
		if (flag == false) return 0;
	}
	cout << "OK";
	return 0;
}