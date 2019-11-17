#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
  
int main() {
	int arr[9];
	for (int i = 0; i < 9; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + 9);
	// æ∆»© ≥≠¿Ô¿Ã ¡ﬂ 7∏Ì ªÃ±‚
	int select[9] = { 0,0,1,1,1,1,1,1,1 };
	do {
		int sum = 0;
		for (int i = 0; i < 9; i++) {
			if (select[i] == 1) {
				//printf("%d ", arr[i]);
				sum += arr[i];
			}
		}
		if (sum == 100) {
			for (int i = 0; i < 9; i++) {
				if (select[i] == 1) {
					printf("%d\n", arr[i]);
				}
			}
			//printf(" sum = %d \n", sum);
			return 0;
		}
	} while (next_permutation(select, select + 9));

}