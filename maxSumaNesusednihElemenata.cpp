#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, x;
    cin >> n;
    
    cin >> x;
    int maxZbirSa=x;
    int maxZbirBez=0;
    
    for(int i=1; i<n; i++){
        cin >> x;
        
        int noviMaxZbirBez = max(maxZbirBez, maxZbirSa);
        maxZbirSa = maxZbirBez + x;
        maxZbirBez = noviMaxZbirBez;
    }
    cout << max(maxZbirBez, maxZbirSa);
    
    return 0;
}
