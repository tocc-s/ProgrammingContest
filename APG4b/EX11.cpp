#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N, A;
	string op;
	cin >> N >> A;

	// ここにプログラムを追記
	for (int i = 1; i <= N; i++)
	{
		int B = 0;
		cin >> op >> B;

		if (op == "+")
		{
			A += B;
		}
		else if (op == "-")
		{
			A -= B;
		}
		else if (op == "*")
		{
			A *= B;
		}
		else if (op == "/")
		{
			if (B == 0)
			{
				cout << "error" << endl;
				break;
			}
			A /= B;
		}
		cout << i << ":" << A << endl;
	}
}