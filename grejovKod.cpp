// program koji trazi k-tu kombinaciju Grejovog koda velicine 2^n

#include <iostream>
#include <vector>
#include <string>

using namespace std;

string grej(int n, int k) { // O(n)
	if (n == 0)
		return "";
	if (k < (1 << (n - 1)))
		return "0" + grej(n - 1, k);
	else
		return "1" + grej(n - 1, (1 << n) - 1 - k);
}

int main()
{
	cout << grej(4, 13);
	return 0;
}
