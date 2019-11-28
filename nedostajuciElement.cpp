// program koji trazi nedostajuci broj od prvih n elemenata

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin >> n;
	
	int zbir=0;
	for(int i=0; i<n-1; i++){
		int x;
		cin >> x;
		zbir+=x;
	}
	cout << n*(n+1)/2 - zbir << endl;
	return 0;
}
