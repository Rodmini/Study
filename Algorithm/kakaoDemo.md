## Kakao 모의테스트 문제
### 1. 자연수 N이 주어지면, N의 각 자릿수의 합을 구해서 return 하는 solution 함수
- ex. N = 123이면 1 + 2 + 3 = 6을 return
- **제한사항** N의 범위 : 100,000,000 이하의 자연수
```c++
  #include <string>
  #include <iostream>
  using namespace std;
  int solution(int n)
  {
      int answer = 0;
      string str = to_string(n);

      for (int i = 0; i < str.size(); i++) {
          answer += (str[i]-'0');
      }

      return answer;
  }
```

### 2. 길이가 n인 배열에 1부터 n까지 숫자가 중복 없이 한 번씩 들어 있는지를 확인
- 1부터 n까지 숫자가 중복 없이 한 번씩 들어 있는 경우 true를, 아닌 경우 false를 반환
- **제한사항** 배열의 길이는 10만 이하, 배열의 원소는 10만 이하의 자연수
```c++
  #include<vector>
  #include<iostream>
  #include<algorithm>
  using namespace std;

  bool solution(vector<int> arr)
  {
    bool answer = true;
    sort(arr.begin(), arr.end());

    for (int i = 0; i < arr.size(); i++) {
        if ((i+1)^arr[i]) {
            return false;
        }
    }
    return answer;
  }
```
- **(1부터 n까지 다 xor한 값) xor (arr의 모든 값을 xor한 값)의 결과가 0이면 모든 수가 같은 것이다.**

### 3. 직사각형을 만드는 데 필요한 4개의 점 중 3개의 좌표가 주어질 때, 나머지 한 점의 좌표를 구하기
- 점 3개의 좌표가 들어있는 배열 v가 매개변수로 주어질 때, 직사각형을 만드는 데 필요한 나머지 한 점의 좌표를 return
- 단, 직사각형의 각 변은 x축, y축에 평행하며, 반드시 직사각형을 만들 수 있는 경우만 입력으로 주어진다.
- **제한사항**
  + v는 세 점의 좌표가 들어있는 2차원 배열.
  + v의 각 원소는 점의 좌표를 나타내며, 좌표는 [x축 좌표, y축 좌표] 순으로 주어진다.
  + 좌표값은 1 이상 10억 이하의 자연수입니다.
  + 직사각형을 만드는 데 필요한 나머지 한 점의 좌표를 [x축 좌표, y축 좌표] 순으로 담아 return
```c++
  #include <iostream>
  #include <vector>
  using namespace std;

  vector<int> solution(vector<vector<int>> v) {
    // vector<vector<int> >의 값은 다음과 같이 읽어올 수 있습니다.
    vector<int> ans(2);

    for (int i = 0; i < 2; i++) {
        for (int j = i+1; j < 3; j++) {
            for (int k = 0; k < 2; k++) {
                if (v[i][k] == v[j][k]) {
                    ans[k] = v[3-i-j][k];   // 입력은 항상 세 개의 좌표를 받으므로!
                }
            }
        }
    }
    return ans;
  }
```

### 4. 표에서 1로 이루어진 가장 큰 정사각형을 찾아 넓이를 return (단, 정사각형이란 축에 평행한 정사각형)
- 1와 0로 채워진 표(board)가 있다. 표 1칸은 1 x 1 의 정사각형
```c++
  #include<vector>
  #include<algorithm>
  using namespace std;

  int solution(vector<vector<int>> board)
  {
    int answer = 0;
    int n = board.size();
    int m = board[0].size();

    vector<vector<int>> d(n+1, vector<int>(m+1));       // int d[n+1][m+1]과 동일
    for (int i = 1; i <= n; i++) {              
        for (int j = 1; j <= m; j++) {
            if (board[i-1][j-1] == 0)
                continue;
            d[i][j] = min({d[i-1][j], d[i][j-1], d[i-1][j-1]}) + 1;   // 왼쪽칸, 위칸, 대각선왼쪽위칸 체크
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (d[i][j] > answer)
                answer = d[i][j];           // 가장 큰 최대값 찾기
        }
    }
    return answer * answer;
  }
```
- d[i][j] = (i, j)를 오른쪽 아래로 하는 가장 큰 정사각형의 변의 길이
- DP 프로그래밍 할 때 배열의 크기를 0번지 부터 말고 해당 값 인덱스로 지정하는 것이 수월하다.

### 5. 땅따먹기 게임
- 땅따먹기 게임의 땅(land)은 총 N행 4열로 이루어져 있고, 모든 칸에는 점수가 쓰여 있다.
- 1행부터 땅을 밟으며 한 행씩 내려올 때, 각 행의 4칸 중 한 칸만 밟으면서 내려와야 한다.
- 단, 땅따먹기 게임에는 한 행씩 내려올 때, 같은 열을 연속해서 밟을 수 없다.
- 마지막 행까지 모두 내려왔을 때, 얻을 수 있는 점수의 최대값을 return
- **제한사항**
  + 행의 개수 N : 100,000 이하의 자연수
  + 열의 개수는 4개이고, 땅(land)은 2차원 배열
  + 점수 : 100 이하의 자연수
```c++
  #include<vector>
  #include<iostream>
  using namespace std;

  int solution(vector<vector<int> > land)
  {
  	int answer = 0;
      int n = land.size();
      int m = land[0].size();
      vector<vector<int>> d(n+1, vector<int>(m+1));
      int max = 0;
      for (int i = 1; i <= 4; i++) {
          d[1][i] = land[0][i-1];
      }

      for (int i = 2; i <= n; i++) {
          for (int j = 1; j <= m; j++) {
              for (int k = 1; k <= 4; k++) {
                  if (j != k) {
                      if (d[i-1][k] > max)
                          max = d[i-1][k];
                  }
              }
              d[i][j] = max + land[i-1][j-1];
              max = 0;
          }
      }

      for (int j = 1; j <= 4; j++) {
          if (d[n][j] > answer)
              answer = d[n][j];
      }
  	return answer;
  }
```
```c++
  #include<vector>
  #include<algorithm>
  using namespace std;

  int solution(vector<vector<int> > land)
  {
  	int n = land.size();
      vector<vector<int>> d(n, vector<int>(4));

      for (int i = 0; i < 4; i++) {
          d[0][i] = land[0][i];
      }

      for (int i = 1; i < n; i++) {
          d[i][0] = max({d[i-1][1],d[i-1][2],d[i-1][3]}) + land[i][0];
          d[i][1] = max({d[i-1][0],d[i-1][2],d[i-1][3]}) + land[i][1];
          d[i][2] = max({d[i-1][0],d[i-1][1],d[i-1][3]}) + land[i][2];
          d[i][3] = max({d[i-1][0],d[i-1][1],d[i-1][2]}) + land[i][3];
      }

      return max({d[n-1][0],d[n-1][1],d[n-1][2],d[n-1][3]});
  }
```
- d[i][j] = (i,j)에 도착했을 때 얻을 수 있는 최대 점수

### 6. N개의 스티커가 원형으로 연결되어 있다. 스티커에서 몇 장의 스티커를 뜯어내어 뜯어낸 스티커에 적힌 숫자의 합이 최대
- 단 스티커 한 장을 뜯어내면 양쪽으로 인접해있는 스티커는 찢어져서 사용할 수 없게 된다.
- 스티커에 적힌 숫자가 배열 형태로 주어질 때, 스티커를 뜯어내어 얻을 수 있는 숫자의 합의 최댓값을 return
- 원형의 스티커 모양을 위해 배열의 첫 번째 원소와 마지막 원소가 서로 연결되어 있다고 가정.
```c++
  #include <vector>
  using namespace std;

  int calc(vector<int> &arr) {
      int n = arr.size();
      vector<int> d(n);
      for (int i = 0; i < n; i++) {
          d[i] = (i-2 >= 0 ? d[i-2] : 0) + arr[i];
          d[i] = max(d[i], (i-1 >= 0 ? d[i-1] : 0));
      }
      return d[n-1];
  }

  int solution(vector<int> sticker)
  {
      if (sticker.size() == 1) {    // size가 1인 경우 그 값 자체가 정답이므로
          return sticker[0];
      }
      vector<int> a(sticker.begin(), sticker.end()-1);  // 스티커가 원형이므로 맨 뒤를 뺀 경우
      vector<int> b(sticker.begin()+1, sticker.end());  // 스티커가 원형이므로 맨 앞을 뺀 경우

      return max(calc(a), calc(b));
  }
```
- 스티커를 뜯었을 때 인접한 양쪽의 스티커를 사용할 수 없다 ==> 해당 값 왼쪽 스티커를 변경할 수 없다로 문제 축소
  + 이렇게 되면, 해당 값(i) 오른쪽 스티커(i+1)를 변경할 수 없는 문제에 대해서는 처리해 줄 필요가 없다.
  + 해당 값이 i+1이 되었을 때 처리해줄 것이므로 ...
- d[i] = i번 스티커까지 고려했을 때 얻을 수 있는 최대 점수
  + i번 스티커를 뜯는 경우 : d[i-2] + A[i]
  + i번 스티커를 뜯지 않는 경우 : d[i-1]
- 즉, d[i] = Max(d[i-2] + A[i] , d[i-1])

### 7. 단어 퍼즐은 주어진 단어 조각들을 이용해서 주어진 문장을 완성하는 퍼즐이다. 이때, 주어진 각 단어 조각들은 각각 무한개씩 있다고 가정
- ex. 주어진 단어 조각이 [“ba”, “na”, “n”, “a”]인 경우 "ba", "na", "n", "a" 단어 조각이 각각 무한개씩 있다.
- 만들어야 하는 문장이 “banana”라면 “ba”, “na”, “n”, “a”의 4개 또는 “ba”, “na”, “na”의 3개만을 사용해도 완성가능
- 사용 가능한 단어 조각들을 담고 있는 배열 strs와 완성해야 하는 문자열 t가 매개변수로 주어질 때,
- 주어진 문장을 완성하기 위해 사용해야 하는 단어조각 개수의 최솟값을 return, 불가능하면 -1을 return
- **제한사항**
  + strs는 사용 가능한 단어 조각들이 들어있는 배열로, 길이는 1 이상 100 이하
  + strs의 각 원소는 사용 가능한 단어조각들이 중복 없이 들어있다.
  + 사용 가능한 단어 조각들은 문자열 형태이며, 모든 단어 조각의 길이는 1 이상 5 이하
  + t는 완성해야 하는 문자열이며 길이는 1 이상 20,000 이하
  + 모든 문자열은 알파벳 소문자로만 이루어짐
```c++
  #include <string>
  #include <vector>
  using namespace std;

  int solution(vector<string> strs, string t)
  {
  	int n = t.length();
    t = " " + t;        // 1번지부터 접근하기 위해
    int m = strs.size();
    vector<int> d(n+1);

    for (int i = 1; i <= n; i++) {
        d[i] = -1;          // -1값으로 초기화
        for (int j = 0; j < m; j++) {
            int len = strs[j].size();
            if (i-len < 0) continue;      // 주어진 문자열 조각의 길이가 훨씬 클 때
            if (d[i-len] == -1) continue;   // 이전의 값에 일치한 조각이 없을 경우 (ex. ban검사시 b없이 an만 있는 경우)
            bool ok = true;
            for (int k = 0; k < len; k++) {
                if (strs[j][k] != t[i-len+1+k]) {   // t는 1번지부터 접근하도록 했으므로 k+1
                    ok = false;
                    break;
                }
            }
            if (ok == false) continue;      // 문자열 조각이 일치하지 않을 경우
            if (d[i] == -1 || d[i] > d[i-len] + 1) {  // 기존에 저장된 d[i]값보다 최소값이 발생할 경우 그 값으로 대체
                d[i] = d[i-len] + 1;
            }
        }
    }

  	return d[n];
  }
```
### T1.
```c++
  #include <iostream>
  #include <bitset>
  #include <vector>
  #include <string>
  using namespace std;

  vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    const int max = 65536;
    vector <bitset<max>> ans;
    vector <string> answer;
    for (int i = 0; i < n; i++) {
        ans.push_back(arr1[i] | arr2[i]);
    }

    for (int i = 0; i < n; i++) {
        string s = "";
        for (int j = n-1; j >= 0; j--) {
            if (ans[i][j] == 1) {
                s += "#";
            } else {
                s += " ";
            }
        }
        answer.push_back(s);
    }
    for (int i = 0; i < n; i++) {
        cout << answer[i] << '\n';
    }
    return answer;
  }
```

### T2.
```javascript
  #include <string>
  #include <vector>
  using namespace std;

  int solution(string s) {
    int answer = 0;
    vector<int> temp;
    int index = 0;

    for (int i = 0; i < s.length(); i++) {
        if(s[i] >= '0' && s[i] <= '9') {
            if (s[i] == '0' && s[i-1] == '1') {
                temp[index] *= 10;
            } else {
                temp.push_back(s[i]-'0');
                index = (int)temp.size() - 1;   // 0 1 2
            }
        } else if (s[i] == 'S') {
            continue;
        } else if (s[i] == 'D') {
            temp[index] *= temp[index];
        } else if (s[i] == 'T') {
            temp[index] = temp[index] * temp[index] * temp[index];
        } else if (s[i] == '#') {
            temp[index] = -(temp[index]);
        } else if (s[i] == '*') {
            if (index == 0) {
                temp[index] *= 2;
            } else {
                temp[index] *= 2;
                temp[index-1] *= 2;
            }
        }
    }
    for (int x : temp) {
        answer += x;
    }

    return answer;
  }
```

### T3.
```c++
  #include <vector>
  #include <string>
  #include <algorithm>
  #include <string.h>
  using namespace std;

  int solution(int size, vector<string> input) {
    int answer = 0;
    vector<string> v;
    vector<string> c(size);
    vector<int> lru(size, 0);

    for (string from : input) {
        string str = "";
        for (int i = 0; i < from.length(); i++) {
            from[i] = toupper(from[i]);
            str += from[i];
        }
        v.push_back(str);
    }

    if (size == 0) {
        answer = (int)v.size() * 5;
    } else {
        int index = 0;
        int add = 1;
        for (string s : v) {
            auto it = find(c.begin(), c.end(), s);
            if (it != c.end()) {
                answer++;
                lru[it-c.begin()] = add++;
                add++;
            } else {
                if (index == size) {
                    int min = add + 10;
                    int min_index = 0;
                    for (int i = 0; i < size; i++) {
                        if (min >= lru[i]) {
                            min = lru[i];
                            min_index = i;
                        }
                    }
                    swap(c[min_index], s);
                    lru[min_index] = add++;
                } else {
                    c[index] = s;
                    lru[index] = add++;
                    index++;
                }
                answer += 5;
            }
        }
    }
    return answer;
  }
```

### T4.
```c++
  #include <iostream>
  #include <vector>
  #include <string>
  using namespace std;

  string changeForm(pair<int,int> p) {
      cout << "changeFo : " << p.first << ' ' << p.second << '\n';
      int h = p.first;
      int m = p.second;
      string s = "";
      if (h < 10 && h > 0) {
          s += '0';
          s += to_string(h);
      } else if (h == 0) {
          s += "00";
      } else {
          s += to_string(h);
      }
      s += ":";

      if (m < 10 && m > 0) {
          s += '0';
          s += to_string(m);
      } else if (m == 0) {
          s += "00";
      } else {
          s += to_string(m);
      }
      cout << "changeFo1 : " << s << '\n';
      return s;
  }

  int main() {
      int n = 10;  // 셔틀운행 횟수
      int t = 60;  // 셔틀운행 간격
      int m = 45;  // 한 셔틀 최대 크루수
      vector<string> timetable = {"23:59","23:59","23:59","23:59","23:59","23:59","23:59","23:59","23:59","23:59","23:59","23:59","23:59","23:59","23:59","23:59"};

      vector<pair<int,int>> bus;
      vector<int> people;
      vector<pair<int,int>> timet;

      string answer = "";

      for (string s : timetable) {
          string sh, sm;
          bool pos = true;
          for (int i = 0; i < s.length(); i++) {
              if (s[i] >= '0' && s[i] <= '9') {
                  if (pos) {
                      sh += s[i];
                  } else {
                      sm += s[i];
                  }
              } else if (s[i] == ':') {
                  pos = false;
              }
          }
          timet.push_back(make_pair(stoi(sh), stoi(sm)));

      }

      sort(timet.begin(), timet.end());

      for (auto &p : timet) {
          cout << p.first << ' '<<  p.second << '\n';
      }

      // 버스 도착시간 구현
      int startH = 9, startM = 0;
      for (int i = 1; i <= n; i++) {
          bus.push_back(make_pair(startH, startM));
          startM += t;
          if (startM >= 60) {
              startH++;
              startM = 0;
          }
      }
      people.resize(bus.size());

      if (timet.size() < m) {
          answer = changeForm(bus.back());
      } else {

          for (auto &p : timet) {
              for (int k = 0; k < bus.size(); k++) {
                  if (k != bus.size()) {
                      if (p.first < bus[k].first) {
                          if (people[k] >= m) {
                              continue;   // 정원초과
                          } else {
                              people[k]++;
                              break;
                          }
                      } else if (p.first == bus[k].first) {
                          if (p.second <= bus[k].second) {
                              if (people[k] >= m) {
                                  continue;
                              } else {
                                  people[k]++;
                                  break;
                              }
                          } else {
                              continue;
                          }
                      } else {
                          continue;
                      }
                  } else {
                      // 버스에 못탐
                      cout << "버스에 못탐" << '\n';
                  }
              }


          }

          cout << "헤헷"<<'\n';
          for (auto i : bus) {
              cout << i.first << ' ' << i.second << '\n';
          }
          for (auto d : people) {
              cout << d << ' ';
          }
          cout << 'f' << '\n';
          cout << people.back() << '\n';
          string person;
          if (people.back() == m) {
              cout << timet.back().first << ' '<< timet.back().second << '-';
              int tempH = timet.back().first, tempM = timet.back().second;
              if (timet.back().second == 0) {
                  tempM = 59;
                  tempH--;
              } else {
                  tempM--;
              }

              person = changeForm({tempH, tempM});
              cout << person << '\n';
          } else {
              person = changeForm(bus.back());
              cout << "\n그냥 : " << person << '\n';
          }
          answer = person;

      }

      cout << "answer: " << answer << '\n';

  }
```
