#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 1; i <= (int)(n); i++)

int main() {
  int N;
  unsigned int diff = 0;
  unsigned long long sum = 0;
  cin >> N;
  vector<unsigned int> A(N);
  rep(i, N) cin >> A[i];

  rep(i, N) {
    if(i > 1){
      if(A[i-1] > A[i]) {
        diff = A[i-1] - A[i];
        A[i] += diff;
        sum += diff;
        diff = 0;
      } 
    }
  }
  cout << sum << endl;
}