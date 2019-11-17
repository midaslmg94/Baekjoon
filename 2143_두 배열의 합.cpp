#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	long long T;
	cin >> T;
		
	int n, m;
	cin >> n;
	vector<long long>A(n);
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}

	cin >> m;
	vector<long long>B(m);
	for (int i = 0; i < m; i++) {
		cin >> B[i];
	}

	vector<long long>v1, v2;

	//��ó�� v1 : ���� A�� ���ҵ��� �������� ���� �� �ִ� ��� ����� �� 
	for (int i = 0; i < n; i++) {
		long long sum = A[i];
		v1.push_back(sum);
		for (int j = i + 1; j < n; j++) {
			sum += A[j];
			v1.push_back(sum);
		}
	}
	//v2 : ���� B�� ���ҵ��� �������� ���� �� �ִ� ��� ����� �� 
	for (int i = 0; i < m; i++) {
		long long sum = B[i];
		v2.push_back(B[i]);
		for (int j = i + 1; j < m; j++) {
			sum += B[j];
			v2.push_back(sum);
		}
	}
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());

	long long result = 0;

	for (int i = 0; i < v1.size(); i++) {
		int low = lower_bound(v2.begin(), v2.end(), T - v1[i]) - v2.begin(); //�̻� 
		int high = upper_bound(v2.begin(), v2.end(), T - v1[i]) - v2.begin(); //�ʰ�
		result += high - low;
	}
	cout << result << endl;

}