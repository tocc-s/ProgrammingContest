#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, max_n = 0, sum = 0;
  cin >> N;
  vector<int> vec(N);

  for (int i = 0; i < N; i++) {
    cin >> vec.at(i);
    max_n = max(max_n, vec.at(i));
  }
  // cout << "max:" << max_n << endl;

  for (int i = 0; i < N; i++) {
    if (max_n == vec[i]) continue;
    sum += vec[i];
  }
  // cout << "sum:" << sum << endl;

  if (sum > max_n) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}