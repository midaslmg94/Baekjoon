## Python 자료형 별 메서드 시간복잡도 정리

[참고자료](https://www.ics.uci.edu/~pattis/ICS-33/lectures/complexitypython.txt)

<br>

### **list**

| Operation     | Example      | Class         | Notes
| --------------|--------------|---------------|-------------------------------
| Index         | l[i]         | O(1)	       | 인덱스로 값 찾기
| Store         | l[i] = 0     | O(1)	       | 인덱스로 데이터 저장
| Length        | len(l)       | O(1)	       | 리스트 길이 
| Append        | l.append(5)  | O(1)	       | 리스트의 맨 뒤에 데이터 저장
| Pop	        | l.pop()      | O(1)	       | 리스트의 맨 뒤의 데이터 pop
| Clear         | l.clear()    | O(1)	       | 리스트 초기화
| Slice         | l[a:b]       | O(b-a)	       | 슬라이싱 되는 길이에 비례
| Extend        | l.extend(...)| O(len(...))   | 확장되는 길이에 비례
| Construction  | list(...)    | O(len(...))   | 리스트 길이에 비례
| check ==, !=  | l1 == l2     | O(N)          | 전체 리스트가 동일한지 확인
| Insert        | l[a:b] = ... | O(N)	       | 데이터 삽입
| Delete        | del l[i]     | O(N)	       | 데이터 삭제
| Containment   | x in/not in l| O(N)	       | 포함 여부 확인
| Copy          | l.copy()     | O(N)	       | 복제
| Remove        | l.remove(...)| O(N)	       | 제거
| Pop	        | l.pop(i)     | O(N)	       | 원소 제거. 제거 된 후로 한칸씩 당겨줘야 함
| Extreme value | min(l)/max(l)| O(N)	       | 최대, 최소 원소 확인.
| Reverse	    | l.reverse()  | O(N)	       | 뒤집기
| Iteration     | for v in l:  | O(N)          | 전체 리스트 순회
| Sort          | l.sort()     | O(N Log N)    | 기본 정렬
| Multiply      | k*l          | O(k N)        | 곱해진 만큼 비례


<br>

### **set**


| Operation     | Example      | Class         | Notes
| --------------|--------------|---------------|-------------------------------
| Length        | len(s)       | O(1)	     | 
| Add           | s.add(5)     | O(1)	     | 원소 추가
| **Containment**   | **x in/not in s** | **O(1)**	     | **포함여부 확인**
| Remove        | s.remove(..) | O(1)	     | 원소 제거, 만약 원소가 없으면 *KeyError* 발생
| Discard       | s.discard(..)| O(1)	     | 특정 요소 제거, 만약 원소가 없으면 종료
| Pop           | s.pop()      | O(1)	     | 랜덤하게 pop
| Clear         | s.clear()    | O(1)	     | similar to s = set()
| Construction  | set(...)     | O(len(...))   | depends on length of ... iterable
| check ==, !=  | s != t       | O(len(s))     | same as len(t); False in O(1) if the lengths are different
| <=/<          | s <= t       | O(len(s))     | issubset
| >=/>          | s >= t       | O(len(t))     | issuperset s <= t == t >= s
| Union         | s `|` t        | O(len(s)+len(t)) | 합집합
| Intersection  | s & t        | O(len(s)+len(t)) | 교집합
| Difference    | s - t        | O(len(s)+len(t)) | 차집합
| Symmetric Diff| s ^ t        | O(len(s)+len(t)) | 여집합
| Iteration     | for v in s:  | O(N)          | Worst: no return/break in loop
| Copy          | s.copy()     | O(N)	     |


<br>


### **dictionary**


| Operation     | Example      | Class         | Notes
| --------------|--------------|---------------|-------------------------------
| Store         | d[k] = v     | O(1)	     | 원소 저장
| Length        | len(d)       | O(1)	     | 길이 반환
| Delete        | del d[k]     | O(1)	     | 원소 삭제
| get/setdefault| d.get(k)     | O(1)	     | key에 따른 value 확인
| Pop           | d.pop(k)     | O(1)	     | pop
| Pop item      | d.popitem()  | O(1)	     | 랜덤하게 pop 
| Clear         | d.clear()    | O(1)	     | similar to s = {} or = dict()
| View          | d.keys()     | O(1)	     | 키값 전체확인. same for d.values()(value값 전체확인)
| Construction  | dict(...)    | O(len(...))   | depends # (key,value) 2-tuples
| Iteration     | for k in d:  | O(N)          | 전체 딕셔너리 순회


