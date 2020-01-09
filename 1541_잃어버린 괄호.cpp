#include<iostream>
#include<string>

/*

 55-(10+245+21)-45-5-(123+124+1)
*/
using namespace std;
string str;
int sum = 0;
int main() {
	cin >> str;
	string tmp = "";
	bool is_first = true;
	bool minus = false;
	for (int i = 0; i <= str.size(); i++) {
		if ('0' <= str[i] && str[i] <= '9') {
			tmp += str[i];
		}
		else {
			int num = stoi(tmp);
			if (minus) {
				sum -= num;
			}
			else {
				sum += num;
			}
			tmp = "";

			if (str[i] == '-') {
				minus = true;
			}
		}
	}
	cout << sum ;
}