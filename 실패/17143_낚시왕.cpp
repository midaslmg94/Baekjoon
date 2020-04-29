#include <bits/stdc++.h>
#define endl "\n"
#define MAX 100 + 1
using namespace std;
struct SHARK {  // 상어의 정보
    int y;
    int x;
    int s;  // 속력
    int d;  // 방향
    int z;  // 크기
};
struct INFO {  // 현재 위치에 있는 상어의 정보
    int idx;   // 몇번 상어인지
    int size;  // 상어의 크기
};
int r, c, m;
deque<INFO> board[MAX][MAX];  // 보드판의 정보
vector<SHARK> shark;          // 상어의 정보
int answer = 0;
int y, x, s, d, z;
int dy[] = {0, -1, 1, 0, 0};  // 상,하,좌,우
int dx[] = {0, 0, 0, 1, -1};
bool cmp(INFO a, INFO b) {
    if (a.size > b.size) return true;
    return false;
}
void prt() {
    for (int i = 0; i < shark.size(); i++) {
        cout << shark[i].y << ' ' << shark[i].x << ' ' << shark[i].s << ' ' << shark[i].d << ' ' << shark[i].z << ' ';
        cout << endl;
    }
    cout << endl
         << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt", "r", stdin);
    cin >> r >> c >> m;
    for (int i = 0; i < m; i++) {
        cin >> y >> x >> s >> d >> z;
        shark.push_back({y, x, s, d, z});
        board[shark[i].y][shark[i].x].push_back({i, shark[i].z});  // {i번 상어, 크기}
    }
    for (int turn = 1; turn <= c; turn++) {  // 낚시왕이 한 칸 이동
        for (int i = 1; i <= r; i++) {       // 낚시왕이 상어를 잡음 -> 상어가 사라짐
            if (board[i][turn].size() != 0) {
                answer += board[i][turn].front().size;    // 상어의 크기만큼 추가
                shark[board[i][turn].front().idx].z = 0;  // 크기가 0이면 죽은 것
                board[i][turn].front().size = 0;          // 상어 삭제
                break;
            }
        }
        // 상어 이동
        for (int j = 0; j < m; j++) {
            if (shark[j].z == 0) continue;
            int y = shark[j].y;
            int x = shark[j].x;
            int dir = shark[j].d;
            int speed = shark[j].s;
            board[y][x].pop_front();  // 해당 위치에서 상어 뺌
            if (dir == 1 || dir == 2) {
                int rotate = (r - 1) * 2;  // 이 만큼 지나면 원래 방향을 가지고 원래 자리로 돌아옴
                if (speed >= rotate) speed = speed % rotate;
                for (int k = 0; k < speed; k++) {
					int ny = y + dy[dir];
					int nx = x + dx[dir];
					
				}

            } else {
            }
            // 새 위치로 변경
            shark[j].y = y;
            shark[j].x = x;
            shark[j].d = dir;
            board[y][x].push_back({j, shark[j].z});
            //prt();
        }
        // 같은 칸에 2마리 이상의 상어 -> 크기가 작은 상어는 다 죽음
        for (int i = 1; i <= r; i++) {
            for (int j = 1; j <= c; j++) {
                if (board[i][j].size() > 1) {
                    sort(board[i][j].begin(), board[i][j].end(), cmp);
                    // 한마리 남을때 까지 뺌
                    while (board[i][j].size() != 1) {
                        board[i][j].pop_back();
                    }
                }
            }
        }
    }
    cout << answer;
    return 0;
}