#include <bits/stdc++.h>
#include <tuple>
#include <string>
using namespace std;

int main() {
  int N = 0;
  cin >> N;

  vector<pair<int, int>> p(N);
  for (int i = 0; i < N; i++) {
    int a, b;
    cin >> a >> b;
    p[i] = make_pair(b, a);
  }  
  sort(p.begin(), p.end());

  for(int i = 0; i < N; i++){
    int a_ans, b_ans;
    tie(b_ans, a_ans) = p[i];
    cout << a_ans << " " << b_ans << endl;
  }
}