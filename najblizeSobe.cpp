/* Dva gosta su došla u hotel i žele da odsednu u sobama koje su što bliže jedna drugoj, da bi tokom večeri mogli da zajedno rade u jednoj od tih soba. Ako postoji više takvih soba, oni biraju da budu što dalje od recepcije,tj. u sobama sa što većim rednim brojevima, kako im buka ne bi smetala */

// resenje je u O(nlogn)

#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

pair<int, int> najblizeSobe(vector<int> &sobe, int n)
{
	sort(begin(sobe), end(sobe));
	int min = 0;
	for(int i=0; i<n-1; i++){
		if(sobe[i+1] - sobe[i] <= sobe[min+1] - sobe[min])
			min = i;
	}
	return make_pair(sobe[min], sobe[min+1]);
}

int main()
{
	int n;
	cin >> n;
	vector<int> sobe(n);
	for(int i=0; i<n; i++)
		cin >> sobe[i];
	
	pair<int, int> p = najblizeSobe(sobe, n);
	
	cout << p.first << " " << p.second << endl;
	
	return 0;
}
