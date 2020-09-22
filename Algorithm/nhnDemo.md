### 1.
```c++
  #include <iostream>
  #include <vector>
  #include <algorithm>
  #include <string>
  #include <stdio.h>
  using namespace std;

  int main() {

    int input;
    vector<string> v;
    string max = "", min = "";
    while (cin >> input) {
        v.push_back(to_string(input));
    }

    sort(v.begin(), v.end(), [](string a, string b) {
        if (a[0] == b[0]) { // 2 24 2
            if (a.size() > 1 && b.size() > 1) {
                return a[1] > b[1];
            } else if (a.size() == 1) {
                return a[0] > b[1];
            } else if (b.size() == 1) {
                return a[1] > b[0];
            } else {
                return a > b;
            }
        } else {
            return a[0] > b[0];
        }
    });

    for (int i = 0; i < v.size(); i++) {
        max += v[i];
    }

    for (int i = (int)v.size()-1; i >= 0; i--) {
        min += v[i];
    }

  //    cout << max << '\n';
  //    cout << min << '\n';

    cout << stoi(max) + stoi(min) << '\n';
    return 0;
  }
```

### 2.
```c++
  #include <iostream>
  #include <vector>
  using namespace std;

  int main() {

  	int n;
  	cin >> n;
  	vector<vector<int>> v(n, vector<int>(n));

  	for (int i = 0; i < n; i++) {
  		for (int j = 0; j < n; j++) {
  			cin >> v[i][j];
  		}
  	}

  	for (int i = 0; i < n; i++) {
  		for (int j = 0; j < n; j++) {
  			cout << v[j][i];
  			if (j != n-1) {
  				cout << ' ';
  			}
  		}
  		cout << '\n';
  	}

    return 0;
  }

```


### 1-1.
```c++
  #include <iostream>
  #include <string>
  #include <vector>
  #include <algorithm>
  using namespace std;

  int main() {
      vector<int> v;
      int num;
      while (cin >> num) {
          v.push_back(num);
          cout << v.back();
      }

      sort(v.begin(), v.end());

      long min = 99999999999;
      int index = 0;
      long sum = 99999999999;
      for (int i = 1; i < v.size(); i++) {
          int temp = v[i] - v[i-1];
          if (temp < min) {
              min = temp;
              sum = v[i] + v[i-1];
              index = i-1;
          } else if (temp == min) {
              int tsum = v[i] + v[i-1];
              if (tsum < sum) {
                  index = i-1;
              }
          }
      }

      cout << v[index] << ' ' << v[index+1] << '\n';
      return 0;
  }
```

### 2-1.
```c++
  #include <iostream>
  #include <string>
  #include <vector>
  using namespace std;

  int main() {
      string s;
      getline(cin, s);
      vector<string> str;

      string temp = "";
      int ja = 0;
      int mo = 0;
      int resultmo = 0;
      int resultja = 0;

      for (int i = 0; i < s.length(); i++) {
          if (s[i] == ' ') {
              mo = 0, ja = 0;
          } else {
              if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
                  if (ja >= 3) {
                      resultja++;
                  }
                  ja = 0;
                  mo++;
              } else {
                  if (mo >= 2) {
                      resultmo++;
                  }
                  mo = 0;
                  ja++;
              }
          }
      }

      cout << resultmo << '\n';
      cout << resultja << '\n';
      return 0;
  }
```

### 3-1.
```c++
  #include <iostream>
  #include <string>
  #include <algorithm>
  using namespace std;

  int check(string ss1, string ss2) {
      int num = stoi(ss1) + stoi(ss2);
      string str = to_string(num); // 7587
      int front = 0;
      int back = (int)str.length() - 1;
      while (front < back) {
          if (str[front] != str[back]) {
              return -1;
          } else {
              front++;
              back--;
          }
      }
      return num;
  }

  int main() {
      int input;
      cin >> input;
      string s2 = to_string(input);
      string s1 = s2;
      reverse(s2.begin(), s2.end());

      int result = -1;
      for (int i = 1; i <= 3; i++) {
          result = check(s1, s2);
          if (result != -1) {
              cout << result << '\n';
              break;
          } else {
              int num1 = stoi(s1);
              int num2 = stoi(s2);
              s2 = to_string(num1+num2);
              s1 = s2;
              reverse(s2.begin(), s2.end());
          }
      }

      if (result == -1) {
          cout << result << '\n';
      }
      return 0;
  }

```

### 4-1.
```c++
  #include <iostream>
  #include <string>
  #include <vector>
  #include <algorithm>
  using namespace std;

  int main() {
      string s;
      getline(cin, s);

      string temp = "";
      vector<string> v;
      for (int i = 0; i < s.length(); i++) {
          if (s[i] == ' ') {
              v.push_back(temp);
              temp = "";
          } else {
              temp += s[i];
          }
      }
      if (temp != "") {
          v.push_back(temp);
      }

      sort(v.begin(), v.end(), [](string &u, string &v) {
          if (u[0] != v[0]) {
              return u[0] > v[0];
          } else {
              if (u.size() == v.size()) {
                  if (u.size() > 1) {
                      return u[1] > v[1];
                  } else {// 둘이 숫자같음 한자리수
                      return u[0] > v[0];
                  }
              } else {
                  if (u.size() > 1) {
                      return u[1] > v[0];
                  } else if (v.size() > 1) {
                      return u[0] > v[1];
                  } else {
                      return u[0] > v[0];
                  }
              }
          }
      });
      long long sum = 0;
      string t = "";
      for (string a : v) {
          t += a;
      }
      sum += stoi(t);
      t = "";
      reverse(v.begin(), v.end());
      for (string a : v) {
          t += a;
      }
      sum += stoi(t);

      cout << sum << '\n';
      return 0;
  }

```


### +5
```c++
  #include <iostream>
  #include <queue>
  #include <vector>
  #include <algorithm>
  using namespace std;

  struct Person {
      string gender;
      int age;
      string etc;
  };

  int main() {
      vector<int> type;
      for (int i = 1; i <= 3; i++) {
          int num;
          cin >> num;
          type.push_back(num);
      }

      int ppNum;
      cin >> ppNum;   // 사람수
      vector<Person> p;

      for (int i = 0; i <= ppNum; i++) {
          string in;
          getline(cin , in);
          vector<string> v;
          string temp = "";
          for (int j = 0; j < in.length(); j++) {
              if (in[j] == ' ') {
                  v.push_back(temp);
                  temp = "";
              } else {
                  temp += in[j];
              }
          }
          if (temp != "") {
              v.push_back(temp);
              temp = "";
          }

          if (v.size() > 2) {
              p.push_back({v[0], stoi(v[1]), v[2]});
          } else if (v.size() > 0) {
  //            cout << v.size() << '\n';
              p.push_back({v[0], stoi(v[1]), ""});
          }
      }
  //    for (Person pw : p) {
  //        cout << "+" << '\n';
  //        cout << pw.gender << pw.age << pw.etc << '\n';
  //    }

      int prior = type[0];
      int prior2 = 0;
      if (prior == 1) {   // 성별순
          sort(p.begin(), p.end(), [&](Person &u , Person &v){
              if (u.gender == v.gender) {
                  prior2 = type[1];
                  if (prior2 == 2) {
                      if (u.age <= 7 && v.age <= 7) {
                          if (u.age == v.age) {
                              if (u.etc.size() == v.etc.size()) {
                                  return u.etc[0] > v.etc[0];
                              } else {
                                  return u.etc.size() > v.etc.size();
                              }
                          } else {
                              return u.age < v.age;
                          }
                      } else if (u.age <= 7){
                          return u.age < v.age;
                      } else if (v.age <= 7) {
                          return u.age > v.age;
                      } else {
                          if (u.age == v.age) {
                              if (u.etc.size() == v.etc.size()) {
                                  return u.etc[0] > v.etc[0];
                              } else {
                                  return u.etc.size() > v.etc.size();
                              }
                          } else {
                              return u.age > v.age;
                          }
                      }
                  } else if (prior2 == 3) {
                      if (u.etc == v.etc) {
                          if (u.age <= 7 && v.age <= 7) {
                              return u.age < v.age;
                          } else if (u.age <= 7){
                              return u.age < v.age;
                          } else if (v.age <= 7) {
                              return u.age > v.age;
                          } else {
                              return u.age > v.age;
                          }
                      } else {
                          if (u.etc.size() == v.etc.size()) {
                              return u.etc[0] > v.etc[0];
                          } else {
                              return u.etc.size() > v.etc.size();
                          }
                      }
                  }
              }
              return u.gender < v.gender;
          });
      } else if (prior == 2) {    // 나이순
          sort(p.begin(), p.end(), [&](Person &u , Person &v){
              if (u.age == v.age) {
                  prior2 = type[1];
                  if (prior2 == 1) {
                      if (u.gender == v.gender) {
                          if (u.etc.size() == v.etc.size()) {
                              return u.etc[0] > v.etc[0];
                          } else {
                              return u.etc.size() > v.etc.size();
                          }
                      } else {
                          return u.gender > v.gender;
                      }
                  } else if (prior2 == 3) {
                      if (u.etc == v.etc) {
                          return u.gender > v.gender;
                      } else {
                          if (u.etc.size() == v.etc.size()) {
                              return u.etc[0] > v.etc[0];
                          } else {
                              return u.etc.size() > v.etc.size();
                          }
                      }
                  }
              } else {
                  if (u.age <= 7 && v.age <= 7) {
                      return u.age < v.age;
                  } else if (u.age <= 7){
                      return u.age < v.age;
                  } else if (v.age <= 7) {
                      return u.age > v.age;
                  } else {
                      return u.age > v.age;
                  }
              }
              return u.age > v.age;
          });
      } else if (prior == 3) {    // 임산부
          sort(p.begin(), p.end(), [&](Person &u , Person &v){
              if (u.etc == v.etc) {
                  prior2 = type[1];
                  if (prior2 == 1) {
                      if (u.gender == v.gender) {
                          if (u.age <= 7 && v.age <= 7) {
                              return u.age < v.age;
                          } else if (u.age <= 7){
                              return u.age < v.age;
                          } else if (v.age <= 7) {
                              return u.age > v.age;
                          } else {
                              return u.age > v.age;
                          }
                      } else {
                          return u.gender > v.gender;
                      }
                  } else if (prior2 == 2) {
                      if (u.age == v.age) {
                          return u.gender > v.gender;
                      } else {
                          if (u.age <= 7 && v.age <= 7) {
                              return u.age < v.age;
                          } else if (u.age <= 7){
                              return u.age < v.age;
                          } else if (v.age <= 7) {
                              return u.age > v.age;
                          } else {
                              return u.age > v.age;
                          }
                      }
                  }
              }
              if (u.etc.size() == v.etc.size()) {
                  return u.etc[0] > v.etc[0];
              } else {
                  return u.etc.size() > v.etc.size();
              }
          });
      }

      for (Person pw : p) {
  //        cout << "+" << '\n';
          cout << pw.gender << ' ' << pw.age;
          if (pw.etc.length() > 0) {
              cout << ' ' << pw.etc;
          }
          cout << '\n';
      }


      return 0;
  }

  //2 1 3
  //5
  //M 17
  //F 60 P
  //F 30 PW
  //M 40 P
  //M 3

  //F60P
  //M40P
  //F30PW
  //M17
  //M3

  //1 2 3
  //2
  //M 3 PW
  //F 6


```
