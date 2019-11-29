#include <iostream>
#include <vector>

using namespace std;

int vrednostPolinoma(vector<int>& a, int n, int x)
{
	int v=0, s=1;
	for(int i=0; i<=n; i++){
		v += a[i]*s;
		s *= x;
	}
	
	return v;
}

int main()
{
	vector<int> a {3, 2, 1, 5};
	int n = a.size();
	
	cout << vrednostPolinoma(a, n, 2) << endl;
	
	
}
