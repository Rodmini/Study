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

#### pow(2,K) 함수의 반환형은 long double이므로 정수형으로 표기할 경우
- `#include <iomanip>`
- `cout << fixed << setprecision(0) << pow(2,k) << '\n';` 꼭 해주어야 한다.

#### size()함수 쓸 때 조심!!!!!!!!
- 자료형이 unsigned 이므로 `for(int i = 0; i < a.size()-1; i++)` 이런 경우에는 이상한 값이 나올 수 있음!!!
- **최대한 size()를 조작하지 않는 쪽으로 코딩하는게 좋다**
- 아니면 `(int)a.size() - 1` 이런식으로 자료형 변환 해주면서 사용하기

#### 순열 => N!
- 순열은 입력의 수 N이 약 10이하 정도일 때 사용 가능. 그 이후로는 값이 너무 커짐
