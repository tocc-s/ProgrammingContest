#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, s = 1000, ans = 0;
  cin >> N;
  if(N % s == 0) cout << N % s << '\n';
  else cout << abs((N % s) - s) << '\n';
 }