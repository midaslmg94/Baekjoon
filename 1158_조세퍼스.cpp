#include<iostream>
#include<deque>
using namespace std;
int main() {
	int n, k;
	cin >> n >> k;
	deque<int> dq;
	deque<int>::iterator iter;
	for (int i = 0; i < n; i++) {
		dq.push_back(i + 1);
	}
	iter = dq.begin();
	cout << '<';
	while (!dq.empty()) {
		for (int i = 0; i < k - 1; i++) { // k번째 사람을 제거하기 위함. 시작 인덱스가 0이므로  i의 범위는 k-1미만
			if (iter == dq.end() - 1) {// 마지막에 가면
				iter = dq.begin();

				continue;
			}
			else {
				iter++;
			}
		}
		cout << *iter;
		if (iter == dq.end() - 1) { // 현재 맨 마지막 원소에 위치. 맨 마지막 원소를 삭제하면 다음 원소의 위치가 반환되므로 오류가 난다.
			iter = dq.begin();
			dq.pop_back(); // 마지막 원소는 이렇게 제거
		}
		else {
			iter = dq.erase(iter); // erase의 리턴값을 받아줘야 한다. erase함수의 리턴값이 삭제 원소 다음에 있는 원소의 iterator이기 때문이다
		}
		if (dq.size() > 0) { // 강제 쉼표 삽입
			cout << ", ";
		}
	}
	cout << '>';
}