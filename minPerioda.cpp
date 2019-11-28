// najmanja tacna perioda niza

#include <iostream>
#include <vector>

using namespace std;

int jePerioda(vector<int> a, int p, int n)
{
	for(int i=p; i<n; i++)
		if(a[i] != a[i%p])
			return false;
	
	return true;
}

int minPerioda(vector<int> a, int n)
{
	for(int p=1; p<=n; p*=2)
		if(jePerioda(a, p, n))
			return p;
	
	return n;
}

int main()
{
	int n; cin >> n;
	vector<int> a(n);
	
	for(int i=0; i<n; i++)
		cin >> a[i];
	
	cout << minPerioda(a, n) << endl;
	
	return 0;
}
