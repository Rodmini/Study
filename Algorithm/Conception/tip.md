## 알고리즘 문제풀이 할 때 유용한 코드 모음
#### 입력 갯수에 제한이 없을 때
```c
  while(scanf("%d %d", &a, &b) == 2)
```
#### 그대로 출력하기 문제(공백 등 포함)
```c
  char c;
  while((c = getchar()) && c != EOF) {
    printf("%c", c);
  }
```
