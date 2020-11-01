#include <bits/stdc++.h>
using namespace std;

int main() {
  int N = 0, count = 0;
  bool flag = false;
  cin >> N;
  vector<int> A(N), ans(N);

  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  while (!flag) {    
    for (int i = 0; i < N; i++) {      
      if (A[i] % 2 == 0) {
        A[i] = A[i] / 2;
      } else {
        flag = true;
        break;
      }
    }
    count++;
  }
  cout << count-1 << endl;
}