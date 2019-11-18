#include <iostream>
#include <vector>
using namespace std;
#define MAX 3
int main() {

	vector<int>v[MAX];
	v[0].push_back(1);
	v[0].push_back(2);
	v[1].push_back(3);
	v[2].push_back(4);

	for (int i = 0; i < MAX; i++) {
		printf("%d ", v[i]);
		cout << endl;
	}
	for (int i = 0; i < MAX; i++) {
		v[i].clear();
	}
	for (int i = 0; i < MAX; i++) {
		printf("%d ", v[i]);
	}
	return 0;
}