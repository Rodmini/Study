# 02 C++ STL
### 입출력
- `%i`: **형태에 따라 다르게 입력받는다.**
  ```c++
    int main(void) {
      int x,y;
      scanf("%d %i", &x, &y);   // 10은 10진수, 010은 8진수, 0x10은 16진수로 입력받게됨
      printf("%d %d\n", x, y);
      return 0;
    }
  ```
- **scanf의 리턴값은 성공적으로 입력받은 인자의 갯수이다.**
  + `while(scanf("%d %d", &x, &y) == 2)`
- **scanf는 줄바꿈과 공백은 무시한다.**
  + 줄바꿈은 `\n`: 10 / 공백은 ` `: 32
  ```c++
    while (n--) {
        char x, y, z;
        scanf(" %c %c %c",&x,&y,&z); // %c 앞에 공백을 넣어주면 공백이나 줄바꿈을 무시하고 필요값을 입력받게 된다.
        printf("%d %d %d\n",x,y,z);
    }
  ```
- `%[]`: 대괄호 안의 문자만 입력받겠다!!!! 대괄호 안의 문자가 아닌 값이 나올 때 까지 입력받음
  + `%[123]`: 123만 입력받겠다!
    - `scanf("%[123]", &a);` ==> **1231231** 9897998 입력 ===> 1231231이 입력됨
  + `%[^123]`: 123을 빼고 입력받겠다! 123이 아닌 값들이 나올 때 까지 입력받음
    - `scanf("%[^123]", &a);` ==> **987654** 323456778  ===> 987654만 입력됨
```c++
  while (scanf("%[^\n]\n",s)==1) {
    printf("%s\n",s);
  }
```
  + 이 방법은 줄바꿈을 안받아도 되지만 줄의 앞 뒤의 공백을 입력못받음.
```c++
  while ((c = getchar()) && c != EOF) {
      printf("%c",c);
  }
```
  + 이렇게 글자를 하나씩 입력받아서 출력해도 된다.
- fgets는 줄바꿈을 포함한다!!!! 그러므로 ...
  ```c++
    void ClearLineFromReadBuffer(void) {
      while(getchar() != '\n');
    }
  ```
  줄바꿈을 비워줄 수 있는 함수를 구현하면 된다.

- `*`을 붙이면 입력은 받되 변수에 저장하지는 않는다!!
  ```javascript
    int main() {
      int x,y;
      scanf("%d %*d %d",&x,&y); // 10 20 30입력할 경우 20은 버려짐
      printf("%d %d\n",x,y);
      return 0;
    }
  ```

- `getline(cin, s);` ===> 한 줄 다 입력받기

- **실수 출력 소수점 조절**
  ```c++
    #include <iomanip>      // 이 헤더를 선언해줘야 한다.
    #include <iostream>
    using namespace std;
    int main() {
      double f = 3.14159265358979;
      // 유효숫자 자릿수 조절. 반올림 한 값을 출력하게 된다.
      cout << setprecision(5) << f << '\n';     // 3.1416
      cout << setprecision(8) << f << '\n';     // 3.1315927
      cout << setprecision(10) << f << '\n';    // 3.141592654

      // 소수점 n번째 자리까지 출력할 때 사용. 반올림 한 값이 출력된다.
      cout << fixed << setprecision(5) << f << '\n';    // 3.14159
      cout << fixed << setprecision(8) << f << '\n';    // 3.14159265
      cout << fixed << setprecision(10) << f << '\n';    // 3.1415926536
      return 0;
    }
  ```
- `endl` vs `\n`
  + `endl`은 스트림을 flush시키는 기능도 있기 때문에 `\n`보다 느리다.
  ```c++
    cout << i << endl; // 4272MS   
    cout << i << '\n'; // 36MS
    printf("%d\n",i);  // 20MS
  ```
- `ios_base::sync_with_stdio(false);` ==> cin,cout의 속도를 높혀줄 수 있다.

### auto (c++11 부터...)
- auto는 컴파일러가 타입을 추론해서 타입을 결정한다.
  ```c++
    auto a = 0, b = 0;
    cin >> a >> b;
    cout << a + b << '\n';
  ```
  다른 언어와 달리 C언어에서는 a,b의 값을 추후에 다른 자료형으로 변경할 수 없다.
- auto는 iterator를 쓸 때 매우 편리하다.
  ```c++
    map<pair<int,int>,vector<pair<int,string>>> d;
    for (map<pair<int,int>,vector<pair<int,string>>>::iterator it = d.begin();
      it != d.end(); ++it) {

    }
    // auto를 통해 위의 코드를 아래 코드로 줄일 수 있다.
    map<pair<int,int>,vector<pair<int,string>>> d;
    for (auto it = d.begin(); it != d.end(); ++it) {

    }  
  ```

### Range-based for (다른 언어에서는 흔히 forEach로 불림)
```c++
  vector<int> a = {1, 2, 3, 4, 5};
  for (int i = 0; i < a.size(); i++) {
    cout << a[i] << ' ';
  }

  for (int x : a) {   // a에 있는 모든 값을 하나씩 받아오겠다!
    cout << x << ' ';
  }
  cout << '\n';
```
```c++
  vector<pair<int,int>> a = {{1, 2}, {3, 4}, {5, 6}};
  for (int i=0; i<a.size(); i++) {
    cout << a[i].first + a[i].second << ' ';
  }

  for (auto &p : a) {
    cout << p.first + p.second << ' ';
  }
```
  + **&연산자를 붙이게 되면 값 복사가 아닌 참조 복사가 되므로 조금 더 빠르게 프로그램을 수행 가능하다.**

### C언어에서의 문자열 vs C++에서의 문자열
```c++
  const char cstr[] = "string";
  sum = 0;
  for (auto x : cstr) {
    sum += 1;               // cstr의 NULL 문자가 포함되어 있어 7이 출력됨
  }

  string str = "string";
  sum = 0;
  for (auto x : str) {
    sum += 1;               // string의 길이 6이 출력됨
  }
```

### 초기화 리스트
- 벡터 선언
  ```c++
    vector<int> a;
    a.push_back(1);
    a.push_back(3);
    a.push_back(7);
    a.push_back(13);
    a.push_back(50);    // C++11 이전에는 이렇게 선언해야 했지만 ...

    vector<int> a = {1, 3, 7, 13, 50}; // 이렇게 배열처럼 선언하는 것도 가능하다.
  ```
- 기타 자료형 선언
  ```c++
    struct Person {
      string name;
      int age;
    };
    Person p = {"you", 20};

    map<int, string> m = { {20, "a"}, {10, "hi"} }; // 20은 key, a는 value
    map<int, vector<pair<int,int>>> m2 = {
      {10, {{1, 2}, {3, 4}}},
      {20, {{5, 6}, {7, 8}, {9, 10}}}
    };

    set <int> s = {1, 2, 3, 4, 5};
  ```

### 람다 함수 (C++11)
- 이름이 없는 함수, 익명 함수라고도 불림
- 람다함수는 `[캡쳐](함수 인자){함수 내용}`으로 구성된다.
  ```c++
    int sum (int x, int y) {
      return x + y;
    }
    cout << sum(1, 2) << '\n';

    cout << [](int x, int y) {
      return x + y;
    }(1, 2) << '\n';
  ```
- 람다함수도 auto와 같은 형태로 변수로 만들 수 있다.
  ```c++
    auto sum2 = [](int x, int y) {
      return x + y;
    };
    cout << sum2(1, 2) << '\n';
  ```
  ```c++
    #include <iostream>
    using namespace std;

    int main(void) {
      auto print = [] {
        cout << "10/14" << '\n';
      };
      print();
    }
  ```
  이런식으로 활용 가능
- 람다함수의 활용
  ```c++
    int n, x;
    cin >> n >> x;
    auto is_less = [&](int number) { // &를 사용하면 함수 외부의 모든 변수를 참조!
      return number < x;
    };
  ```
  + `&x`처럼 특정 값을 명시해줘도 된다. `&`는 참조, `=`는 값 복사
  ```c++
    auto f = [&x, y]() mutable {    // 여기서 mutable을 지정해주지 않으면 y때문에 컴파일에러 발생
        x += 10;  // x는 참조값이므로 10씩 증가된다.   
        y += 10;  // y는 값을 복사한 것이므로 함수 내부에서는 증가되더라도 함수 외부에서는 그대로 10 출력
    };
  ```
- **함수의 변수 타입**
  + 지금까지는 `auto`를 이용해서 함수를 변수 처럼 사용했는데, 함수의 실제 변수 타입은?
  + `#include <functional>`에 선언되어 있다.
  + `function<리턴타입(콤마로 구분한 인자의 타입들)>`
    ```c++
      function<void()> print = [] {
      };
      function<void(int)> print2 = [](int x) {
      };
      function<int(int, int)> sum = [](int x, int y) {
          return x+y;
      };
    ```
- **재귀호출을 사용할 때는 auto를 사용할 수 없다!**
  ```c++
    function<int(int)> f = [&](int num) {   // 함수 내부 기준으로는 f도 외부 변수이므로 & 써줘야함
        if (num <= 1) {
            return num;
        } else {
            return f(num-1) + f(num-2);
        }
    };
  ```
- 람다함수를 이용한 사칙연산
  ```c++
    vector<function<int(int, int)>> v;    // 사칙연산 람다함수들을 모아 놓을 v 벡터 선언
    v.push_back([](int n, int m) {
        return n + m;
    });
    v.push_back([](int n, int m) {
        return n - m;
    });
    v.push_back([](int n, int m) {
        return n * m;
    });
    v.push_back([](int n, int m) {
        return n / m;
    });
    v.push_back([](int n, int m) {
        return n % m;
    });

    for (auto &f : v) {             // 참조를 통한 접근이 수행시간 더 적게 걸림
        cout << f(a, b) << '\n';
    }
  ```

### STL (Standard Template Library)
- 알고리즘, 컨테이너, 함수, 이터레이터로 이루어짐
#### STL의 컨테이너 1. pair
- 별도의 구조체나 클래스 선언없이 두 자료형을 묶을 수 있다.
- 첫 번째는 first, 두번째는 second로 접근
- pair는 `#include <utility>`에 있지만 algorithm이나 vector에서 이미 포함하고 있어 따로 include 하지 않아도 된다.
```c++
  #include <iostream>
  using namespace std;

  int main() {
    pair<int, int> p1;              // pair 선언법 1 (기본 0으로 초기화 된다)
    cout << p1.first << ' ' << p1.second << '\n';

    p1 = make_pair(10, 20);         // pair 선언법 2
    cout << p1.first << ' ' << p1.second << '\n';

    p1 = pair<int, int>(30, 40);    // pair 선언법 3
    cout << p1.first << ' ' << p1.second << '\n';

    pair<int, int> p2(50, 60);      // pair 선언법 4
    cout << p2.first << ' ' << p2.second << '\n';


    pair<pair<int, int>, pair<int, int>> p3;    // pair는 무조건 둘씩 짝지으므로, 이렇게 4개를 묶을 수도 있다.
    p3 = make_pair(make_pair(10,20), make_pair(30,40));     // 하지만, 헷갈릴 수 있으므로 좋은 방법은 X

    cout << p3.first.first << ' ' << p3.first.second << '\n';
    cout << p3.second.first << ' ' << p3.second.second << '\n';

    return 0;
  }
```
### STL의 컨테이너 2. tuple (C++11)
- pair와 같지만 여러 개를 묶을 수 있다.
- get을 이용해 인덱스로 접근
- `#include <tuple>`에 정의되어 있다.
```c++
  tuple<int, int, int> t = make_tuple(1, 2, 3);
  cout << get<0>(t) << '\n';
  cout << get<1>(t) << '\n';
  cout << get<2>(t) << '\n';

  // cout << get<i>(t1) << '\n';
```
  + tuple을 사용할 때는 get함수 안에 변수를 넣을 수 없다.

### STL의 컨테이너 3. tie
- tie를 이용하면 swap을 한 줄로 간단하게 표현할 수 있다.
```c++
  auto t = make_tuple(10, 20, 30);

  int x = get<0>(t);
  int y = get<1>(t);
  int z = get<2>(t);      // get함수 인자로 변수 전달이 불가능하므로 일일이 해야 하는 불편함

  tie(x, y, z) = t;     // 이렇게 하면 편하게 한 줄에 쭈루룩 입력 가능
  tie(x, y, ignore) = t;    // 30은 무시하게 된다.

  tie(b, a) = make_pair(a, b);  // 이렇게 swap을 간단히 구현 가능
```

### STL의 컨테이너 4. vector
- 배열인데 길이를 편하게 조절 가능하다!
```c++
  #include <iostream>
  using namespace std;

  int main() {
    vector<int> v1;         // 길이가 0
    vector<int> v2(10);     // 길이가 10인 벡터 ==> int v2[10];
    vector<int> v3(15, 1);  // 1로 초기화한 길이가 15인 벡터
    vector<int> v4 = {1, 2, 3, 4, 5};   // 초기화 리스트를 이용

    vector<pair<int, int>> v5;
    vector<pair<int, int>> v6 = {{1, 2}, {3, 4}};
    vector<vector<int>> v7;

    int n = 10, m = 20;
    vector<vector<int>> v8(n, vector<int>(m));      // int v8[n][m];

    vector<int> a = {1, 2, 3, 4, 5};
    a.push_back(6); // [1,2,3,4,5,6]
    a.pop_back();   // [1,2,3,4,5]
    a.clear();      // []
    a.resize(5);    // [0,0,0,0,0]
    a.clear();

    a.push_back(1);
    a.push_back(2);   // [1,2]
    a.resize(5);      // [1,2,0,0,0]      // 0으로 추가 채워짐
    a.resize(3);      // [1,2,0]        // 뒷 부분 잘라버림
    a.size();         // 3
    a.empty();        // false ==> 3이 들어있으므로

    vector<int> b = {1, 2, 3};
    cout << b.front();    // 1
    cout << b[1];         // 2
    cout << b.back();     // 3

    vector<int> a = {1, 2, 3, 4, 5};
    for (int i=0; i<a.size(); i++) {
      cout << a[i] << ' ';
    }
    for (int &x : a) {
      cout << x << ' ';
    }

    return 0;
  }
```
#### vector의 iterator
- iterator는 포인터라고 생각하면 편하다. 벡터의 처음부터 끝까지 순회하면서 접근할 때 용이
```javascript
  vector<int> a = {1,2,3,4,5};
  for (vector<int>::iterator it = a.begin(); it != a.end(); ++it) { // end()는 마지막 값의 뒤를 나타냄!
      cout << *it << '\n';
  }
  for (auto it = a.begin(); it != a.end(); ++it) {
    cout << "a[" << (it - a.begin()) << "] = " << *it << '\n';
  }
}
```
- vector에 pair나 tuple이 들어있는 경우 `emplace_back` 사용 가능
```javascript
  vector<pair<int,int>> a;
  a.emplace_back(1,2);
  a.push_back(make_pair(3,4));
  a.push_back({5, 6});

  for (auto &x : a) {
    cout << x.first << ' ' << x.second << '\n';
  }

  for (auto it = a.begin(); it != a.end(); ++it) {
    cout << it->first << ' ' << it->second << '\n';   // (*it).first 와 동일
  }
```
```javascript
  void print(vector<int> &a) {
    for (int x: a) {
      cout << x << '\n';
    }
    cout << '\n';
  }

  int main() {
    vector<int> a = {1,2,3};
    print(a);

    auto it = a.begin();
    a.insert(it, 4);  // 맨 앞에 4를 삽입
    print(a);         // 4, 1, 2, 3

    it = a.begin() + 1;
    a.insert(it, 5, 0);     // 5개의 길이만큼 0의 값을 추가
    print(a);           // 4,0,0,0,0,0,1,2,3

    it = a.begin() + 2;
    vector<int> b = {10, 20, 30};
    a.insert(it, b.begin(), b.end());   // b의 처음부터 끝까지의 값들을 삽입
    print(a);       // 4,0,10,20,30,0,0,0,0,1,2,3

    return 0;
  }
```
- 벡터도 배열이므로 insert하게 되면 `O(N)`만큼의 시간 소요. 추가 위치 뒤의 값들을 밀어내므로
- 값을 지우는 `erase` 함수. insert와 마찬가지로 `O(N)`소요. 제거 후 뒤의 값들을 앞으로 당기므로
```javascript
  vector<int> a = {1,2,3,4,5};
  a.erase(a.begin() + 2);   // 3이 삭제됨  ==> 1,2,4,5

  a.erase(a.begin()+1, a.begin()+3); // 1번지 이상 부터 3번지 미만의 값들을 제거 ==> 1,5
```
### STL의 컨테이너 5. Deque
- queue가 양쪽으로 붙어있는 경우. 양쪽에서 모두 `push`, `pop`이 가능하다.
```c++
  deque<int> d;

  d.push_back(1);         // 1
  d.push_front(2);        // 2 1
  d.push_back(3);         // 2 1 3
  d.pop_back();           // 2 1
  d.pop_front();          // 1
```
