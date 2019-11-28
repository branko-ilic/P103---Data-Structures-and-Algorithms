// program koji trazi broj deljivih nekim brojem k u intervalu [a,b]

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int a, b;
	cin >> a >> b;
	int k;
	cin >> k;
	
	int nl = a%k==0 ? a/k : a/k + 1;
	int nd = b/k;
	int broj = nd >= nl ? nd-nl+1 : 0;
	
	cout << broj << endl;
	
	return 0;
}
