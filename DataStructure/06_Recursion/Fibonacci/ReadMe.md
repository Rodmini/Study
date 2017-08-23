# 피보나치 수열 (Fibonacci)
## 1. 풀이
- fib(n)
  + 0   if n=0
  + 1   if n=1
  + fib(n-1) + fib(n-2)   if n>=2

## 2. 재귀 호출을 이용한 구현
![book](/images/recursion_fibonacci_1.png)
- 피보나치 수열을 재귀 호출로 구현할 경우 성능면에서 매우 비효율적
- 같은 숫자에 대한 피보나치 수열 계산을 중복하여 호출하기 때문이다.
- ex) fib(6)의 값을 계산하기 위해 fib(4)가 두 번 호출, fib(3)은 세 번 호출되므로...
- 시간복잡도가 O(n^2) 이므로 n의 값이 커질수록 매우매우 비효율적

## 3. 반복 호출을 이용한 구현
```
int i = 0, temp = 0, current = 1, last = 0;

for(i = 2; i <= n; i++) {
  temp = current;
  current += last;
  last = temp;
}
```
- 반복 호출을 이용하면 시간복잡도가 O(n)
- 재귀 호출에 비해 수행시간이 매우 짧다는 장점!
- 그러나, 한 눈에 흐름을 파악할 수 없다는 단점!
