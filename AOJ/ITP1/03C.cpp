#include <bits/stdc++.h>
using namespace std;

int main() {
  int cnt = 0, tmp = 0;
  vector<int> x(3001), y(3001);

  for(;;) {
    cin >> x[cnt] >> y[cnt];
    if(x[cnt] > y[cnt]) {
      tmp = x[cnt];
      x[cnt] = y[cnt];
      y[cnt] = tmp;
    }
    if(x[cnt] == y[cnt] && x[cnt] == 0) break;
    cnt++;
  }
  for(int i = 0; i < cnt; i++) {
    cout << x[i] << " " << y[i] << endl;
  }
}