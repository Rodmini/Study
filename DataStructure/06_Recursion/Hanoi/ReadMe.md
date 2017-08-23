# 하노이의 탑 (Hanoi)
## 1. 개념 및 제약사항
![hanoi_1](/images/170718_hanoi_1.png)
- 한 막대에 쌓여있는 원판들을 다른 막대로 이동시켜야 한다.
- 제약사항
+ 한 번에 하나의 원판만 이동할 수 있다.
+ 맨 위에 있는 원판만 이동할 수 있다.
+ 크기가 작은 원판 위에 큰 원판이 있을 수 없다.
+ (크기가 큰 원판 위에만 작은 원판을 놓을 수 있다)
+ 중간 막대를 이용할 수 있으나 앞의 3가지 조건을 만족해야 한다.

<br><br>
![hanoi_2](/images/170718_hanoi_2.png)
- 원판이 3개인 하노이의 탑을 옮기는 과정

## 2. 원판의 갯수가 클 경우의 재귀적 접근 방법
![hanoi_3](/images/170718_hanoi_3.png)
![hanoi_4](/images/170718_hanoi_4.png)
![hanoi_5](/images/170718_hanoi_5.png)
![hanoi_6](/images/170718_hanoi_6.png)
```
void hanoi_tower(int n, char from, char to, char temp) {
  if (n == 1) {
    from에서 to로 원판을 옮긴다.
  } else {
    Step-1) from의 맨 밑 원판을 제외한 나머지 원판들을 temp로 옮긴다.
    Step-2) from에 있는 한 개의 원판을 to로 옮긴다.
    Step-3) temp의 원판들을 to로 옮긴다.
  }
}
```
- Step-1)과 Step-3)은 같은 원판 옮기기지만 문제의 범위가 n-1인데다, 호출 될 때마다 범위가 줄어들기 때문에 재귀적 호출로 변경할 수 있다.
- 단, from과 to의 대상이 변경된다는 점에 주의!
```
void hanoi_tower(int n, char from, char to, char temp) {
  if (n == 1) {
    from에서 to로 원판을 옮긴다.
  } else {
    hanoi_tower(n-1, from, to, temp);
    from에 있는 한 개의 원판을 to로 옮긴다.
    hanoi_tower(n-1, temp, from, to);
  }
}
```

## 3. 수행 결과
```
원판 1을 A에서 C로 옮겼습니다
원판 2를 A에서 B로 옮겼습니다
원판 1을 C에서 B로 옮겼습니다
원판 3를 A에서 C로 옮겼습니다
원판 1을 B에서 A로 옮겼습니다
원판 2를 B에서 C로 옮겼습니다
원판 1을 A에서 C로 옮겼습니다
Program ended with exit code: 0
```
