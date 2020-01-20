#include<iostream>
#include<vector>
#include<string.h>
#include<algorithm>
using namespace std;
int L, C;
bool check(string str) {
    int vowel_cnt = 0; 
    int consonant_cnt = 0;
    for (int i = 0; i < str.size(); i++) {
        char tmp = str[i];
        if (tmp == 'a' || tmp == 'e' || tmp == 'i' || tmp == 'o' || tmp == 'u') {
            vowel_cnt++;
        }
        else {
            consonant_cnt++;
        }
    }

    if (vowel_cnt < 1 || consonant_cnt < 2)
        return false;
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("input.txt", "r", stdin);
    cin >> L >> C; // ���� : L
    vector<char>alpha;
    for (int i = 0; i < C; i++) {
        char tmp;
        cin >> tmp;
        alpha.push_back(tmp);
    }
    vector<int>select;// C�� �� L�� �̱�
    for (int i = 1; i <= C; i++) {
        if (i <= L)
            select.push_back(1);
        else {
            select.push_back(0);
        }
    }
    sort(select.begin(), select.end(), greater<int>());
    sort(alpha.begin(), alpha.end());
    do {
        string str = "";
        for (int i = 0; i < select.size(); i++) {
            if (select[i] == 1) {
                str+=alpha[i];
            }            
        }
        if(check(str)) //  �ּ� �� ���� ������ �ּ� �� ���� �������� �����Ǿ����� Ȯ��
            cout <<str<< "\n";
    } while (prev_permutation(select.begin(), select.end()));
}