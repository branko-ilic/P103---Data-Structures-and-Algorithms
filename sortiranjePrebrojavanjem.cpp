#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

void sortirajPrebrojavanjem(vector<int>& a, int n)
{
    int m = *max_element(a.begin(), a.end());
    vector<int> frekvencije(m+1, 0);
    for(int i=0; i<n; i++)
        frekvencije[a[i]]++;
    
    int k=0;
    for(int j=0; j<=m; j++)
        for(int i=0; i<frekvencije[j]; i++)
            a[k++] = j;
}

int main()
{
    int n;
    cin >> n;
    
    vector<int> a(n);
    for(int i=0; i<n; i++)
        cin >> a[i];
    
    sortirajPrebrojavanjem(a, n);
    for(int i=0; i<n; i++)
        cout << a[i] << " ";
    cout << endl;
    return 0;
}