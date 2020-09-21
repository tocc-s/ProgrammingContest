#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  string S; cin >> S;
  int len = S.length();

  if(S[len-1] == 's') cout << S << "es" << endl;
  else cout << S << "s" << endl;
}