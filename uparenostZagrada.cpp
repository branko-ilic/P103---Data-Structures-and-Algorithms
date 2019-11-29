#include <iostream>
#include <stack>

using namespace std;

bool uparena(char oz, char zz)
{
	return oz=='(' && zz==')' ||
			oz=='[' && zz==']' ||
			oz=='{' && zz=='}'; 
}

int main()
{
	string izraz;
	cin >> izraz;
	stack<char> zagrade;
	
	for(char c : izraz){
		if(c=='(' || c=='[' || c=='{')
			zagrade.push(c);
		else if(c==')' || c==']' || c=='}'){
			if(!zagrade.empty() && uparena(zagrade.top(), c))
				zagrade.pop();
		}
	}
	
	if(zagrade.empty())
		cout << "uparene su" << endl;
	else
		cout << "nisu uparene" << endl;
	
	return 0;
}
