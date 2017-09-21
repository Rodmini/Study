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
