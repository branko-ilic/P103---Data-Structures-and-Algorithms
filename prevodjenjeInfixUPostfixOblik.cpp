#include <iostream>
#include <stack>

using namespace std;

int primeniOp(int op1, int op2, char c)
{
	int v;
	if(c=='+') v=op1+op2;
	if(c=='*') v=op1*op2;
	
	return v;
}

int main()
{
	string izraz;
	cin >> izraz;
	
	stack<char> op;
	
	for(char c : izraz){
		if(isdigit(c))
			cout << c;
		
		if(c=='*' || c=='+')
			op.push(c);
		
		if(c==')'){
			cout << op.top();
			op.pop();
		}
	}	
	return 0;
}
