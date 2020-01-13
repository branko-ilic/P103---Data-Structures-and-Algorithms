/* Rangiranje naučnika vrši se pomoću statistike koja se naziva Hiršov indeks ili kraće h-indeks. H-indeks je najveći broj h takav da naučnik ima
bar h radova sa bar h citata. Napisati program koji na osnovu broja citata svih radova naučnika određuje njegov h-indeks. */

#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
#include <iterator>

using namespace std;

int hIndeks(vector<int>& brojCitata, int n) // slozenost je O(nlogn)
{
	sort(begin(brojCitata), end(brojCitata), greater<int>());
	int indeks = 0;
	while(indeks < n && brojCitata[indeks] > indeks)
		indeks++;
	
	return indeks;
}

int main()
{
	int n;
	cin >> n;
	vector<int> brojCitata(n);
	for(int i=0; i<n; i++)
		cin >> brojCitata[i];
	
	cout << hIndeks(brojCitata, n) << endl;
	return 0;
}
