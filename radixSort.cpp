#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int getMax(vector<int>&a, int n)
{
    int max = numeric_limits<int>::min();
    for(int i=0; i<n; i++)
        if(max < a[i])
            max = a[i];
    return max;
}

void countSort(vector<int>&a, int n, int exp)
{
    int output[n];
    int count[10] = {0};
    for(int i=0; i<n; i++)
        count[(a[i]/exp)%10]++;
    for(int i=1; i<10; i++)
        count[i] += count[i-1];
    
    for(int i=n-1; i>=0; i--){
        output[count[(a[i]/exp)%10]-1] = a[i];
        count[(a[i]/exp)%10]--;
    }
    for(int i=0; i<n; i++)
        a[i] = output[i];
}

void radixSort(vector<int>& a, int n)
{
    int m = getMax(a, n);
    for(int exp=1; m/exp > 0; exp*=10)
        countSort(a, n, exp);
}

int main()
{
    int n;
    cin >> n;
    
    vector<int> a(n);
    for(int i=0; i<n; i++)
        cin >> a[i];
    
    radixSort(a, n);
    
    for(int i=0; i<n; i++)
        cout << a[i] << " ";
    cout << endl;
    return 0;
}