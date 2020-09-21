#include <bits/stdc++.h>
using namespace std;

int main()
{
    int A, B, C;
    int small = 0, high = 0;
    cin >> A >> B >> C;

    small = min(A, B);
    small = min(small, C);
    high = max(A, B);
    high = max(high, C);

    cout << high - small << endl;
}