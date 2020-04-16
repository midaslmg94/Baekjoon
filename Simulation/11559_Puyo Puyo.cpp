#include<iostream>
#include<queue>
#include<string.h>
using namespace std;
char arr[12][6];
bool visit[12][6];
int chain = 0;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

void tmp_print() {
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			cout << arr[i][j];
		}
		cout << endl;
	}
}

void move() { // 폭발이후 중력에 의해 뿌요가 밑으로 이동
	for (int i = 11; i >= 0; i--) {
		for (int j = 5; j >= 0; j--) {
			int dist = 0;
			if (arr[i][j] == '.') {// 위로(y축) 올라가면서 떠있는 뿌요가 있는지 확인
				for (int k = i; k >= 0; k--) {
					if (arr[k][j] == '.') {
						dist++;
					}
					else {
						// 밑에서 부터 떨어진 거리만큼 뿌요를 밑으로 이동
						while (dist--) {
							arr[k + 1][j] = arr[k][j];
							arr[k][j] = '.'; // 이부분 생각을 잘 못했음
							k++;
						}
						break;
					}
				}
			}
		}
	}
}
void explode() { // 4개이상의 경우 뿌요가 폭발
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			if (visit[i][j] == true) { // 방문여부로 확인
				arr[i][j] = '.';
			}
		}
	}
}

int bfs(int y, int x) {
	queue<pair<int, int>>q;
	q.push({ y,x });
	visit[y][x] = true;
	char color = arr[y][x];
	int cnt = 1; // 몇개의 뿌요가 연결되어 있는지
	while (!q.empty()) {
		y = q.front().first;
		x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			char new_color = arr[ny][nx];
			// 다음번 뿌요가 범위 안에 있고, 방문을 안했었어야 하고, color가 같아야 함
			if (0 <= nx && nx < 6 && 0 <= ny && ny < 12 && !visit[ny][nx] && new_color == color) {
				visit[ny][nx] = true;
				q.push({ ny,nx });
				cnt++;
			}
		}
	}
	return cnt;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);	cout.tie();
	freopen("input.txt", "r", stdin);
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			cin >> arr[i][j];
		}
	}
	bool is_explode = true;
	while (is_explode) {
		int puyo = 0; // 연결된 뿌요의 개수
		is_explode = false; // 폭발의 발생여부 초기화
		for (int i = 0; i < 12; i++) {
			for (int j = 0; j < 6; j++) {
				if (arr[i][j] != '.' && !visit[i][j]) {
					puyo = bfs(i, j);
					//cout << "color:" << arr[i][j] << " puyo cnt:" << puyo << endl;
					if (puyo >= 4) { // 4개이상 뿌요가 뭉쳐있다 --> 폭발
						explode();
						//tmp_print(); 	cout << endl<<chain<<endl;
						is_explode = true; // 폭발 발생
					}
				}
			memset(visit, false, sizeof(visit));
			}
		}
		//터질 수 있는 뿌요가 여러 그룹이 있다면 동시에 터져야 하고 여러 그룹이 터지더라도 한번의 연쇄가 추가된다.
		if(is_explode)
			chain++;
		
		move(); // 떠있는 뿌요들이 밑으로 내려옴
	}
	// 하나도 터지지 않는다면 0을 출력해야한다
	cout << chain;
}