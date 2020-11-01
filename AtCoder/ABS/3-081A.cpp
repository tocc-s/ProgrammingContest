#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  int count = 0;

  cin >> s;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '1') {
      count++;
    }
  }
  cout << count << endl;
}