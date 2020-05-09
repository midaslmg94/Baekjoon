#include <bits/stdc++.h>
using namespace std;
long long answer = 0;
vector<char> oper;
vector<long long> num;
list<long long> my_num;
vector<char> my_oper;
string tmp;
long long solution(string expression) {
    vector<string> v;
    for (int i = 0; i < expression.size(); i++) {
        if (expression[i] == '*' || expression[i] == '+' || expression[i] == '-') {
            int t = stoi(tmp);
            num.push_back(t);
            oper.push_back(expression[i]);
            tmp = "";
        } else {
            tmp += expression[i];
        }
    }
    num.push_back(stoi(tmp));
    // 3가지 연산자 벡터에 저장
    vector<char> order = {'*', '+', '-'};
    do {
        long long res = 0;
        my_oper.clear();
        for(int i=0; i<num.size(); i++){
            my_num.push_back(num[i]);
        }
        for (int k = 0; k < 3; k++) {
            char op = order[k];
            auto it = my_num.begin();
            for (int i = 0; i < oper.size(); i++) {
                if (my_oper[i] == op) {
                    int f_num = it
                    if (op == '+') {
                        int re = my_num[it] + my_num[it + 1];
                        my_num.erase(it + i - 1, it + i);
                        my_num.insert()
                        my_num.push_back();
                    } else if (op == '-') {
                        my_num.erase(it + i - 1, it + i);
                        my_num.push_back(my_num[i] - my_num[i + 1]);
                    } else {
                        my_num.erase(it + i - 1, it + i);
                        my_num.push_back(my_num[i] * my_num[i + 1]);
                    }
                } else {
                    my_num.push_back(num[i]);
                }
            }
            cout << my_num[0] << endl;
        }
        answer = max(answer, abs(res));
    } while (next_permutation(order.begin(), order.end()));

    return answer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt", "r", stdin);
    string s;
    cin >> s;
    long long ans = solution(s);
    cout << ans;
    return 0;
}