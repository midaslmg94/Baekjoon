#include <bits/stdc++.h>
#define endl "\n"
#define MAX 4
using namespace std;
struct Shark {
    int y;
    int x;
    int d;
    int eat;
};

struct Fish {
    int y;
    int x;
    int num;
    int d;
};

struct Board {
    int fish;
    int d;
};

int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};  // 하나씩 넘어갈 때 마다, 45도 반시계로 회전
int dx[8] = {0, -1, -1, -1, 0, 1, 1, 1};

void swapBoard(Board &a, Board &b) {  // 두 물고기의 위치 바꿈
    Board tmp;
    tmp = a;
    a = b;
    b = tmp;
}
bool cmp(Fish a, Fish b) {
    return a.num < b.num;
}
Board board[MAX][MAX];
vector<Fish> fish;
Shark shark;

void moveFish() {
    fish.clear();
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (board[i][j].fish != 0) {
                fish.push_back({i, j, board[i][j].fish, board[i][j].d});
            }
        }
    }
    sort(fish.begin(), fish.end(), cmp);
    cout << "\nFISH \n";
    for (int a = 0; a < fish.size(); a++) {
        cout << fish[a].num << ' ' << fish[a].y << ' ' << fish[a].x << ' ' << fish[a].d << ' ' << endl;
    }
    cout << endl;
    for (int i = 0; i < fish.size(); i++) {
        // 해당 위치가 비어있거나, 물고기가 있는 지 확인
        int y = fish[i].y;
        int x = fish[i].x;
        for (int j = 0; j < 8; j++) {
            int ny = y + dy[(fish[i].d + j) % 8];
            int nx = x + dx[(fish[i].d + j) % 8];
            if (0 > ny || ny > MAX || 0 > nx || nx > MAX) continue;  // 범위 초과
            if (shark.y == ny && shark.x == nx) continue;            // 상어가 있음
            // 물고기 바꾸기
            swapBoard(board[y][x], board[ny][nx]);
            break;
        }
    }
}

int moveShark() {
    int eat = 0;
    int dir = shark.d;
    int y = shark.y;
    int x = shark.x;
    vector<Fish> candi;  // 먹을 후보들
    while (true) {
        y += dy[dir];
        x += dx[dir];
        if (0 > y || y > MAX || 0 > x || x > MAX) break;  // 범위 초과
        if (board[y][x].fish) candi.push_back({board[y][x].fish, board[y][x].d});
    }
    cout << "\n CANDI\n";
    sort(candi.begin(), candi.end(), cmp);
    for (int a = 0; a < candi.size(); a++) {
        cout << candi[a].num << ' ' << candi[a].y << ' ' << candi[a].x << ' ' << candi[a].d << ' ' << endl;
    }

    shark.y = candi.back().y;
    shark.x = candi.back().x;
    eat = candi.back().num;
   // cout << candi.back().num << ' ' << candi.back().y << ' ' << candi.back().x << ' ' << endl;
    return eat;
}

void prtFish() {
    cout << "\n================================\n";
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cout << board[i][j].fish << ' ';
        }
        cout << endl;
    }
    cout << "================================\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt", "r", stdin);
    int n, d;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> n >> d;
            board[i][j].fish = n;
            board[i][j].d = d;
            fish.push_back({i, j, n, d - 1});  // 방향이 1부터 인것을 0으로 바꿈
        }
    }
    // 상어가 0,0에 들어감
    shark.y = 0;
    shark.x = 0;
    shark.d = board[0][0].d;
    shark.eat = board[0][0].fish;
    board[0][0].d = 0;
    board[0][0].fish = 0;

    while (true) {
        prtFish();
        moveFish();             // 물고기 움직임
        int res = moveShark();  // 상어 움직임
        if (res == 0) break;
        shark.eat += res;
    }

    cout << shark.eat;

    return 0;
}