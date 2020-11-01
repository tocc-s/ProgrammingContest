#include <bits/stdc++.h>
using namespace std;

int main() {
  int N = 0, counter = 0;
  cin >> N;
  priority_queue<int> pq;

  for (int i = 0; i < N; i++) {    
    int num = 0;
    cin >> num;
    pq.push(num);    
  }

  int max = pq.top();
  while(!pq.empty()) {    
    if(pq.top() == max) {
      counter++;
    }
    pq.pop();
  }
  cout << max << " " << counter << endl;
}