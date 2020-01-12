/* Dato jenpaketa čokolade i za svaki od njih je poznato kolikočokoladica sadrži. Svaki odkučenika uzima tačno jedan paket, pri čemu je ciljda svi 
učenici imaju što približniji broj čokoladica. Kolika je najmanja mogućarazlika između onog učenika koji uzme paket sa najmanje i onog koji uzme 
paket sa najviše čokoladica. */

// resenje je u O(nlogn)

#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

int pravednaPodela(vector<int> &a, int n, int k)
{
	sort(a.begin(), a.end());
	int min = numeric_limits<int>::max();
	for(int i=0; i+k-1 < n; i++){
		int razlika = a[i+k-1] - a[i];
		if(razlika < min)
			min = razlika;
	}
	
	return min;
}

int main()
{
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for(int i=0; i<n; i++)
		cin >> a[i];
	
	cout << pravednaPodela(a, n, k) << endl;
	
	return 0;
}
