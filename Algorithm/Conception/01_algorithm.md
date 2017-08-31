# 01 Algorithm
## 1. 알고리즘과 입출력
### 1.1 알고리즘이란?
- In mathematics and computer science, an algorithm is a self-contained step-by-step set of operations to be performed.
- 어떠한 문제를 해결하기 위한 여러 동작들의 모임이다.

### 1.2 C++에서의 cin, cout의 속도 향상 방법
- `ios_base::sync_with_stdio(false);`를 앞에 추가해주자.

### 1.3 시간 복잡도 (Time Complexity)
- 시간 복잡도를 이용하면 작성한 코드가 시간이 얼마나 걸릴지 예상할 수 있다.
- 영어로 Big O Notation. 최악의 경우에 시간이 얼마나 걸릴지 나타내야 한다.
```c
  int sum = 0;
  for (int i=1; i<=N; i++) {
    sum += i;
  }
  // for문이 총 N번 수행되므로 O(N)
```
```c
  int sum = 0;
  sum = N*(N+1)/2;
  // 하나의 수식은 O(1)
```
```c
  int sum = 0;
  for (int i=1; i<=n; i++) {
    for (int j=1; j<=n; j++) {
      if (i == j) {
        sum += j;
      }
    }
  }
  // N * O(N) ==> O(N^2)          
```
- **대표적인 시간 복잡도**
  + O(1) : 단순 계산(a+b 같은, 배열 접근 연산)
  + O(lgN) : N개를 절반으로 계속해서 나눔
  + O(N) : 1중 for문
  + O(NlgN)
  + O(N^2) : 2중 for문
  + O(N^3) : 3중 for문
  + O(2^N) : 크기가 N인 집합의 부분 집합
  + O(N!) : 크기가 N인 순열
- **시간 복잡도 계산**
  + Big O Notaion에서 상수는 버린다.
    - O(3N^2) = O(N^2)
  + 두 가지 항이 있을 때, 변수가 같으면 큰 것만 빼고 다 버린다.
    - O(N^2 + NlgN) = O(N^2)
  + 두 가지 항이 있는데, 변수가 다르면 그대로 놔둔다.
    - O(N^2 + M) ==> N과 M의 값이 얼마인지 모르기 때문이다.

### 1.4 입출력
- 입력이 몇 개인지 주어지지 않은 경우 입력을 EOF까지 받으면 된다.
  + **C**: `while(scanf("%d %d", &a, &b) == 2)` ==> 성공적으로 입력받은 변수의 갯수
  + **C++**: `while(cin >> a >> b)`
  + **JAVA**: `while(sc.hasNextInt())`
- 한 줄 입력받기
  ```c
    scanf("%s", s);
    cin >> s;
  ```
  위의 두 방법으로는 한 줄을 입력받을 수 없다.
  ```c
    fgets(s, 100, stdin);
    scanf("%[^\n]\n", s); // 각 줄의 앞 뒤에 있는 공백은 입력받을 수 없다는 단점
    getline(cin, s);
  ```
  + 위의 세 방법은 모두 한 줄을 전체로 입력받을 수 있다.
  + %[]의 의미는 []안의 문자만 입력을 받겠다는 건데 ^마크가 있으므로 저 안의 문자만 빼고 입력받겠다는 의미
    - `scanf("%[^\n]", str);` ==> 이렇게 하면 줄 바꿈 제외한 문자열만 입력받을 수 있음
  + fgets 함수는 줄 바꿈까지 입력 받으므로 조심해야 한다.
  + getline 함수는 줄 바꿈을 입력 받지 않는다.
  + JAVA에서는 nextLine() 함수를 사용하면 한 줄을 입력받을 수 있다.
- `scanf("%1d", &x);` ==> %d 사이에 수를 넣으면 그 길이만큼만 입력받을 수 있다.
  + ex. 12345가 붙어있는 경우 한 자리씩 입력받고 싶을 때 유용!
