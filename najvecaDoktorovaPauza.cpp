/* Poznata su vremena dolaska pacijenata na pregled i vreme trajanja njihovog pregleda (pretpostavlja se da se nikoja dva pacijenta ne 
preklapaju).Kolika je najveća pauza koju doktor može imati u toku tog dana, između pregle dadva svoja pacijenta? */

// resenje je u O(nlogn)

#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

int najvecaPauza(vector<int> &dosao, vector<int>& trajao, int n)
{
	sort(dosao.begin(), dosao.end());
	int maxPauza = 0;
	for(int i=0; i<n-1; i++){
		int pauza = dosao[i+1] - (trajao[i] + dosao[i]);
		if(pauza > maxPauza)
			maxPauza = pauza;
	}
	return maxPauza;
}

int main()
{
	int n;
	cin >> n;
	vector<int> dosao(n);
	vector<int> trajao(n);
	
	for(int i=0; i<n; i++)
		cin >> dosao[i];
	for(int i=0; i<n; i++)
		cin >> trajao[i];
	
	cout << najvecaPauza(dosao, trajao, n) << endl;
	
	return 0;
}
