#include<iostream>
#include<algorithm>
/*
	���Ҹ� ������ �������鼭 ��� �� ū���� ã������
	���� ���鼭 ������ ���� ��� �� ũ���������� ã��..
*/
using namespace std;
int ret_MAX[3];
int ret_MIN[3];
int main() {
	int N, a, b, c, x, y, z;  //abc = max, xyz = min
	cin >> N;
	cin >> ret_MAX[0] >> ret_MAX[1] >> ret_MAX[2];
	ret_MIN[0] = ret_MAX[0];
	ret_MIN[1] = ret_MAX[1];
	ret_MIN[2] = ret_MAX[2];
	for (int i = 1; i < N; i++) {
		cin >> a >> b >> c;
		x = a; y = b; z = c;
		a += max(ret_MAX[0], ret_MAX[1]);
		b += max(max(ret_MAX[0], ret_MAX[1]), ret_MAX[2]);
		c += max(ret_MAX[1], ret_MAX[2]);
		ret_MAX[0] = a;
		ret_MAX[1] = b;
		ret_MAX[2] = c;


		x += min(ret_MIN[0], ret_MIN[1]);
		y += min(min(ret_MIN[0], ret_MIN[1]), ret_MIN[2]);
		z += min(ret_MIN[1], ret_MIN[2]);
		ret_MIN[0] = x;
		ret_MIN[1] = y;
		ret_MIN[2] = z;
	}
	cout << max(ret_MAX[0], max(ret_MAX[1], ret_MAX[2])) << " " << min(ret_MIN[0], min(ret_MIN[1], ret_MIN[2])) << endl;

	return 0;
}