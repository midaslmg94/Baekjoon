#include<iostream>
using namespace std;
/* 
	분할 정복
	정수론 
	(A*B)%C= ((A%C)*(B%C))%C
*/

long a, b, c;
long long sol(int n) {
	if (n == 0) { // base case
		return 1; 
	}
	long long tmp = sol(n / 2);
	long long result = (tmp * tmp) % c;
	if (n % 2 == 1) {
		return (result * a) % c;
	}
	return result;
}
int main() {
	cin >> a >> b >> c;
	cout << sol(b);
}