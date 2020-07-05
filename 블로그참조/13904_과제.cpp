#include <bits/stdc++.h>
#define endl "\n"
#define MAX 1001
using namespace std;

int n;
struct TASK {
    int restDate;
    int score;
};
int scores[MAX];
bool cmp(TASK a, TASK b) {  // 얻는 점수가 큰 순 마감일이 빠른 순
    if (a.score == b.score) {
        return a.restDate < b.restDate;
    }
    return a.score > b.score;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt", "r", stdin);
    cin >> n;
    vector<TASK> task;
    for (int i = 0; i < n; i++) {
        int d, s;
        cin >> d >> s;
        task.push_back({d, s});
    }
    sort(task.begin(), task.end(), cmp);
    for (auto a : task) {
        //cout << a.score << ' ' << a.restDate << endl;
    }

    for(int i=0; i<n; i++){
        for(int j=task[i].restDate; j>0; j--){
            if(scores[j]==0){ // 해당 날짜에 과제를 할 수 있음
                scores[j]=task[i].score;
                break;
            }
        }
    }
    
    int answer = 0;
    for(int i=0; i<MAX; i++){
        answer+=scores[i];
    }
    cout<<answer;

    return 0;
}