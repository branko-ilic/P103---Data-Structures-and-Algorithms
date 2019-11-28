// program koji trazi dva nedostajuca broja u prvih n elemenata niza

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int n;
	cin >> n;
	
	int z1=0, z2 = 0;
	for(int i=0; i<n-2; i++){
		int x;
		cin >> x;
		z1+=x, z2+=x*x;
	}
	int c1 = n*(n+1)/2 - z1;
	int c2 = n*(n+1)*(2*n+1)/6 - z2;
	
	int x = (c1 + sqrt(2*c2 - c1*c1))/2;
	int y = c1 - x;
	
	cout << x << " " << y << endl;
	return 0;
}
