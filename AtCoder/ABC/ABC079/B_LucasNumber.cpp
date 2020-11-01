#include <bits/stdc++.h>
using namespace std;

int main() {  
  int num = 0;
  cin >> num;
  vector<long long> lucas(num+1) ;

  // 再帰厳しい
  lucas[0] = 2;
  lucas[1] = 1;
  for (int i = 2; i <= num; i++) {
    lucas[i] = lucas[i-2] + lucas[i-1];
  }

  cout << lucas[num] << endl;
}