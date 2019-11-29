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
	return a > b; // �������� ���� : 5 4 3 2 1
}

bool cmp_vector(int a, int b) {
	return a > b; // �������� ����
}

bool cmp_vector_struct(const s& a, const s& b) { // �Ű������� �׻� �̷��� const�� ������
	// ���⼭ � ����ü ������ �������� �����Ұ����� ����
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
	/*�迭 ����
	int a[5] = { 5,2,1,4,3 };
	sort(a, a+5); // stl�� Ȱ���� ����(�������� ���� : 1 2 3 4 5)
	//sort(a, a + 5, cmp_arr); // ����� ���� �Լ� ���

	for (const int n : a) {
		cout << n << ' ';
	}
	cout << endl;*/

	/*���� ����
	vector<int>w;
	w.push_back(4); w.push_back(1);
	w.push_back(3); w.push_back(2); w.push_back(5);
	sort(w.begin(), w.end()); // �������� ���� : 1 2 3 4 5
	sort(w.begin(), w.end(),cmp_vector); // �������� ���� : 5 4 3 2 1
	for (auto n : w) {
		cout << n << ' ';
	}
	cout << endl;*/

	/*���� ����(pair)
	vector<pair<int, int>>v;
	v.push_back({ 3, 4});
	v.push_back({ 1, 2 });
	v.push_back({ 5,1 });

	sort(v.begin(), v.end()); //first �������� �������� ����(�⺻��)
	sort(v.begin(), v.end(),greater<pair<int,int>>()); //first �������� �������� ����
	for (int i = 0; i < v.size(); i++) {
		cout << v[i].first << ' ' << v[i].second<<endl;
	}
	//sort(v.begin(), v.end(), cmp);
	for (auto n : v) {
		cout << n.first<<' '<<n.second<<endl;
	}*/

	/*���� ����(����ü)*/
	vector<s>v;
	v.push_back({ 1,3,5 }); // num, rank, idx ����
	v.push_back({ 3,1,7});
	v.push_back({ 2, 5,1 });
	//sort(v.begin(), v.end()); // �̷��� �ϸ� ����
	sort(v.begin(), v.end(), cmp_vector_struct);
	for (auto n : v) {
		cout << n.num << n.rank << n.idx << endl;
	}
	

}