**### 파이썬 문법 정리**

> 자료형
- 소수를 정의하려 float 같은 걸 안쓰고 10.1 처럼 그냥 바로 소수를 쓰면 된다.
- 지수표기 방식은 실수형으로 처리한다. ex) INF = 1e9로 하면 소수가 된다.
- 실수는 정확한 값을 처리하지 못하므로 round()를 사용해서 반올림 하여 처리한다.

> 수의 자료형 연산
- 나누기를 하면 실수형으로 반환. 몫을 구하려면 `//` 를 사용한다.
- 거듭제곱 연산도 가능하다. `**`
  - print(2**3) -> `8`


> 리스트 자료형

- C++의  vector과 유사. 
- 대괄호를 사용. 
- 비어있는 리스트는 `list()` 또는 `[ ]`
- 리스트에는 일반적으로 같은 자료형이 들어가는게 정석이지만, 다른 자료형이 들어가는 것도 가능하다. 
- 인덱스 접근 가능
    - 음의 정수로 인덱스 접근하면 맨 뒤에서부터 접근
    - 단, 맨 뒤의 원소의 인덱스는 `-1`
- 인덱스 슬라이싱
    - 대괄호 안에 콜론(:)을 넣어서 시작인덱스와 끝 인덱스를 설정
    - 끝 인덱스는 실제 인덱스보다 1 크게 설정. 
        - ex) 두번째 원소부터 네번째 원소까지 가져오려면 `result = a[1:4]`
- 리스트 컴프리헨션
	- a = [for I in range(20) if I %2==1]  -> 홀수만 있는 리스트가 생성된다.
	- 2차원 리스트를 사용할 때 효율적이다
		- N x M의 2차원 리스트 초기화 
			- `array = [[0] * m for _ in range(n)]`
			- `_` 의 경우는 해당 변수가 별 의미가 없을 때 쓰는 것. 

- 리스트 관련 메서드
	- append( ) : 리스트의 맨 뒤에 원소 1개 삽입. O(1)
	- sort( ) : 오름차순 정렬. O(nlogn)
		- a.sort( ) : a 자체를 정렬한다.
		- `res = sorted(a)` : a를 정렬한 것을 res에 넣고, a는 정렬되지 않는다. 
	- reverse( ) : 원소를 뒤집는다. O(N)
	- insert(삽입 위치, 삽입 값) : 특정한 인덱스 위치에 값을 삽입. O(N)
	- count( ) : 리스트에서 특정한 값을 가지는 데이터의 개수를 반환. O(N)
	- remove( ) : 특정한 값을 갖는 원소를 하나만 제거. 여러개의 경우 맨 앞 원소 제거. O(N)
		- 특정한 값을 모두 제거하기 
			- a = [1,2,3,4,4,5,5], remove_item =[2,4] 
			- res = [I for I in a if I not in remove_item]
			

> 문자열 자료형
- `+` 로 문자열 연결 가능
- 리스트와 마찬가지로 인덱싱과 슬라이싱 가능

> 튜플 자료형

- 한번 선언된 값을 변경할 수 없음
- 소괄호를 사용한다.


> 사전 자료형
- key와 value를 쌍으로 데이터를 갖음(해시 테이블 형태)
- 값의 검색이 O(1)
- data = dict( )로 선언 가능
	- key만 뽑아서 리스트로 활용 가능 `list(a.keys())`
	- value만 뽑아서 리스트로 활용 가능 `list(a.values())`
	

> 집합 자료형
- 중복을 허용하지 않는다.
- 순서가 없다.
	- 인덱싱 불가
- `set()` 함수 사용
- C++의 `map`과 유사함. 시간복잡도 : O(1)
- data = {1,2,3,3}  처럼 `{ }` 으로 정의한다.
- 값이 있는지 없는지만 확인할 때 유용함
	- print(1 in data) -> true 출력
- 합집합, 교집합, 차집합
	- 합집합 : a | b
	- 교집합 : a & b
	- 차집합 : a - b

- 여러개의 데이터 추가 : update



> 기본 입출력
- 데이터의 개수 입력 : n = int(input())
	- 값을 초기화 할 때 map함수 사용된다
- `split()` : 각 데이터를 공백을 기준으로 구분하여 입력받음
	- 1 2 3 4 5 입력이 들어오면 [‘1’, ‘2’, ‘3’, ‘4’, ‘5’] 이렇게 저장된다. 
	- a, b, c, d, e = map(int, input().split())
		- 각 a, b, c, d, e 변수에 int 값 1개씩 담긴다.
	- data = list(map(int, input().split()))
		- 입력이 data에 리스트 형태로 담긴다.

- 2차원 배열로 입력이 들어오는 경우
```python
3 
4
0 0 0 0
0 0 0 0
0 0 0 0
0 0 0 0

n = int(input())
m = int(input())
arr = []
for i in range(n):
	arr.append(list(map(int, input().split()))
```

- 입력받아야 할 것이 한 줄에 여러 개라면 `input()`보다 `readline()`함수를 이용하는 것이 훨씬 더 빠르다.
```python
from sys import stdin
n = sys.stdin.readline().split()
```

- readline() 함수 뒤에 split() 함수를 연이어서 호출하면 아예 이렇게 list로 받는 것이 가능하다. 게다가 문자열이 아니라 아예 int로 바꿔서까지 저장할 수 있다.
```python
from sys import stdin
li = list(map(int, stdin.readline().split()))
```

- print를 할 때는 같은 자료형으로 출력을 해야한다.
	- print(“정답은” + str(5))

- 파일입출력
	- sys.stdin 을 아래와 같이 정의해주면 된다. 
	```python
	import sys, copy
	sys.stdin = open("input.txt", "r")
	arr = map(int, sys.stdin.readline().split())
	Map = list(list(map(int, sys.stdin.readline().split())) for _ in range(n))
	```


> 비교 연산자
- 기존에 `&&` `||` 로 썼던 것을 그냥 and, or로 쓴다. 또한, `if 0<=a<=10:` 이것도 가능하다.

> 글로벌 변수
- 전역 변수에 사용 된 값을 가지고 오려면 `global` 키워드를 사용한다.
- 만약 리스트가 전역에 사용되었다면 그냥 써도 된다.
```python
a = 10 
def func():
	global a
  a += 1

func()
print(a)
```

> 여러 개의 반환값을 갖는 함수 
```python
def func(a, b):
	return a+b, a-b, a*b, a/b

plus, minu, mult, div = func(5,2)

```
	- 함수에서 리턴하는 순서대로 각각의 변수에 담긴다.

> 표준 라이브러리
- itertools : 반복되는 형태의 데이터를 처리하는 기능을 제공
	- 순열, 조합 라이브러리 제공
- heapq : 힙 기능을 제공
	- 우선순위 큐
- bisect : 이진 탐색을 제공
- collections : 덱(duque), 카운터(Counter)등의 자료구조를 포함 

> 자주 사용되는 내장함수
- result = eval


> 순열과 조합
```python
ffrom itertools import permutations, combinations
data = ['A','B','C']
result = list(permutations(data,2)) # 3개 중 2개 뽑는 순열
print(result)

data = ['A', 'B', 'C']
result = list(combinations(data,2)) # 3개 중 2개 뽑는 조합
print(result)

# [('A', 'B'), ('A', 'C'), ('B', 'A'), ('B', 'C'), ('C', 'A'), ('C', 'B')] 
# [('A', 'B'), ('A', 'C'), ('B', 'C')]

```


> 중복순열과 중복조합
```python
from itertools import product
data = ['A', 'B', 'C']
result = list(product(data, repeat=2)) # 중복순열
print(result)
# [('A', 'A'), ('A', 'B'), ('A', 'C'), ('B', 'A'), ('B', 'B'), ('B', 'C'), ('C', 'A'), ('C', 'B'), ('C', 'C')]

from itertools import combinations_with_replacement
data = ['A', 'B', 'C']
result = list(combinations_with_replacement(data, 2)) # 중복조합 3개 중 2개 뽑는 조합
print(result)
# [('A', 'A'), ('A', 'B'), ('A', 'C'), ('B', 'B'), ('B', 'C'), ('C', 'C')]

```