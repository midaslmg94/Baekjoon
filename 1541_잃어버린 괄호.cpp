#include<iostream>
using namespace std;
/* 숫자와 기호 분리
 입력을 어떻게 받을까 : 
 '-'뒤에서부터 묶기 시작해서 새로운 '-'가나오면 닫기
 input :  54-5+12+52-65+42-2+157-5
 처리 : 54-(5+12+52)-(65+42)-(2+157)-5
*/

string str;
int main() {    
    cin >> str;
    int res = 0;
    string tmp="";
    for (int i = 0; i < str.size(); i++) {
        if ('0' <= str[i] && str[i]<='9') {
            tmp += str[i];
        }
        else if (str[i] == '+') {

        }
    }
}