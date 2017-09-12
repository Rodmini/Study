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

#### string을 표준 입출력처럼 사용
```c++
  #include <sstream>

  string s;
  string line;
  while (cin >> line) {
      s += line;
  }

  istringstream sin(s);

  string number;
  int sum = 0;

  while (getline(sin, number, ',')) {
      sum += stoi(number);
  }
```

#### memset은 0,-1로 초기화 할 때만 정상동작함. 다른 값에 대해서도 안정하게 초기화하려면 fill쓰기!
