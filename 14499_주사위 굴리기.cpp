#include<iostream>
#include<algorithm>
#include<string.h>
#include<queue>
using namespace std;
int map[20][20];
int n, m, x, y, k;
/*
	dice[0] = 안씀 (제외)
	dice[1] = 정면
	dice[2] = 뒷면
	dice[3] = 왼쪽면
	dice[4] = 오른쪽면
	dice[5] = 윗면
	dice[6] = 아랫면 (밑바닥)
*/
int dice[7] = { -99, 0, 0, 0, 0, 0, 0 };

void rollDice(int order, int nx, int ny) {
	if (order == 1) { // 동쪽으로 이동 : 정면, 뒷면 고정
		swap(dice[3], dice[6]);
		swap(dice[4], dice[5]);
		swap(dice[5], dice[6]);
	}
	else if (order == 2) { //서쪽으로 이동 : 정면, 뒷면 고정 
		swap(dice[3], dice[5]);
		swap(dice[4], dice[6]);
		swap(dice[5], dice[6]);
	}
	else if (order == 3) {//북쪽으로 이동 : 왼쪽면, 오른쪽면 고정
		swap(dice[1], dice[6]);
		swap(dice[2], dice[5]);
		swap(dice[5], dice[6]);
	}
	else if (order == 4) {//남쪽으로 이동 : 왼쪽면, 오른쪽면 고정
		swap(dice[1], dice[5]);
		swap(dice[2], dice[6]);
		swap(dice[5], dice[6]);
	}
}

bool canGo(int order, int nx, int ny) {	
	if (order == 1) { // 동쪽으로 이동가능? ny값 1증가	
		if (ny+1>=m ) {
			return false;
		}
	}
	else if (order == 2) { // 서쪽으로 이동가능? ny값 1감소		
		if (ny-1<0 ) {			
			return false;
		}
	}
	else if (order == 3) { // 북쪽으로 이동가능? nx값 1감소		
		if (nx-1<0 ) {			
			return false;
		}
	}
	else if (order == 4) {  // 남쪽으로 이동가능? nx값 1증가	
		if (nx+1>=n ) {
			return false;
		}
	}
	return true;
}

int main() {	
	ios::sync_with_stdio(false);
	cin.tie(NULL);	cout.tie(NULL);
	cin >> n >> m >> x >> y >> k; 
	for (int i = 0; i < n; i++) { // x값 증가
		for (int j = 0; j < m; j++) { // y값 증가
			cin >> map[i][j];
		}
	}
	queue<int>q; // 명령
	for (int i = 0; i < k; i++) {
		int tmp; cin >> tmp;
		q.push(tmp);
	} 

	// 현재 주사위의 위치
	int nx = x; int ny = y;	
	while (!q.empty()) {
		int order = q.front();
		q.pop();
		if (!canGo(order, nx, ny)) { // 바깥으로 이동하는 경우 명령 무시.출력 X
			continue;
		}		
		if (order == 1) { // 동쪽으로 이동, ny값 1증가,
			++ny;			
		}
		else if (order == 2) { // 서쪽으로 이동, ny값 1감소,
			--ny;
		}
		else if (order == 3) { // 북쪽으로 이동, nx값 1감소,
			--nx;
		}
		else if (order == 4) {  // 남쪽으로 이동, nx값 1증가,
			++nx;
		}
		int num = map[nx][ny]; // 이동하는 위치에 쓰여진 숫자
		rollDice(order, nx, ny);
		if (num == 0) { //이동한 칸에 쓰여 있는 수가 0이면, 주사위의 바닥면에 쓰여 있는 수가 칸에 복사된다. 바닥면 : dice[6]
			map[nx][ny] = dice[6];  // 여기서 num = dice[6] 이라고 실수함
		}
		else { //0이 아닌 경우에는 칸에 쓰여 있는 수가 주사위의 바닥면으로 복사되며, 칸에 쓰여 있는 수는 0이 된다.
			dice[6] = num;
			map[nx][ny] = 0;
		}
		cout << dice[5]<<endl; // 주사위의 맨 윗면 출력
	}
}