#include <bits/stdc++.h>
using namespace std;

int main() {
  int num[10001], cnt = 0, i = 1;

  for (;;) {
    cin >> num[cnt];
    if(num[cnt] == 0) break;
    cnt++;
  }
  for (int i = 1; i <= cnt; i++) {
    cout << "Case" << " " << i << ":" << " " << num[i-1] << endl;
  }
}