#pragma region includes
#include <bits/stdc++.h>
using namespace std;
#pragma endregion
#pragma region defines
using LL = long long;
using PLL = pair<LL, LL>;
using OVEC = vector<int>;
using TVEC = vector<vector<int>>;
constexpr LL MOD = 1e9 + 7;
constexpr LL LINF = 1e18;
constexpr int IINF = 1e9;
constexpr double PI = 3.14159265358979323846;
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPE(i, n) for (int i = 0; i <= n; i++)
#define REPR(i, n) for (int i = n; i >= 0; i--)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define FORE(i, m, n) for (int i = m; i <= n; i++)
#define FORR(v, vec) for (auto const& v : vec)
#define ALL(v) v.begin(), v.end()
#define SETPRE(n) cout << fixed << setprecision(n)
template <class T>
void CO(T value) {
  cout << value << endl;
}
void string_lower(string& s, int n) { s[n] = s[n] + ('a' - 'A'); }
void string_upper(string& s, int n) { s[n] = s[n] - ('a' - 'A'); }
#pragma endregion

int main() {
  int n;
  cin >> n;
  priority_queue<int, vector<int>, greater<int>> q;
  q.push(0);  // A0(社長)を格納

  /* 入力した社員番号を昇順でqueueに格納 */
  REP(i, n - 1) {
    int num;
    cin >> num;
    q.push(num);
  }
  // REP(i, n) {
  //   int n = q.top();
  //   CO(n);
  //   q.pop();
  // }

  vector<int> cnt(n, 0);
  int index = 0, cmp;
  cmp = q.top();  // 社長を比較対象に取得
  q.pop();        // キューから社長を除外

  int p = 0;
  while (!(q.empty())) {
    if (cmp == q.top()) {
      cnt[index]++;
      p++;
    } else if(cmp < q.top()) {
      cnt[index]++;
      index += p;
      p = 0;
    }
    cmp = q.top();
    q.pop(); // 次の人との比較のため、先頭を除外
  }
  REP(i, n) CO(cnt[i]);
}