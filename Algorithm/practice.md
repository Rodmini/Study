### 1.
```c++
  #include <stdio.h>
  #include <string.h>
  using namespace std;
  int solution(int n)
  {
      char str[11];
      int answer = 0;

      sprintf(str, "%d", n);
      int len = strlen(str);
      int i;
      for (i = 0; i < len; i++) {
          answer += (str[i] - '0');
      }

      return answer;
  }
```

### 2.
```c++
  #include<vector>
  #include<stdio.h>
  #include <iostream>
  using namespace std;

  bool solution(vector<int> arr)
  {
  	bool answer = true;
      int len = arr.size();
      bool check[100001] = {false, };
      int i;

      for (i = 0; i < len; i++) {
          if (arr[i] > len) return false;
          if (!check[arr[i]]) {
              check[arr[i]] = true;
          } else {
              return false;
          }     
      }

      for (i = 1; i <= len; i++) {
          if (!check[i]) return false;
      }

  	return answer;
  }
```

### 3.
```c++
  #include <iostream>
  #include <vector>
  using namespace std;

  vector<int> solution(vector<vector<int> > v) {
    //vector<vector<int> >의 값은 다음과 같이 읽어올 수 있습니다.
      // cout << v[0][0] << " ";
      int left[2] = {0, };
      int right[2] = {0, };
      int len = v.size();
      int i, j;
      int xp = 0, yp = 0;
      int findx = 0, findy = 0;

      for (i = 0; i < len; i++) {
              for (j = 0; j < 2; j++) {
                  if (left[j] == v[i][0]) {
                      findx = v[i][0];
                  } else if (left[j] == 0) {
                      left[xp++] = v[i][0];
                      break;
                  }
              }
              for (j = 0; j < 2; j++) {
                  if (right[j] == v[i][1]) {
                      findy = v[i][1];
                  } else if (right[j] == 0) {
                      right[yp++] = v[i][1];
                      break;
                  }
              }
      }
      int resultX = 0, resultY = 0;
      for (i = 0; i < len; i++) {
          if (v[i][0] != findx) {
              resultX = v[i][0];
          }
          if (v[i][1] != findy) {
              resultY = v[i][1];
          }
      }

      vector<int> ans;
      ans.push_back(resultX);
      ans.push_back(resultY);
      return ans;
  }
```
