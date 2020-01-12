/* U nizu celih brojeva odrediti najbrojniji podskup elemenata koji se mogu urediti u niz uzastopnih celih brojeva.  Na primer, za niz 4,8,1,−6,9,5,−9,10,−1,3,0,1,2 treba prikazati −1,0,1,2,3,4,5.  Ako ima više takvih podskupova, prikazati prvi (onaj u kojem su brojevi najmanji) */

// resenje je u O(nlogn)

#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
#include <iterator>

using namespace std;

int najbrojnijiPresekIntervala(vector<pair<int, int>> &intervali)
{
	int n = intervali.size();
	vector<pair<int, int>> promene(2*n);
	for(int i=0; i<n; i++){
		promene[2*i] = make_pair(intervali[i].first, 1);
		promene[2*i+1] = make_pair(intervali[i].second, -1);	
	}
	
	sort(begin(promene), end(promene));
	
	int trenutnoPrisutno = 0;
	int maxPrisutno = 0;
	int i=0;
	while(i<n){
		trenutnoPrisutno += promene[i++].second;
		
		if(trenutnoPrisutno > maxPrisutno)
			maxPrisutno = trenutnoPrisutno;
	}
	
	return maxPrisutno;
}

int main()
{
	vector<pair<int, int>> intervali = {{14,17}, {11,15}, {14,15}, {11,12}, {12,17}, {9, 11}};
	
	cout << najbrojnijiPresekIntervala(intervali) << endl;
		
	return 0;
}
