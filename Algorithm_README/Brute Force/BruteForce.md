# 1. 문제

- [2143_두 배열의 합](https://www.acmicpc.net/problem/2143) 	

- [2231_분해합](https://www.acmicpc.net/problem/2231)

- [2309_일곱 난쟁이](https://www.acmicpc.net/problem/2309)

- [3085_사탕게임](https://www.acmicpc.net/problem/3085)

- [7453_합이 0인 네 정수](https://www.acmicpc.net/problem/7453)

- [1182_부분수열의 합](https://www.acmicpc.net/problem/1182)

  





## 부분수열

- 부분수열은 수열이 연속적이지 않아도 된다.
  - ex) 5 7 1 6 3 의 부분 수열은 {5, 1, 3}도 가능한 것이다.
- [1182_부분수열의 합](https://www.acmicpc.net/problem/1182) 문제를 보면 합이 S가 되는 부분수열의 개수를 물어보고 있다. N개의 원소가 있는 수열에서 1개~N개의 원소를 선택한 부분집합을 구하고 그 합이 S와 같으면 된다. 이는 n개 중에서 r개를 선택하는 `nCr` 과 같다. nCr의 구현은 `next_permutation()` 을 사용한다.
- 아래의 코드는 9개 중 7개를 뽑는 경우의 수를 모두 출력하는 코드이다.

```c++
int arr[9];
for(int i=0; i<9; i++){
    cin>>arr[i];
}
sort(arr, arr+9); // 정렬이 되어있어야 함
// 9개 중 7개 뽑기
int select[9] = {0,0,1,1,1,1,1,1}; // 이 부분이 중요. 0, 0 앞에 들어감
do{
    for(int i=0; i<9; i++){
        if(select[i]==1){
            cout<<arr[i];
        }
    }
    cout<<endl;    
}while(next_permutation(select, select+9));
```



```c++
	vector<int>v(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	int cnt = 0;
	vector<int>choice(N);
	for (int i = N-1; i >=0; i--) {
		choice[i] = 1; // N개 중 1개 뽑는 경우, 2개 뽑는 경우 ... N개 뽑는 경우의 순서
		do{
			int sum = 0;
			for (int j = 0; j < N; j++) {
				if (choice[j] == 1) { 
					sum += v[j];
				}
			}
			if (sum == S) {
				cnt++;
			}
		} while (next_permutation(choice.begin(), choice.end()));
	}
```

