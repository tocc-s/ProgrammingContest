#include <bits/stdc++.h>
using namespace std;

int main()
{
	string S;
	int count = 1;
	cin >> S;

	// ここにプログラムを追記
	for (int i = 0; i < S.size(); i++)
	{
		if (S.at(i) == '+')
		{
			count++;
		}
		else if (S.at(i) == '-')
		{
			count--;
		}
	}
	cout << count << endl;
}