#include <bits/stdc++.h>
using namespace std;

int main() {
  char alpha;
  cin >> alpha;
  if(alpha >= 'A' && alpha <= 'Z') cout << 'A' << '\n';
  else if(alpha >= 'a' && alpha <= 'z') cout << 'a' << '\n';
}