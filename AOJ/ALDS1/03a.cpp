#pragma region Region
#pragma region Includes
#include <bits/stdc++.h>
using namespace std;
#pragma endregion
#pragma region Setting
#pragma GCC optimize("Ofast")
#define FAST                   \
  ios::sync_with_stdio(false); \
  cin.tie(nullptr);
#define CLS clock_t start = clock();
#define CLE              \
  clock_t end = clock(); \
  cout << end - start << " ms" << '\n';
#pragma endregion
#pragma region Defines
using LL = long long;
template <class T>
using P = pair<T, T>;
template <class T>
using VEC = vector<T>;
template <class T>
using GRAPH = vector<vector<T>>;
using PQ = priority_queue<int>;
using RPQ = priority_queue<int, vector<int>, greater<int>>;
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPE(i, n) for (int i = 0; i <= n; i++)
#define REPR(i, n) for (int i = n; i >= 0; i--)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define FORE(i, m, n) for (int i = m; i <= n; i++)
#define FORR(itr, dict) for (auto& itr : dict)
#define ALL(v) v.begin(), v.end()
#define SETPRE(n) cout << fixed << setprecision(n)
constexpr LL LLINF = LLONG_MAX;
constexpr int IINF = INT_MAX;
constexpr int MOD = 1e9 + 7;
constexpr double PI = 3.14159265358979323846;
void string_lower(string& s, int n) { s[n] = s[n] + ('a' - 'A'); }
void string_upper(string& s, int n) { s[n] = s[n] - ('a' - 'A'); }
int ctoi(char c) {
  if ('0' <= c && c <= '9') return (c - '0');
  return -1;
}
template <class T>
void CO(T value) {
  cout << value << "\n";
}
#pragma endregion
#pragma endregion Region
///////////////////////////////////////////////////////////////////////////////

int main() {
  FAST;
  stack<int> st;

  /* 正解解答例 */
  // string s;
  // while (cin >> s) {
  //   if (s == "+") {
  //     int a = st.top();
  //     st.pop();
  //     int b = st.top();
  //     st.pop();
  //     st.push(a + b);
  //   } else if (s == "-") {
  //     int a = st.top();
  //     st.pop();
  //     int b = st.top();
  //     st.pop();
  //     st.push(b - a);
  //   } else if (s == "*") {
  //     int a = st.top();
  //     st.pop();
  //     int b = st.top();
  //     st.pop();
  //     st.push(b * a);
  //   } else {
  //     st.push(stoi(s));
  //   }
  // }
  // CO(st.top());

  string s;
  getline(cin, s);
  VEC<string> c;

  int cnt = 0;
  REP(i, s.size()) {
    if (!(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == ' ')) {
      cnt++;
    }
    if (s[i] == ' ' && cnt) {
      c.emplace_back(s.substr(i - cnt, cnt));
      cnt = 0;
    }
    if (s[i] == '+' || s[i] == '-' || s[i] == '*') {
      string tmps{s[i]};
      c.emplace_back(tmps);
      cnt = 0;
    }
  }
  // REP(i, c.size()) CO(c[i]);

  REP(i, c.size()) {
    if (c[i][0] == ' ') continue;
    if (!(c[i][0] == '+' || c[i][0] == '-' ||
          c[i][0] == '*')) {  //数字なら stack に格納
      st.push(stoi(c[i]));
    }
    if (c[i][0] == '+') {
      int tmp = st.top();
      st.pop();
      tmp += st.top();
      st.pop();

      st.push(tmp);
    }
    if (c[i][0] == '-') {
      int tmp1 = st.top();
      st.pop();
      int tmp2 = st.top();
      st.pop();

      st.push(tmp2 - tmp1);
    }
    if (c[i][0] == '*') {
      int tmp = st.top();
      st.pop();
      tmp *= st.top();
      st.pop();

      st.push(tmp);
    }
  }

  CO(st.top());
}