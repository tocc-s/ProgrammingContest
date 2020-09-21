#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int N;
  set<int> d;
  cin >> N;

  rep(i, N) {
    int num = 0;
    cin >> num;
    d.insert(num);
  }
  cout << d.size() << endl;
}