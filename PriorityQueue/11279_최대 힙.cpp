#include<iostream>
#include<queue>

using namespace std;
/*
	만약 x가 자연수라면 배열에 x라는 값을 넣는(추가하는) 연산이고,
	x가 0이라면 배열에서 가장 큰 값을 출력하고 그 값을 배열에서 제거하는 경우이다. 
	입력에서 0이 주어진 회수만큼 답을 출력한다. 
	만약 배열이 비어 있는 경우인데 가장 큰 값을 출력하라고 한 경우에는 0을 출력하면 된다.
*/

/**/
priority_queue<long long>q;
long long arr[100000];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	long long n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	long long x = 0;
	for (int i = 0; i < n; i++) {
		x = arr[i];
		if (x == 0) {
			if (q.empty()) { 
				cout <<0<<"\n";
			}else { //배열이 비어있는 경우
				cout <<q.top()<< "\n";
				q.pop();
			}
		}else {
			q.emplace(x);
		}
	}
}