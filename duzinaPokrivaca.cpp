/* U nizu celih brojeva odrediti najbrojniji podskup elemenata koji se mogu urediti u niz uzastopnih celih brojeva.  Na primer, za niz 4,8,1,−6,9,5,−9,10,−1,3,0,1,2 treba prikazati −1,0,1,2,3,4,5.  Ako ima više takvih podskupova, prikazati prvi (onaj u kojem su brojevi najmanji) */

// resenje je u O(nlogn)

#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
#include <iterator>

using namespace std;

typedef vector<pair<double, double>> Intervali;

int ukrupniIntervale(Intervali &ulazni, Intervali &izlazni)
{
	vector<pair<double, int>> promene(2*ulazni.size());
	for(int i=0; i<ulazni.size(); i++){
		promene[2*i] = make_pair(ulazni[i].first, 1);
		promene[2*i+1] = make_pair(ulazni[i].second, -1);	
	}
	
	sort(begin(promene), end(promene));
	
	int i=0;
	int brojUlaznih = 0;
	bool zapocetIzlazni = false;
	double xPocetakIzlaznog = 0;
	
	while(i < promene.size()){
		double xTrenutno = promene[i].first;
		while(i < promene.size() && promene[i].first == xTrenutno)
			brojUlaznih += promene[i++].second;
	
		if(!zapocetIzlazni && brojUlaznih > 0){
			zapocetIzlazni = true;
			xPocetakIzlaznog = xTrenutno;
		}
		
		if(zapocetIzlazni && brojUlaznih == 0){
			izlazni.push_back(make_pair(xPocetakIzlaznog, xTrenutno));
			zapocetIzlazni = false;
		}
	}
}

int main()
{
	int n;
	cin >> n;
	
	Intervali ulazni(n);
	for(int i=0; i<n; i++){
		double x1, x2;
		cin >> x1 >> x2;
		
		ulazni[i] = make_pair(x1, x2);
	}
	
	Intervali izlazni;
	
	ukrupniIntervale(ulazni, izlazni);
	int duzina = 0;
	for(auto it : izlazni)
		duzina += it.second - it.first;
	
	cout << duzina << endl;
	cout << izlazni.size() << endl;
	
	return 0;
}
