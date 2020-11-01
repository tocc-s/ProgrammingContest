#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int N;
  cin >> N;
  vector<string> judge = { "AC", "WA", "TLE", "RE" };
  vector<int> j_cnt = {0, 0, 0, 0};

  rep(i, N) {
    string S;
    cin >> S;
    if (judge[0] == S) j_cnt[0]++;
    else if(judge[1] == S) j_cnt[1]++;
    else if(judge[2] == S) j_cnt[2]++;
    else if(judge[3] == S) j_cnt[3]++;
  }
  rep(i, judge.size()) cout << judge[i] << " x " << j_cnt[i] << '\n';
}