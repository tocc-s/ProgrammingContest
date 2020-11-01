#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, index = 0;
  vector<int> ans(3000);
  char op;
  for (;;) {
    cin >> a >> op >> b;
    if (op == '+') {
      ans[index] = a + b;
    } else if (op == '-') {
      ans[index] = a - b;
    } else if (op == '*') {
      ans[index] = a * b;
    } else if (op == '/') {
      ans[index] = a / b;
    } else
      break;
    index++;
  }
  for(int i = 0; i < index; i++) {
    cout << ans[i] << endl;
  }
}