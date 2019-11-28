#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n; cin >> n;
	vector<int> a(n);
	for(int i=0; i<n; i++)
		cin >> a[i];
	
	int tezinskiZbir=0;
	int zbir=0;
	
	for(int i=0; i<n; i++){
		tezinskiZbir+= a[i]*i;
		zbir+=a[i];
	}
	
	int maksTezinskiZbir = tezinskiZbir;
	
	int brojRotacija = 0;
	for(int i=1; i<n; i++){
		tezinskiZbir = tezinskiZbir - zbir + n*a[i-1];
		
		if(tezinskiZbir > maksTezinskiZbir){
			maksTezinskiZbir = tezinskiZbir;
			brojRotacija = i;
		}
	}
	
	cout << brojRotacija << endl;
	return 0;
}
