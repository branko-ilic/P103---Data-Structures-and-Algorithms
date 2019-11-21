#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main()
{
	int n;
	cin >> n;
	
	stack<int> s;
	
	for(int i=0; i<n; i++){
		int x;
		cin >> x;
		
		if(!s.empty() && s.top() > x){
			s.pop();
		}

		if(s.empty())
			cout << "-" << " ";
		else
			cout << s.top() << " ";
		
		s.push(x);
	}
}
