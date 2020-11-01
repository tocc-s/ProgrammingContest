#include <bits/stdc++.h>
using namespace std;

void insertionSort(vector<int>, int);

int main() {
  int N; cin >> N;
  vector<int> A(N);
  for(int i = 0; i < N; i++) cin >> A[i];

  insertionSort(A, N);
}

void insertionSort(vector<int> A, int N) {
  int j = 0, v = 0;
  for(int i = 1; i < N; i++) {
    v = A[i];
    j = i-1;
    while(j >= 0 && A[j] > v) {
      A[j+1] = A[j];
      j--;
    }
    A[j+1] = v;
    cout << A[i-1] << " ";
  }
}