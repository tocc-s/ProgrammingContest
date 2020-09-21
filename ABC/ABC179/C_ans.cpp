#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int N; cin >> N;
  int cnt = 0;
  // A*B <= N-1
  // N-1の-1は、正の整数で1が含まれないため
  for(int A = 1; A <= N; ++A) cnt += (N-1) / A;

  cout << cnt << endl;
}