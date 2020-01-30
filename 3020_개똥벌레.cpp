#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n, h;
vector <int> suck; //����
vector <int> jong;  //������
vector<int>result; // �ı��ϴ� ��ֹ��� ���� 
int cnt = 0;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);	cout.tie();
	freopen("input.txt", "r", stdin);
	cin >> n >> h;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		if (i % 2==0) {//����
			suck.push_back(tmp);
		}
		else {//������
			jong.push_back(tmp);
		}
	}
	sort(suck.begin(), suck.end());
	sort(jong.begin(), jong.end());
	int sector1; // ������ ����
	int cnt_suck=0; // �߸��� ������ ����
	int sector2; // �������� ����
	int cnt_jong = 0; //�߸��� �������� ����
	for (int i = 1; i <= h; i++) {
		sector1 = i; 
		sector2 = h - sector1+1; // ���⼭ �� ���� +1�� �����༭
		// �� ��ġ���� ���� �ִ� ����, ���������� �߸�
		int pos_suck = lower_bound(suck.begin(), suck.end(), sector1)-suck.begin();
		int pos_jong = lower_bound(jong.begin(), jong.end(), sector2)-jong.begin();

		cnt_suck = suck.size() - pos_suck;
		cnt_jong = jong.size() - pos_jong;
 		result.push_back(cnt_suck + cnt_jong);
	}
	// ���˹����� �ı��ؾ� �ϴ� ��ֹ��� �ּڰ��� �׷��� ������ ���� �������� �����Ͽ� ����Ѵ�.
	sort(result.begin(), result.end());

	int ans = result[0]; // ��ֹ��� �ּڰ�
	// ���� ���� �� ��� �ִ��� ã��
	cnt = upper_bound(result.begin(), result.end(), ans) - lower_bound(result.begin(), result.end(), ans);
	cout << ans << ' ' << cnt;
}