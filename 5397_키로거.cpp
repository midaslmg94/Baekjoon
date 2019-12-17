#include<iostream>
#include<list>
#include<string>

using namespace std;

int main() {
	int n;
	cin >> n;
	while (n--) {
		string str;
		cin >> str;
		list<char>password;	
		list<char>::iterator iter = password.begin();

		for (int i = 0; i < str.length(); i++) {
			if (str[i] == '<') { // 왼쪽으로 커서 이동
				if (iter == password.begin()) {
					continue;
				}
				iter--;
			}
			else if (str[i] == '>') {// 오른쪽으로 커서 이동
				if (iter == password.end()) {
					continue;
				}
				iter++;
			}
			/*
			'<'와  '>'는 제대로 함 

			처음에 풀었을 때의 코드
			
			else if (tmp == '-') {//앞에 문자가 있다면 삭제
				if (iter != password.begin()){
					ans.erase(iter);
				}
			}
			else {
				ans.insert(iter,tmp);
				iter++;
			}
			*/					   			 		  
			else if (str[i] == '-') {// 앞에 문자가 있다면 삭제, iter를 앞으로 왼쪽으로 한 칸 옮겨줌
				if (iter == password.begin()) {
					continue;
				}
				/*이 부분이 문제였었다

				  1. 36번 line과 37번 line의 순서가 바뀌었었음
				  2. iter에 password.erase(iter)을 넣어주지 않았음

				*/
				iter--;
				iter = password.erase(iter); // 왜 이렇게 하는거지?

			}
			else {
				password.insert(iter, str[i]);
			}
		}

		/*출력 주의*/
		list<char>::iterator it;
		for (it = password.begin(); it != password.end(); it++) {
			cout << *it;
		}
		cout << endl;
		password.clear();
	}

}