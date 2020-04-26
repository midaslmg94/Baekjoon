#include <bits/stdc++.h>
using namespace std;
int n = 0;
vector<vector<int>> board;
bool boundary(int y, int x) {
    if (0 > y || y > n - 1 || 0 > x || x > n - 1) return false;
    return true;
}
bool drop(int y, int x) {  // 해당 위치로 벽돌이 떨어질 수 있는지 확인
    for (int i = y; i >= 0; i--) {
        if (board[i][x] != 0)
            return false;
    }
    return true;
}
/*
    1
    1 1 1  
*/
bool one(int y, int x) {
    int num = board[y][x];
    if (boundary(y, x + 1) && boundary(y, x + 2) && boundary(y + 1, x) && drop(y, x + 1) && drop(y, x + 2)) {
        if (board[y][x + 1] == 0 && board[y][x + 2] == 0 && board[y + 1][x] == num && board[y + 1][x + 1] == num && board[y + 1][x + 2] == num) {
            board[y][x] = 0;
            board[y + 1][x] = 0;
            board[y + 1][x + 1] = 0;
            board[y + 1][x + 2] = 0;
            return true;
        }
    }
    return false;
}
/*
        1
    1 1 1  
*/
bool two(int y, int x) {
    int num = board[y][x];
    if (boundary(y, x - 1) && boundary(y, x - 2) && boundary(y + 1, x) && drop(y, x - 1) && drop(y, x - 2)) {
        if (board[y][x - 1] == 0 && board[y][x - 2] == 0 && board[y + 1][x] == num && board[y + 1][x - 1] == num && board[y + 1][x - 2] == num) {
            board[y][x] = 0;
            board[y + 1][x] = 0;
            board[y + 1][x - 1] = 0;
            board[y + 1][x - 2] = 0;
            return true;
        }
    }
    return false;
}
/*
      1
    1 1 1  
*/
bool three(int y, int x) {
    int num = board[y][x];
    if (boundary(y, x + 1) && boundary(y, x - 1) && boundary(y + 1, x) && drop(y, x - 1) && drop(y, x + 1)) {
        if (board[y][x - 1] == 0 && board[y][x + 1] == 0 && board[y + 1][x] == num && board[y + 1][x + 1] == num && board[y + 1][x - 1] == num) {
            board[y][x] = 0;
            board[y + 1][x] = 0;
            board[y + 1][x + 1] = 0;
            board[y + 1][x - 1] = 0;
            return true;
        }
    }
    return false;
}
/*
    1
    1 
    1 1  
*/
bool four(int y, int x) {
    int num = board[y][x];
    if (boundary(y, x + 1) && boundary(y + 1, x) && boundary(y + 2, x) && drop(y + 1, x + 1)) {
        if (board[y][x + 1] == 0 && board[y + 1][x + 1] == 0 && board[y + 1][x] == num && board[y + 2][x] == num && board[y + 2][x + 1] == num) {
            board[y][x] = 0;
            board[y + 1][x] = 0;
            board[y + 2][x] = 0;
            board[y + 2][x + 1] = 0;
            return true;
        }
    }
    return false;
}
/*
        1
        1  
      1 1 
*/
bool five(int y, int x) {
    int num = board[y][x];
    if (boundary(y, x - 1) && boundary(y + 1, x) && boundary(y + 2, x) && drop(y + 1, x - 1)) {
        if (board[y][x - 1] == 0 && board[y + 1][x - 1] == 0 && board[y + 1][x] == num && board[y + 2][x] == num && board[y + 2][x - 1] == num) {
            board[y][x] = 0;
            board[y + 1][x] = 0;
            board[y + 2][x] = 0;
            board[y + 2][x - 1] = 0;
            return true;
        }
    }
    return false;
}
int solution(vector<vector<int>> inp) {
    for (int i = 0; i < inp.size(); i++) {
        vector<int> tmp;
        for (int j = 0; j < inp.size(); j++) {
            tmp.push_back(inp[i][j]);
        }
        board.push_back(tmp);
    }
    int answer = 0;
    bool flag = true;
    n = board.size();
    while (flag) {
        flag = false;
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < n; i++) {
                if (board[i][j] == 0) continue;
                if (one(i, j)) {
                    answer++;
                    flag = true;
                    break;
                } else if (two(i, j)) {
                    answer++;
                    flag = true;
                    break;
                } else if (three(i, j)) {
                    answer++;
                    flag = true;
                    break;
                } else if (four(i, j)) {
                    answer++;
                    flag = true;
                    break;
                } else if (five(i, j)) {
                    answer++;
                    flag = true;
                    break;
                }
            }
            if (flag) {  // 다시 처음부터 확인
                break;
            }
        }
    }
    return answer;
}