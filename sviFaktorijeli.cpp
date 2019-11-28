//svi faktorijeli u O(n)

#include <iostream>

using namespace std;

int main()
{
	int n; cin >> n;
	
	int faktorijel = 1;
	for(int i=1; i<=n; i++){
		faktorijel*=i;
		cout << faktorijel << " ";
	}
	return 0;
}
