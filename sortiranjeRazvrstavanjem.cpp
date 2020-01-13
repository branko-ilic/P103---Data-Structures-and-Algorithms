#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

struct Birac{
    string opstina;
    string sifra;
};

void sortiraj(vector<Birac>& biraci)
{
    map<string, int> brojBiraca;
    for(auto birac:biraci)
        brojBiraca[birac.opstina]++;
    
    cout << "Sortirano leksikografski:" << endl;
    for(auto it = begin(brojBiraca); it != end(brojBiraca); it++)
        cout << it->first << " " << it->second << endl;

    map<string, int> pozicije;
    int prethodnoBiraca = 0;
    
    for(auto it : brojBiraca){
        pozicije[it.first] = prethodnoBiraca;
        prethodnoBiraca += it.second;
        
    }
    
    cout << "Sortirano po opstinama:" << endl;
    for(auto it : pozicije)
        cout << it.first << " " << it.second << endl;
    
    vector<Birac> sortirano(biraci.size());
    for(auto birac : biraci){
        sortirano[pozicije[birac.opstina]] = birac;
        pozicije[birac.opstina]++;
    }
    biraci = sortirano;
}

int main()
{
    int n;
    cin >> n;
    
    vector<Birac> biraci(n);
    for(int i=0; i<n; i++)
        cin >> biraci[i].opstina >> biraci[i].sifra;
    
    sortiraj(biraci);
    return 0;
}