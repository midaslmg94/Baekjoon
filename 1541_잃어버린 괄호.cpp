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
			/* minus 부분 처리를 제대로 하지 못했었다. 또한 처음에 들어오는 수를 따로 처리하려고 생각해서 더 못풀었다*/
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