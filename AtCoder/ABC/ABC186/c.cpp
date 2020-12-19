#pragma region Template
#pragma region Includes
#include <bits/stdc++.h>
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
////////////////////////////////////////////////////////////////////////////////////////////////////

/* n 進法変換 */  // 10進数num を n 進法に変換
int deci_to_n(int num, int n) {
  int len = 0;
  VEC<char> digit_c;
  while(num >= n) {
    digit_c.emplace_back(itoc(num % n));
    num /= n;
    len++;
  }
  digit_c.emplace_back(itoc(num % n));
  len++;

  reverse(ALL(digit_c));
  string s(ALL(digit_c));
  int n_ary = stoi(s);

  return n_ary;
}

void solve() {
  int n;
  cin >> n;
  VEC<int> d10(n), d8(n);
  REPE(i, 1, n) {
    d10[i] = i;
    d8[i] = deci_to_n(i, 8);
  }

  LL cnt = 0;
  REPE(i, 1, n) {
    bool f10 = false, f8 = false;

    int tmp = d10[i];
    while(tmp > 0) {
      if(tmp % 10 == 7) {
        f10 = true;
        break;
      }
      tmp /= 10;
    }

    tmp = d8[i];
    while(tmp > 0) {
      if(tmp % 10 == 7) {
        f8 = true;
        break;
      }
      tmp /= 10;
    }

    if(!f10 && !f8) cnt++;
  }

  CO(cnt);
}

int main() {
  FAST;
  solve();
}