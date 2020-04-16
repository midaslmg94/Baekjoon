#include<iostream>
#include<string>
#include<deque>
using namespace std;
deque<int>dq;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T; // 테스트 케이스	
	string func;// 수행할 명령, R:배열 뒤집기, D:맨앞원소 삭제
	int n; // 배열의 개수	
	string arr;
	cin >> T;
	while (T--) {
		dq.clear();
		cin >> func;
		cin >> n;	
		cin >> arr;// [1,21,100,4] 와 같이 입력. 쉼표를 없애고 숫자를 int형으로 바꿔서 덱에 넣자		
		string tmp = "";
		// 전처리
		if (n != 0) { // n=0 일경우 덱에 입력할 필요없음
			for (int i = 1; i < arr.size() - 1; i++) {
				if ('0' <= arr[i] && arr[i] <= '9') {
					tmp += arr[i];
				}
				else {
					dq.push_back(stoi(tmp));
					tmp = "";
				}
			}
			dq.push_back(stoi(tmp));// 마지막 원소 입력
		}

		//명령처리
		bool reverse = false;
		bool is_empty = false;
		for (int i = 0; i < func.size(); i++) {
			if (func[i] == 'R') { 
				reverse=!reverse;
			}
			else {
				//배열이 비었을 경우
				if (dq.empty()) {
					is_empty = true;
					break;
				}
				if (!reverse) {// 정순일 경우
					dq.pop_front();
				}
				else {//역순일 경우
					dq.pop_back();
				}
			}
		}
		
		//출력처리 
		if (is_empty) {
			cout << "error\n";
		}
		else {
			if (dq.empty()) {
				cout << "[]\n";
			}
			else {
				cout << "[";
				while (!dq.empty()) {
					if (!reverse) {
						cout << dq.front();
						dq.pop_front();
					}
					else {
						cout << dq.back();
						dq.pop_back();
					}
					if(dq.size()>=1) //쉼표처리
						cout << ",";
				}
				cout << "]\n";				
			}
		}
	}
}