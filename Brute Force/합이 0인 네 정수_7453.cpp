#include <iostream>
#include <algorithm>
#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

int n, nn;
int a[4000], b[4000], c[4000], d[4000];
int ab[16000000], cd[16000000];

int main()
{
	scanf("%d", &n);
	nn = n * n;
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d %d", &a[i], &b[i], &c[i], &d[i]);
	}

	//�ִ� ����Ƚ�� = 2*4000^2
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			ab[i * n + j] = -(a[i] + b[j]);
			cd[i * n + j] = c[i] + d[j];
		}
	}
	sort(cd, cd + nn);

	long long ans = 0;

	//�ִ� ����Ƚ�� = 4000^2*log(4000^2)
	for (int i = 0; i < nn; i++)
	{
		int left = 0;
		int right = nn;
		int mid;
		while (left < right) {
			mid = (left + right) / 2;
			if (ab[i] > cd[mid])
				left = mid + 1;
			else
				right = mid;
		}
		int low = right;    //cd�� �ߺ��� ���� ���� �� ���� ���� �ε���
		left = 0, right = nn;

		while (left < right) {
			mid = (left + right) / 2;
			if (ab[i] >= cd[mid])
				left = mid + 1;
			else
				right = mid;
		}
		int high = right;    //cd�� �ߺ��� ���� ���� �� ���� ���� �ε���
		ans += (long long)(high - low);
	}
	printf("%lld", ans);
}