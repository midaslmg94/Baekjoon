#include<iostream>
#include<list>
#include<deque>
using namespace std;

list<int>li;
list<int>li_sort;
deque<int>dq;
deque<int>dq_sort;
bool finish() {
	for (int i = 0; i < li.size(); i++) {
		if (dq[i] != dq_sort[i]) {
			return false;
		}
	}
	return true;
}

int main() {
	int n;
	cin >> n;
	int cnt = 0;

	/* 앞에서 부터 채워 나갈것임 
		1. 
	*/


	while (!finish) {

	}

	li = {6,7,1,3,4,5,2};
	li_sort = { 1,2,3,4,5,6,7 };
	
	dq = { 6,7,1,3,4,5,2 };
	dq_sort = { 1,2,3,4,5,6,7 };

}