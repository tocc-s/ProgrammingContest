#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  string N;
  int keta = 0, sum = 0;
  cin >> N;
  keta = N.size();

  rep(i, keta) {
    sum += N[i] - '0';
  }
  if(sum % 9 == 0) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}