#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  const ll lim = 1e18;
  int N;
  cin >> N;
  vector<ll> A(N);
  ll mul = 1;
  bool flag = false;
  for (int i = 0; i < N; i++) {
    cin >> A[i];
    if (A[i] == 0) {
      cout << 0 << endl;
      return 0;
    }
  }
  for (int i = 0; i < N; i++) {
    if (A[i] > lim / mul) flag = true;
    else mul *= A[i];
  }
  if (flag) mul = -1;

  cout << mul << endl;
}