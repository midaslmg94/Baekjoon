#include<iostream>
#include<string>
#include<deque>
using namespace std;
deque<int>dq;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T; // �׽�Ʈ ���̽�	
	string func;// ������ ���, R:�迭 ������, D:�Ǿտ��� ����
	int n; // �迭�� ����	
	string arr;
	cin >> T;
	while (T--) {
		dq.clear();
		cin >> func;
		cin >> n;	
		cin >> arr;// [1,21,100,4] �� ���� �Է�. ��ǥ�� ���ְ� ���ڸ� int������ �ٲ㼭 ���� ����		
		string tmp = "";
		// ��ó��
		if (n != 0) { // n=0 �ϰ�� ���� �Է��� �ʿ����
			for (int i = 1; i < arr.size() - 1; i++) {
				if ('0' <= arr[i] && arr[i] <= '9') {
					tmp += arr[i];
				}
				else {
					dq.push_back(stoi(tmp));
					tmp = "";
				}
			}
			dq.push_back(stoi(tmp));// ������ ���� �Է�
		}

		//���ó��
		bool reverse = false;
		bool is_empty = false;
		for (int i = 0; i < func.size(); i++) {
			if (func[i] == 'R') { 
				reverse=!reverse;
			}
			else {
				//�迭�� ����� ���
				if (dq.empty()) {
					is_empty = true;
					break;
				}
				if (!reverse) {// ������ ���
					dq.pop_front();
				}
				else {//������ ���
					dq.pop_back();
				}
			}
		}
		
		//���ó�� 
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
					if(dq.size()>=1) //��ǥó��
						cout << ",";
				}
				cout << "]\n";				
			}
		}
	}
}