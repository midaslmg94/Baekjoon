## lower_bound와 upper_bound

> 항상 헷갈리는 lower_bound와 upper_bound를 정리해보자
>
> lower_bound(target) : target 값보다 같거나 큰 값 중 가장 앞에 있는 원소의 인덱스 반환
>
> upper_bound(target) : target 값보다 큰 값중 가장 앞에 있는 원소의 인덱스 반환
>
> 즉, **lower_bound**는 value를 포함한 **이상**인 값을, **upper_bound**는 value를 포함하지 않은 **초과**인 값을 찾아내준다.



- 반환형 : iterator

  - 인덱스를 반환하고 싶으면 int pos = lower_bound(v.begin(), v.end(), target)-v.begin(); 

    

- 시간복잡도 

  - O(log N)

그리고 그 중복된 수가 몇 개인지를 알아야 하는 경우라면? 아니면, 그 중복된 수 모두를 체크해야 하는 경우라면 어떻게 해야할까?

![img](https://k.kakaocdn.net/dn/YT5sb/btqBs1c2G0m/BOqdMK4MKxyjjTxWyImhV1/img.png)

위와 같이 중복이 있는 벡터라고 할 때, 모든 40을 다 찾아야 한다면 다음과 같이 lower bound와 upper bound를 이용하면 된다.

- `lower_bound(v.begin(), v.end(), 40)-v.begin()`을 수행하면 첫번째로 나타나는 40의 인덱스인 4를 리턴
- `upper_bound(v.begin(), v.end(), 40)-v.begin()`을 수행하면 마지막으로 나타나는 40의 인덱스 다음 값인 7을 리턴한다.
  - lower_bound부터 upper_bound까지 for-loop을 돌면 모든 40인 값들을 찾을 수 있다.

 

그렇다면 배열에 없는 값인 35를 찾아야 한다면?

- `lower_bound(v.begin(), v.end(), 35)-v.begin()`를 수행 : 35가 들어갈 수 있는 4라는 인덱스를 똑같이 리턴한다. 4번자리는 기존 40이 있던 자리이다. 그러면 4번 자리에 35를 넣고, 기존 값들인 40, 50 등 을 한 칸씩 뒤로 밀면 35가 들어가도 전체 배열은 그대로 정렬된 상태를 유지하게 된다.
- `upper_bound(v.begin(), v.end(), 40)-v.begin()`를 수행 : 35는 배열에 없는 값인데, lower_bound(35)를 한 값과 마찬가지로 4라는 인덱스를 리턴한다. 마찬가지로 4번 자리에 35를 넣을 수 있다는 뜻이다.

 

**배열에 없는 값에 대하여 lower_bound나 upper_bound 연산을 수행하면 같은 값이 나오게 된다.**

==> **즉, 배열 안에 있는 x값의 개수를 찾고 싶다면 upper_bound(x) - lower_bound(x) 연산으로 할 수 있다.**

 





마지막으로, 정리해보면 

### lower_bound

- x라는 값을 배열에 넣을 때, 정렬된 상태를 유지하면서 넣을 수 있는 위치 중 가장 **앞**

(이때 넣는다는 개념은 해당 자리에 x를 넣고, 기존 값들은 다 1칸씩 뒤로 민다고 가정함)

- x라는 값 보다 **같거나 큰 값** 중 가장 앞에 있는 원소 위치

 

### upper_bound

- x라는 값을 배열에 넣을 때, 정렬된 상태를 유지하면서 넣을 수 있는 위치 중 가장 **뒤**

- x라는 값보다 **큰 값** 중 가장 앞에 있는 원소 위치

