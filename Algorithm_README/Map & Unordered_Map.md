## Map & Unordered_Map



> Map과 Unordered_map을 비교해보자



- 관련 문제

  - [백준 10816번 숫자 카드2](https://www.acmicpc.net/problem/10816)

    

- 헤더파일, 선언

  - map

    ```c++
    #include <unordered_map>
    unordered_map<int, int> um;
    ```

  - unordered_map

    ```c++
    #include <map>
    map<int, int> m;
    ```

    

- 방식

  - map : 레드블랙트리

  - unordered_map : 해시


  

- 시간복잡도

  - map : O(log n)
  - unordered_map : O(1)



- 장단점
  - map : 알아서 정렬되어서 들어감. 안정적임. 하지만 상대적으로 느림
  - unordered_map : 탐색이 빠름. 하지만 입력에 문자가 들어가면 충돌이 일어날 수 있음. 내부에서 정렬이 안된다. 불안정함
- 

