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
			if (str[i] == '<') { // �������� Ŀ�� �̵�
				if (iter == password.begin()) {
					continue;
				}
				iter--;
			}
			else if (str[i] == '>') {// ���������� Ŀ�� �̵�
				if (iter == password.end()) {
					continue;
				}
				iter++;
			}
			/*
			'<'��  '>'�� ����� �� 

			ó���� Ǯ���� ���� �ڵ�
			
			else if (tmp == '-') {//�տ� ���ڰ� �ִٸ� ����
				if (iter != password.begin()){
					ans.erase(iter);
				}
			}
			else {
				ans.insert(iter,tmp);
				iter++;
			}
			*/					   			 		  
			else if (str[i] == '-') {// �տ� ���ڰ� �ִٸ� ����, iter�� ������ �������� �� ĭ �Ű���
				if (iter == password.begin()) {
					continue;
				}
				/*�� �κ��� ����������

				  1. 36�� line�� 37�� line�� ������ �ٲ������
				  2. iter�� password.erase(iter)�� �־����� �ʾ���

				*/
				iter--;
				iter = password.erase(iter); // �� �̷��� �ϴ°���?

			}
			else {
				password.insert(iter, str[i]);
			}
		}

		/*��� ����*/
		list<char>::iterator it;
		for (it = password.begin(); it != password.end(); it++) {
			cout << *it;
		}
		cout << endl;
		password.clear();
	}

}