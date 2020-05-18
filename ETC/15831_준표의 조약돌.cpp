#include <bits/stdc++.h>
#define endl "\n"
#define MAX 10
using namespace std;
int n, black, white;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt", "r", stdin);
    cin >> n >> black >> white;
    string str;
    int start = 0;
    int end = 1;
    int answer = 0;
    int cnt_white = 0;
    int cnt_black = 0;
    cin >> str;

    if (n == 1) {
        if (str[0] == 'W')
            cnt_white++;
        else
            cnt_black++;
        if (cnt_black > black) {  // 검정색 초과 -> 가진것에서 맨 앞 한 개 버림
            cout << 0;
            return 0;
        } else if (cnt_white < white)  // 흰색 부족 -> 1개 추가, 조건을 만족하지는 않음
        {
            cout << 0;
            return 0;
        } else {
            cout << 1;
            return 0;
        }
    }
    deque<char> dq;
    dq.push_back(str[0]);
    dq.push_back(str[1]);
    if (str[0] == 'W')
        cnt_white++;
    else
        cnt_black++;
    if (str[1] == 'W')
        cnt_white++;
    else
        cnt_black++;
    // 검정색은 적게, 흰색은 많이
    while (end < str.size()) {
        for (int i = 0; i < dq.size(); i++) {
            //cout<<dq[i]<<' ';
        }
        // cout<<"  white:"<<cnt_white<<"  black:"<<cnt_black<<endl;
        if (cnt_black > black) {  // 검정색 초과 -> 가진것에서 맨 앞 한 개 버림
            char rock = str[start++];
            if (rock == 'W')
                cnt_white--;
            else
                cnt_black--;
            dq.pop_front();
        } else if (cnt_white < white)  // 흰색 부족 -> 1개 추가, 조건을 만족하지는 않음
        {
            char rock = str[++end];
            if (rock == 'W')
                cnt_white++;
            else
                cnt_black++;
            dq.push_back(rock);
        } else {
            char rock = str[++end];
            if (rock == 'W')
                cnt_white++;
            else
                cnt_black++;
            int num = dq.size();
            dq.push_back(rock);
            answer = max(answer, num);  // 조건을 만족하는 경우에만
                                        // cout<<" answer:"<<answer<<' '<<endl;
        }
    }
    cout << answer;
    return 0;
}