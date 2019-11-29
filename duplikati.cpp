#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void sortiraj(int n, vector<int>& a)
{
	int i=0;
	while(i<n){
		if(a[a[i]] == a[i])
			i++;
		else
			swap(a[i], a[a[i]]);
	}
}

int main()
{
	int n; cin >> n;
	vector<int> a(n);
	
	for(int i=0; i<n; i++)
		cin >> a[i];
	
	sortiraj(n, a);
	
	for(int i=0; i<n; i++){
		if(a[i]!=i){
			cout << a[i] << " je duplikat" << endl;
			cout << i << " ne postoji" << endl;
		}
	}
	
	cout << endl;
}
