#include <bits/stdc++.h>
#define endl "\n"
#define MAX 51
#define pii pair<int,int>
using namespace std;
struct GROUND {//땅의 상태	
	int red; // 빨간색 배양액이 뿌려진 시점
	int green; // 초록색 배양액이 뿌려진 시점
	bool flower; // 꽃이 피어나는지 확인
};
struct INFO {
	string color;
	int y;
	int x;
	int t;
};
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
int n, m, g, r;
vector<pii>candi_space; // 배양액 심을 수 있는 땅(최대 10개)
vector<pii>green; // 배양액 심을 수 있는 땅(최대 10개)
vector<pii>red; // 배양액 심을 수 있는 땅(최대 10개)
int answer = -1;
bool checked[MAX];
int board[MAX][MAX];
GROUND new_board[MAX][MAX];	

int bfs(vector<pii>green, vector<pii>red){ // 호수 빼고 다 퍼질 수 있음
	int flower = 0;
	queue<INFO>q; // 색, y, x, time
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){			
			new_board[i][j].red = -1;
			new_board[i][j].green = -1;
			new_board[i][j].flower = false;
		}
	}
	// 시작 위치에 배양액을 뿌림
	for(int i=0; i<green.size(); i++){
		new_board[green[i].first][green[i].second].green = 0;
		q.push({"green", green[i].first, green[i].second, 0});
	}
	for(int i=0; i<red.size(); i++){
		new_board[red[i].first][red[i].second].red = 0;		
		q.push({"red", red[i].first, red[i].second, 0});		
	}

	while(!q.empty()){
		string color = q.front().color;
		int y = q.front().y; 
		int x = q.front().x; 
		int t = q.front().t;
		q.pop();

		if(color == "flower"){ // 꽃인 경우
			flower++;
		}
		else if(color =="green"){ // 초록 배양액 확산
			for(int d = 0; d<4; d++){
				int ny = y+dy[d];
				int nx = x+dx[d];	
				int nt = t+1;			
				if(0>ny||ny>n-1||0>nx||nx>m-1)continue;
				if(new_board[ny][nx].flower || board[ny][nx]==0)continue; // 꽃이거나 호수
				if(new_board[ny][nx].green>=0)continue; // 같은 색 존재 -> pass				
				if(new_board[ny][nx].red == nt){ // 다른 색 & 같은 시간 -> 꽃으로 변신
					new_board[ny][nx].flower = true;
					q.push({"flower", ny,nx,nt});
				}
				else if(new_board[ny][nx].red == -1 && new_board[ny][nx].green == -1) { // 빈 공간
					new_board[ny][nx].green = nt;
					q.push({"green", ny,nx,nt});
				}
			}
		}
		else{ // 빨강 배양액 확산
			for(int d = 0; d<4; d++){
				int ny = y+dy[d];
				int nx = x+dx[d];			
				int nt = t+1;	
				if(0>ny||ny>n-1||0>nx||nx>m-1)continue;
				if(new_board[ny][nx].flower || board[ny][nx]==0)continue; // 꽃이거나 호수
				if(new_board[ny][nx].red>=0)continue; // 같은 색 존재 -> pass
				if(new_board[ny][nx].green == nt){ // 다른 색 & 같은 시간 -> 꽃으로 변신
					new_board[ny][nx].flower = true;
					q.push({"flower",ny,nx,nt});
				}
				else if(new_board[ny][nx].red == -1 && new_board[ny][nx].green == -1){
					new_board[ny][nx].red = nt;
					q.push({"red", ny,nx,nt});
				}
			}
		}
	}
	return flower;
}
void dfs_red(int idx, int cnt){
	if(cnt == r){ // 남은 것 중 r개고름
		answer = max(answer, bfs(green, red));
		return;
	}
	for(int i=idx; i<candi_space.size(); i++){		
		if(checked[i])continue;
		checked[i] = true;
		red.push_back({candi_space[i].first, candi_space[i].second});
		dfs_red(i, cnt+1);	
		checked[i] = false;	
		red.pop_back();
	}
}

void dfs_green(int idx, int cnt){
	if(cnt == g){ // g개 고름		
		dfs_red(0, 0);
		return;
	}
	for(int i=idx; i<candi_space.size(); i++){		
		if(checked[i])continue;
		checked[i] = true;
		green.push_back({candi_space[i].first, candi_space[i].second});
		dfs_green(i, cnt+1);	
		checked[i] = false;	
		green.pop_back();
	}
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);
	
	cin >> n >> m >> g >> r;
	//  0은 호수, 1은 배양액을 뿌릴 수 없는 땅, 2는 배양액을 뿌릴 수 있는 땅을 의미한다.
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			if (board[i][j] == 2) {
				candi_space.push_back({ i,j }); // 배양액 가능
			}
		}
	}
	dfs_green(0, 0);
	cout << answer;
	return 0;
}