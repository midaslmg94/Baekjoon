#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    vector<pii> left_hand;
    vector<pii> right_hand;

    pii phone[10] = {
        {3, 1}, //0
        {0, 0}, 
        {0, 1},
        {0, 2},
        {1, 0},
        {1, 1},
        {1, 2},
        {2, 0},
        {2, 1},
        {2, 2}};

    left_hand.push_back({3, 0});
    right_hand.push_back({3, 2});

    for (int i = 0; i < numbers.size(); i++) {
        int cur = numbers[i];
        if (cur == 1 || cur == 4 || cur == 7) {  // 왼손
            answer+="L";
            left_hand.pop_back();
            left_hand.push_back(phone[cur]);

        } else if (cur == 3 || cur == 6 || cur == 9) {  // 오른손
            answer+="R";
            right_hand.pop_back();
            right_hand.push_back(phone[cur]);
        } else {
            int right_dist = abs(phone[cur].first - right_hand.front().first) + abs(phone[cur].second - right_hand.front().second);
            int left_dist = abs(phone[cur].first - left_hand.front().first) + abs(phone[cur].second - left_hand.front().second);

            if (right_dist > left_dist) {  // 왼손이 더 가까움
                left_hand.pop_back();
                left_hand.push_back(phone[cur]);
                answer+="L";
            } else if (right_dist < left_dist) {  // 오른손이 더 가까움
                right_hand.pop_back();
                right_hand.push_back(phone[cur]);
                answer+="R";
            } else {  // 거리가 같은 경우
                if (hand == "right") {
                    answer += "R";
                    right_hand.pop_back();
                    right_hand.push_back(phone[cur]);


                } else {
                    answer += "L";
                    left_hand.pop_back();
                    left_hand.push_back(phone[cur]);

                }
            }
        }
    }

    return answer;
}

int main() {
    ios::sync_with_stdio(false);
    vector<int> numbers;
    numbers = {1, 3, 4, 5, 8, 2, 1, 4, 5, 9, 5};
    string ans = solution(numbers, "left");
    cout << ans;
    return 0;

    /*
    테스트 1 〉	통과 (0.01ms, 3.81MB)
테스트 2 〉	통과 (0.00ms, 3.76MB)
테스트 3 〉	통과 (0.01ms, 3.79MB)
테스트 4 〉	통과 (0.00ms, 3.85MB)
테스트 5 〉	통과 (0.01ms, 3.91MB)
테스트 6 〉	통과 (0.00ms, 3.88MB)
테스트 7 〉	통과 (0.00ms, 3.91MB)
테스트 8 〉	통과 (0.01ms, 3.86MB)
테스트 9 〉	통과 (0.01ms, 3.85MB)
테스트 10 〉	통과 (0.01ms, 3.78MB)
테스트 11 〉	통과 (0.01ms, 3.86MB)
테스트 12 〉	통과 (0.01ms, 3.9MB)
테스트 13 〉	통과 (0.01ms, 3.86MB)
테스트 14 〉	통과 (0.01ms, 3.86MB)
테스트 15 〉	통과 (0.02ms, 3.91MB)
테스트 16 〉	통과 (0.02ms, 3.75MB)
테스트 17 〉	통과 (0.04ms, 3.77MB)
테스트 18 〉	통과 (0.04ms, 3.84MB)
테스트 19 〉	통과 (0.03ms, 3.78MB)
테스트 20 〉	통과 (0.03ms, 3.91MB)
    
    
    */
}