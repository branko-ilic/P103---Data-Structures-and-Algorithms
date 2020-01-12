/* U nizu celih brojeva odrediti najbrojniji podskup elemenata koji se mogu urediti u niz uzastopnih celih brojeva.  Na primer, za niz 4,8,1,−6,9,5,−9,10,−1,3,0,1,2 treba prikazati −1,0,1,2,3,4,5.  Ako ima više takvih podskupova, prikazati prvi (onaj u kojem su brojevi najmanji) */

// resenje je u O(nlogn)

#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
#include <iterator>

using namespace std;

int najduziPodskupUzastopnih(int a[], int n)
{
	sort(a, a+n);
	n = distance(a, unique(a, next(a, n)));
	
	int duzinaTekuceSerije = 1;
	int duzinaMaxSerije = 1;
	for(int i=1; i<n; i++){
		if(a[i] == a[i-1]+1)
			duzinaTekuceSerije++;
		else
			duzinaTekuceSerije=0;
		if(duzinaTekuceSerije > duzinaMaxSerije)
			duzinaMaxSerije = duzinaTekuceSerije;
	}
	
	return duzinaMaxSerije;
}

int main()
{
	int a[] = {4,8,1,-6,9,5,-9,10,-1,3,0,1,2};
	int n = sizeof(a)/sizeof(a[0]);
	//cout << n << endl;
	cout << najduziPodskupUzastopnih(a, n) << endl;
	
	return 0;
}
