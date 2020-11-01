#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B, C, X, count = 0;
  cin >> A;
  cin >> B;
  cin >> C;
  cin >> X;

  for (int i = 0; i <= A; i++) {
    // if ((X == (500 * i))) count++;
    for (int j = 0; j <= B; j++) {
      // if ((X == (100 * j))) count++;
      // if ((X == ((100 * j) + (500 * i)))) count++;
      for (int k = 0; k <= C; k++) {
        // if ((X == (50 * k))) count++;
        // if ((X == ((50 * k) + (500 * i)))) count++;
        // if ((X == ((50 * k) + (100 * j)))) count++;
        if ((X == ((50 * k) + (500 * i) + (100 * j)))) count++;
      }
    }
  }
  cout << count << endl;
}