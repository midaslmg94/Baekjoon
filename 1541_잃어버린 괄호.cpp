#include<iostream>
using namespace std;
/* ���ڿ� ��ȣ �и�
 �Է��� ��� ������ : 
 '-'�ڿ������� ���� �����ؼ� ���ο� '-'�������� �ݱ�
 input :  54-5+12+52-65+42-2+157-5
 ó�� : 54-(5+12+52)-(65+42)-(2+157)-5
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