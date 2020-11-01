#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int N, sum_a = 0, sum_b = 0, cnt = 0;
  cin >> N;
  priority_queue<int> a;
  rep(i, N) {
    int num = 0;
    cin >> num;
    a.push(num);
  }

  while (!a.empty()) {
    if (cnt % 2 == 0) sum_a += a.top();
    else sum_b += a.top();
    a.pop();
    cnt++;
  }
  cout << sum_a - sum_b << endl;
}