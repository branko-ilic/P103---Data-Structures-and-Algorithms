#include<iostream>
#include<vector>

using namespace std;

int prebroji(vector<int>& a, int n)
{
    int brojRastucih = 0;
    int ukupanBrojRastucih = 0;
    for(int i=0; i<n; i++){
        if(a[i] < a[i+1]){
            brojRastucih++;
            ukupanBrojRastucih+= brojRastucih;
        }else brojRastucih = 0;
    }
    return ukupanBrojRastucih;
}

int main() {
    
    vector<int> a;
    int x;
    
    do{
        cin >> x;
        a.push_back(x);
    }while(x);
    
    a.pop_back();
    int n = a.size();
    
    cout << prebroji(a, n);
    return 0;
}