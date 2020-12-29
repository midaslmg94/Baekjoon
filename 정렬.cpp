#include <iostream>
#include <vector>
#include<algorithm>
#include<string>
#include<typeinfo>
using namespace std;
struct s {
	int num;
	int rank;
	int idx;
};
bool cmp_arr(int a, int b) {
	return a > b; // 내림차순 정렬 : 5 4 3 2 1
}

bool cmp_vector(int a, int b) {
	return a > b; // 내림차순 정렬
}

bool cmp_vector_struct(const s& a, const s& b) { // 매개변수는 항상 이렇게 const는 포인터
	// 여기서 어떤 구조체 변수를 기준으로 정렬할건지를 정함
	if (a.idx < b.idx) {
		return true;
	}
	else if (a.idx == b.idx) {
		if (a.num < b.num) {
			return true;
		}
	}
	return false;
}

int main() {
	/*배열 정렬
	int a[5] = { 5,2,1,4,3 };
	sort(a, a+5); // stl을 활용한 정렬(오름차순 정렬 : 1 2 3 4 5)
	//sort(a, a + 5, cmp_arr); // 사용자 정의 함수 사용
	for (const int n : a) {
		cout << n << ' ';
	}
	cout << endl;*/

	/*벡터 정렬
	vector<int>w;
	w.push_back(4); w.push_back(1);
	w.push_back(3); w.push_back(2); w.push_back(5);
	sort(w.begin(), w.end()); // 오름차순 정렬 : 1 2 3 4 5
	sort(w.begin(), w.end(),cmp_vector); // 내림차순 정렬 : 5 4 3 2 1
	for (auto n : w) {
		cout << n << ' ';
	}
	cout << endl;*/

	/*벡터 정렬(pair)
	vector<pair<int, int>>v;
	v.push_back({ 3, 4});
	v.push_back({ 1, 2 });
	v.push_back({ 5,1 });
	sort(v.begin(), v.end()); //first 기준으로 오름차순 정렬(기본값)
	sort(v.begin(), v.end(),greater<pair<int,int>>()); //first 기준으로 내림차순 정렬
	for (int i = 0; i < v.size(); i++) {
		cout << v[i].first << ' ' << v[i].second<<endl;
	}
	//sort(v.begin(), v.end(), cmp);
	for (auto n : v) {
		cout << n.first<<' '<<n.second<<endl;
	}*/

	/*벡터 정렬(구조체)*/
	vector<s>v;
	v.push_back({ 1,3,5 }); // num, rank, idx 순서
	v.push_back({ 3,1,7});
	v.push_back({ 2, 5,1 });
	//sort(v.begin(), v.end()); // 이렇게 하면 오류
	sort(v.begin(), v.end(), cmp_vector_struct);
	for (auto n : v) {
		cout << n.num << n.rank << n.idx << endl;
	}
	

}