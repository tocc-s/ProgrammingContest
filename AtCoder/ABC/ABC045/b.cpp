#pragma region Template
#pragma region Includes
#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
#pragma endregion Includes
#pragma region Setting
#pragma GCC optimize("Ofast")
#define FAST                   \
  ios::sync_with_stdio(false); \
  cin.tie(nullptr);
#pragma endregion Setting
#pragma region Defines
using LL = long long;
template<class T> using P = pair<T, T>;
template<class T> using VEC = vector<T>;
template<class T> using VEC2 = vector<vector<T>>;
template<class T> using PQ = priority_queue<T>;
template<class T> using PQR = priority_queue<T, vector<T>, greater<T>>;
#define REP(i, m, n) for(int i = m; i < (int)(n); i++)
#define REPE(i, m, n) for(int i = m; i <= (int)(n); i++)
#define REPR(i, m, n) for(int i = m; i >= (int)(n); i--)
#define FORR(itr, dict) for(auto &itr : dict)
#define REPBIT(n) for(int bit = 0; bit < (1 << (int)(n)); bit++)
#define ALL(v) v.begin(), v.end()
#define SETPRE(n) cout << fixed << setprecision(n)
#define en '\n'
constexpr LL LLINF = LLONG_MAX;
constexpr int IINF = INT_MAX;
constexpr int MOD = 1e9 + 7;
constexpr double PI = 3.14159265358979323846;
#pragma endregion Defines
#pragma region Functions
void string_lower(string &s, int n) {
  if(s[n] >= 65 && s[n] <= 90) s[n] = s[n] + ('a' - 'A');
}
void string_upper(string &s, int n) {
  if(s[n] >= 97 && s[n] <= 122) s[n] = s[n] - ('a' - 'A');
}
template<class T> inline void CO(T value) { cout << value << en; }
inline void CO(void) { cout << en; }
template<class T> inline void CON(T value) { cout << value; }
int ctoi(char c) {
  if('0' <= c && c <= '9') return (c - '0');
  else {
    CO("ctoi error!");
    return -1;
  }
}
char itoc(int n) { return n + '0'; }
template<class T> inline bool chmin(T &a, T b) {
  if(a > b) {
    a = b;
    return true;
  }
  return false;
}
template<class T> inline bool chmax(T &a, T b) {
  if(a < b) {
    a = b;
    return true;
  }
  return false;
}
template<class T> inline bool int_chk(T n) {
  if(ceil(n) == floor(n)) return true;
  return false;
}
#pragma endregion Functions
#pragma endregion Template
/* update 2021/02/17 */
////////////////////////////////////////////////////////////////////////////////////////////////////

void solve() {
  string sa, sb, sc;
  cin >> sa >> sb >> sc;
  int s_size = sa.size() + sb.size() + sc.size();

  int idx_a = 0, idx_b = 0, idx_c = 0;
  bool fa = true, fb = false, fc = false;
  REPE(i, 0, s_size) {
    if(fa) {
      if(idx_a > sa.size()) {
        CO("A");
        return;
      }

      if(sa[idx_a] == 'b') {
        fb = true;
        fa = false;
      } else if(sa[idx_a] == 'c') {
        fc = true;
        fa = false;
      }

      idx_a++;

    } else if(fb) {
      if(idx_b > sb.size()) {
        CO("B");
        return;
      }

      if(sb[idx_b] == 'a') {
        fa = true;
        fb = false;
      } else if(sb[idx_b] == 'c') {
        fc = true;
        fb = false;
      }

      idx_b++;

    } else {
      if(idx_c > sc.size()) {
        CO("C");
        return;
      }

      if(sc[idx_c] == 'a') {
        fa = true;
        fc = false;
      } else if(sc[idx_c] == 'b') {
        fb = true;
        fc = false;
      }

      idx_c++;
    }
    // cout << fa << " " << fb << " " << fc << en;
    // cout << idx_a << " " << idx_b << " " << idx_c << en;
  }
}

int main() {
  FAST;
  solve();
}