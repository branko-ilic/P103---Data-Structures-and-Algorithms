// maksimalni zbir svih segmenata u vremenu O(n^2)

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n; cin >> n;
	vector<int> a(n);
	for(int i=0; i<n; i++)
		cin >> a[i];
	
	int max = 0;
	for(int i=0; i<n; i++){
		int z=0;
		for(int j=i; j<n; j++){
			z+=a[j];
			if(z>max)
				max=z;
		}
	}
	
	cout << max << endl;
	return 0;
}
