#include <bits/stdc++.h>
#define endl "\n"
#define MAX 100 + 1
using namespace std;
struct SHARK {  // ����� ����
    int y;
    int x;
    int s;  // �ӷ�
    int d;  // ����
    int z;  // ũ��
};
struct INFO {  // ���� ��ġ�� �ִ� ����� ����
    int idx;   // ��� �������
    int size;  // ����� ũ��
};
int r, c, m;
deque<INFO> board[MAX][MAX];  // �������� ����
vector<SHARK> shark;          // ����� ����
int answer = 0;
int y, x, s, d, z;
int dy[] = {0, -1, 1, 0, 0};  // ��,��,��,��
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
        board[shark[i].y][shark[i].x].push_back({i, shark[i].z});  // {i�� ���, ũ��}
    }
    for (int turn = 1; turn <= c; turn++) {  // ���ÿ��� �� ĭ �̵�
        for (int i = 1; i <= r; i++) {       // ���ÿ��� �� ���� -> �� �����
            if (board[i][turn].size() != 0) {
                answer += board[i][turn].front().size;    // ����� ũ�⸸ŭ �߰�
                shark[board[i][turn].front().idx].z = 0;  // ũ�Ⱑ 0�̸� ���� ��
                board[i][turn].front().size = 0;          // ��� ����
                break;
            }
        }
        // ��� �̵�
        for (int j = 0; j < m; j++) {
            if (shark[j].z == 0) continue;
            int y = shark[j].y;
            int x = shark[j].x;
            int dir = shark[j].d;
            int speed = shark[j].s;
            board[y][x].pop_front();  // �ش� ��ġ���� ��� ��
            if (dir == 1 || dir == 2) {
                int rotate = (r - 1) * 2;  // �� ��ŭ ������ ���� ������ ������ ���� �ڸ��� ���ƿ�
                if (speed >= rotate) speed = speed % rotate;
                for (int k = 0; k < speed; k++) {
					int ny = y + dy[dir];
					int nx = x + dx[dir];
					
				}

            } else {
            }
            // �� ��ġ�� ����
            shark[j].y = y;
            shark[j].x = x;
            shark[j].d = dir;
            board[y][x].push_back({j, shark[j].z});
            //prt();
        }
        // ���� ĭ�� 2���� �̻��� ��� -> ũ�Ⱑ ���� ���� �� ����
        for (int i = 1; i <= r; i++) {
            for (int j = 1; j <= c; j++) {
                if (board[i][j].size() > 1) {
                    sort(board[i][j].begin(), board[i][j].end(), cmp);
                    // �Ѹ��� ������ ���� ��
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