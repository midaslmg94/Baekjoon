#include <bits/stdc++.h>

#include <string>
#include <vector>
#define MAX 501
using namespace std;
int stay_stage[MAX];  // 현재 사람들이 머물러있는 스테이지
float fail_rate[MAX]; // 각 스테이지 마다 실패율
struct INFO {
    float f_rate;
    int num;
};
bool operator<(INFO a, INFO b) { // 실패율이 높은 스테이지부터 내림차순
    if (a.f_rate < b.f_rate)
        return true;
    else if (a.f_rate == b.f_rate) { // 실패율이 같은 스테이지는 작은 번호의 스테이지가 먼저
        if (a.num > b.num) return true;
        return false;
    }
    return false;
}
vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    for (int i = 0; i < stages.size(); i++) {
        stay_stage[stages[i]] += 1;
    }
    int stage = N;
    int people = stages.size();
    for (int i = 1; i <= N; i++) {
        if (people == 0) {
            fail_rate[i] = 0;
            continue;
        }
        fail_rate[i] = (float)stay_stage[i] / people;
        people -= stay_stage[i];
    }

    priority_queue<INFO, vector<INFO>> pq; // pair의 빠름 내림, 오름차순 정리를 위해 우선순위 큐
    for (int i = 1; i <= N; i++) {
        // cout<<fail_rate[i]<<' ';
        pq.push({fail_rate[i], i});
    }
    while (!pq.empty()) {
        answer.push_back(pq.top().num);
        //cout<<pq.top().num<<' ';
        pq.pop();
    }
    return answer;
}
int main() {
    int N;
    vector<int> stages;
    solution(N, stages);
}