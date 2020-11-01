#include <bits/stdc++.h>
using namespace std;

int main() {
  int cnt = 0, max = 0;
  string S;
  cin >> S;

  for(int i = 0; i < S.length(); i++) {
    if(S[i] == 'A' || S[i] == 'C' || S[i] == 'G' || S[i] == 'T') {
      cnt++;
      for(int j = i+1; j < S.length(); j++) {
        if(S[j] == 'A' || S[j] == 'C' || S[j] == 'G' || S[j] == 'T') {
          cnt++;
        } else break;
      }
    } else continue;
    if(cnt > max) max = cnt;
    cnt = 0;
  }
  cout << max << endl;
}