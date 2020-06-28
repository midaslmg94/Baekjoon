#include <bits/stdc++.h>
#define endl "\n"
#define MAX 10
using namespace std;
vector<long long> v1;  // 윤형이의 빌딩
vector<long long> v2;  // 동혁이의 빌딩
int n;

long long calc(long long height) {  // height : 만들어야할 빌딩의 중간 높이
    long long res = 0;
    int mid = n / 2;
    int left = mid - 1, right = mid + 1;
    res = abs(v1[mid] - height) + abs(v2[mid] - height);
    while (0 <= left && right < n) {
        height++;
        res += (abs(v1[left] - height) + abs(v1[right] - height));  // 윤형이가 블럭을 쌓/빼는 횟수
        res += (abs(v2[left] - height) + abs(v2[right] - height));  // 동혁이가 블럭을 쌓/빼는 횟수
        left--;                                                     // 각각 한 칸씩 옆으로 이동
        right++;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 0; i < n; i++) {
        long long tmp;
        cin >> tmp;
        v1.push_back(tmp);
    }
    for (int i = 0; i < n; i++) {
        long long tmp;
        cin >> tmp;
        v2.push_back(tmp);
    }
    long long ans = 0;
    long long left = 0;
    long long right = 1e12-n/2; // 최대 빌딩의 높이 : 
    long long min_block = 0, max_block = 0;
    min_block = calc(left);
    max_block = calc(right);
    while (left <= right) {
        long long mid = (left + right) / 2;
        if (min_block < max_block) {
            right = mid - 1;
            max_block = calc(right);
        } else {
            left = mid + 1;
            min_block = calc(left);
        }
    }
    cout << (min_block < max_block ? min_block : max_block) << endl;
    return 0;
}