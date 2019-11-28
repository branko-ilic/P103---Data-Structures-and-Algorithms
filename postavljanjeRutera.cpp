// na kojoj poziciji u nizu(zgradi) treba postaviti ruter tako da 
// on bude na najmanjem mogucem rastojanju(utroseno najmanje kablova)
// od svih ostalih clanova u nizu(zgrada)

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n; cin >> n;
	vector<int> stanara(n);
	
	for(int i=0; i<n; i++)
		cin >> stanara[i];
	
	long long duzinaKablova = 0;
	for(int i=0; i<n; i++)
		duzinaKablova+=stanara[i]*i;
	
	long long stanaraPre = 0;
	long long stanaraPosle=0;
	for(int i=0; i<n; i++)
		stanaraPosle+=stanara[i];
	
	int minDuzinaKablova = duzinaKablova;
	
	for(int k=1; k<n; k++){
		stanaraPre += stanara[k-1];
		stanaraPosle -= stanara[k-1];
		
		duzinaKablova += stanaraPre - stanaraPosle;
		if(duzinaKablova < minDuzinaKablova)
			minDuzinaKablova = duzinaKablova;
	}
	
	cout << minDuzinaKablova << endl;
	return 0;
}
